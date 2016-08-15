/*
* 创建日期：2016-08-11
* 最后修改：2016-08-12
* 作    者：syf
* 描    述：
*/
#include "cameralink.h"

/*
* 参数：
* 返回：
* 功能：构造函数
*/
CameraLink::CameraLink(QObject *parent)
	: QObject(parent),
	m_isServerFound(FALSE),
	m_isGrabberFound(FALSE),
	m_serverCount(0),
	m_pAcq(NULL),
	m_pAcqDevice(NULL),
	m_pBuffers(NULL),
	m_pXfer(NULL)
{
	Detected();
}


/*
* 参数：
* 返回：
* 功能：析构函数
*/
CameraLink::~CameraLink()
{

}


/*
* 参数：
* 返回：
* 功能：检测系统中可用的采集设备与资源
*/
BOOL CameraLink::Detected()
{
	m_serverNameList.clear();
	m_grabberNameList.clear();
	
	m_serverCount = SapManager::GetServerCount();

	if (m_serverCount > 0)
	{
		m_isServerFound = TRUE;

		for (int i = 0; i < m_serverCount; i++)
		{
			if (SapManager::GetResourceCount(i, SapManager::ResourceAcq) != 0)
			{
				char serverName[64];
				SapManager::GetServerName(i, serverName, sizeof(serverName));
				m_serverNameList.append(serverName);

				m_isServerFound = TRUE;
			}

			if (SapManager::GetResourceCount(i, SapManager::ResourceAcqDevice) != 0)
			{
				char grabberName[64];
				SapManager::GetServerName(i, grabberName, sizeof(grabberName));
				m_grabberNameList.append(grabberName);

				m_isGrabberFound = TRUE;
			}
		}
	}

	if (m_isServerFound)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


/*
* 参数：
* 返回：
* 功能：返回采集设备名称列表
*/
QStringList& CameraLink::GetServerNameList()
{
	return m_serverNameList;
}


/*
* 参数：server名称
* 返回：server包含的resource名称列表
* 功能：根据server名称检测其包含的resource名称列表
*/
QStringList& CameraLink::GetResourceNameList(QString serverName)
{
	m_resourceNameList.clear();


	int deviceCount = SapManager::GetResourceCount(serverName.toLatin1().data(), SapManager::ResourceAcq);

	for (int j = 0; j < deviceCount; j++)
	{
		char deviceName[255];
		SapManager::GetResourceName(serverName.toLatin1().data(), SapManager::ResourceAcq, j, deviceName, sizeof(deviceName));
		m_resourceNameList.append(deviceName);
	}

	return m_resourceNameList;
}



/*
* 参数：
* 返回：
* 功能：根据grabber名称列表
*/
QStringList& CameraLink::GetGrabberNameList()
{
	return m_grabberNameList;
}


/*
* 参数：
* 返回：
* 功能：返回图像数据地址
*/
SapBuffer* CameraLink::GetBuffers()
{
	return m_pBuffers;
}


/*
* 参数：serverName--选择的server名称
*       resourceIndex--选择的resource编号
*       ccfPath--资源文件路径
* 返回：0--打开相机成功
*       1--初始化Acquisition失败
*       2--初始化AcqDevice失败
*       3--相机不支持DFNC
*       4--初始化Buffer失败
*       5--初始化transfer失败
*       10--server无可用resource
* 功能：根据选择的配置，打开相机
*/
int CameraLink::OpenCamera(QString& serverName, QString& grabberName, int resourceIndex, QString& ccfPath)
{
	char acqServerName[64] = {0};
	char configFileName[256] = {0};
	strcpy_s(acqServerName, 64, serverName.toLatin1().data());
	strcpy_s(configFileName, 256, ccfPath.toLatin1().data());
	BOOL status = FALSE;
	SapLocation loc(acqServerName, resourceIndex);


	if (SapManager::GetResourceCount(acqServerName, SapManager::ResourceAcq) > 0)
	{
		m_pAcq = new SapAcquisition(loc, configFileName);
		
		if (m_pAcq && !*m_pAcq && !m_pAcq->Create())
		{
			// 初始化Acquisition失败
			return 1;
		}

		SapLocation loc2(grabberName.toLatin1().data(), resourceIndex);
		m_pAcqDevice = new SapAcqDevice(loc2, FALSE);

		if (m_pAcqDevice && !*m_pAcqDevice && !m_pAcqDevice->Create())
		{
			// 初始化AcqDevice失败
			return 2;
		}

		SapFeature feature(grabberName.toLatin1().data());
		status = feature.Create();
		char modelName[64] = {0};
		m_pAcqDevice->IsFeatureAvailable("DeviceModelName", &status);
		
		//check to see if this is a DFNC camera. If it is not, end program
		//Program checks for both current and legacy naming
		if (status)
		{
			m_pAcqDevice->GetFeatureValue("DeviceModelName", modelName, sizeof(modelName));
			if (strstr(modelName, "Genie") != 0)
			{
				// 不支持DFNC
				return 3;
			}
		}
		else
		{
			// 不支持DFNC
			return 3;
		}

		m_pBuffers = new SapBuffer(1, m_pAcq);
		if (m_pBuffers && !*m_pBuffers && !m_pBuffers->Create())
		{
			// 初始化Buffer失败
			return 4;
		}

		m_pXfer = new SapAcqToBuf(m_pAcq, m_pBuffers, AcqCallback);

		if (m_pXfer && !*m_pXfer && !m_pXfer->Create())
		{
			// 初始化transfer失败
			return 5;
		}
		
	}
	else
	{
		return 10;
	}

	return 0;
}



/*
* 参数：
* 返回：
* 功能：关闭相机，释放占用的资源
*/
void CameraLink::CloseCamera()
{
	if (m_pXfer)
	{
		m_pXfer->Destroy();
		delete m_pXfer;
		m_pXfer = NULL;
	}

	if (m_pBuffers)
	{
		m_pBuffers->Destroy();
		delete m_pBuffers;
		m_pBuffers = NULL;
	}

	if (m_pAcq)
	{
		m_pAcq->Destroy();
		delete m_pAcq;
		m_pAcq = NULL;
	}

	if (m_pAcqDevice)
	{
		m_pAcqDevice->Destroy();
		delete m_pAcqDevice;
		m_pAcqDevice = NULL;
	}
}



/*
* 参数：
* 返回：
* 功能：相机回调函数
*/
void CameraLink::AcqCallback(SapXferCallbackInfo *pInfo)
{
	
}