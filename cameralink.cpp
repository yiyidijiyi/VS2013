/*
* �������ڣ�2016-08-11
* ����޸ģ�2016-08-12
* ��    �ߣ�syf
* ��    ����
*/
#include "cameralink.h"

/*
* ������
* ���أ�
* ���ܣ����캯��
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
* ������
* ���أ�
* ���ܣ���������
*/
CameraLink::~CameraLink()
{

}


/*
* ������
* ���أ�
* ���ܣ����ϵͳ�п��õĲɼ��豸����Դ
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
* ������
* ���أ�
* ���ܣ����زɼ��豸�����б�
*/
QStringList& CameraLink::GetServerNameList()
{
	return m_serverNameList;
}


/*
* ������server����
* ���أ�server������resource�����б�
* ���ܣ�����server���Ƽ���������resource�����б�
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
* ������
* ���أ�
* ���ܣ�����grabber�����б�
*/
QStringList& CameraLink::GetGrabberNameList()
{
	return m_grabberNameList;
}


/*
* ������
* ���أ�
* ���ܣ�����ͼ�����ݵ�ַ
*/
SapBuffer* CameraLink::GetBuffers()
{
	return m_pBuffers;
}


/*
* ������serverName--ѡ���server����
*       resourceIndex--ѡ���resource���
*       ccfPath--��Դ�ļ�·��
* ���أ�0--������ɹ�
*       1--��ʼ��Acquisitionʧ��
*       2--��ʼ��AcqDeviceʧ��
*       3--�����֧��DFNC
*       4--��ʼ��Bufferʧ��
*       5--��ʼ��transferʧ��
*       10--server�޿���resource
* ���ܣ�����ѡ������ã������
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
			// ��ʼ��Acquisitionʧ��
			return 1;
		}

		SapLocation loc2(grabberName.toLatin1().data(), resourceIndex);
		m_pAcqDevice = new SapAcqDevice(loc2, FALSE);

		if (m_pAcqDevice && !*m_pAcqDevice && !m_pAcqDevice->Create())
		{
			// ��ʼ��AcqDeviceʧ��
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
				// ��֧��DFNC
				return 3;
			}
		}
		else
		{
			// ��֧��DFNC
			return 3;
		}

		m_pBuffers = new SapBuffer(1, m_pAcq);
		if (m_pBuffers && !*m_pBuffers && !m_pBuffers->Create())
		{
			// ��ʼ��Bufferʧ��
			return 4;
		}

		m_pXfer = new SapAcqToBuf(m_pAcq, m_pBuffers, AcqCallback);

		if (m_pXfer && !*m_pXfer && !m_pXfer->Create())
		{
			// ��ʼ��transferʧ��
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
* ������
* ���أ�
* ���ܣ��ر�������ͷ�ռ�õ���Դ
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
* ������
* ���أ�
* ���ܣ�����ص�����
*/
void CameraLink::AcqCallback(SapXferCallbackInfo *pInfo)
{
	
}