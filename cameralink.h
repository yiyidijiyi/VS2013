/*
* �������ڣ�2016-08-11
* ����޸ģ�2016-08-12
* ��    �ߣ�syf
* ��    ����
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

	// ��⺬��resource��server
	BOOL Detected();

	// ����server�����б�
	QStringList& GetServerNameList();

	// ����resource�����б�
	QStringList& GetResourceNameList(QString serverName);

	// ����grabber�����б�
	QStringList& GetGrabberNameList();

	// ����ͼ�����ݵ�ַ
	SapBuffer* GetBuffers(); 

	// �����
	int OpenCamera(QString& serverName, QString& grabberName, int resourceIndex, QString& ccfPath);

	// �ر����
	void CloseCamera();

	// ����ص�����
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
