/*
* 创建日期：2016-08-11
* 最后修改：2016-08-12
* 作    者：syf
* 描    述：
*/
#ifndef CAMERALINK_H
#define CAMERALINK_H

#include <QObject>
#include <QStringList>
#include <QString>


#include "sapclassbasic.h"

class CameraLink : public QObject
{
	Q_OBJECT

public:
	CameraLink(QObject *parent = 0);
	~CameraLink();

	// 检测含有resource的server
	BOOL Detected();

	// 返回server名称列表
	QStringList& GetServerNameList();

	// 返回resource名称列表
	QStringList& GetResourceNameList(QString serverName);

	// 返回grabber名称列表
	QStringList& GetGrabberNameList();

	// 返回图像数据地址
	SapBuffer* GetBuffers(); 

	// 打开相机
	int OpenCamera(QString& serverName, QString& grabberName, int resourceIndex, QString& ccfPath);

	// 关闭相机
	void CloseCamera();

	// 相机回调函数
	static void AcqCallback(SapXferCallbackInfo *pInfo);


private:
	BOOL m_isServerFound;
	BOOL m_isGrabberFound;
	BOOL m_isImgPrepared;

	int m_serverCount;
	QStringList m_serverNameList;
	QStringList m_resourceNameList;
	QStringList m_grabberNameList;

	SapAcquisition* m_pAcq;
	SapAcqDevice*   m_pAcqDevice;
	SapBuffer*      m_pBuffers;
	SapTransfer*    m_pXfer;	
};

#endif // CAMERALINK_H
