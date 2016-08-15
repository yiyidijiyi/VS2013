/*
* �������ڣ�2016-08-11
* ����޸ģ�2016-08-12
* ��    �ߣ�syf
* ��    ����
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"


/*
* ������
* ���أ�
* ���ܣ����캯��
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
	m_pCameraLink(NULL),
	m_pSapBuffers(NULL)
{
    ui->setupUi(this);

	// ��ʼ�����ļ�·��Ϊ��
	m_ccfPath = "";

	// ����豸
	m_pCameraLink = new CameraLink();
	//QStringList& severNameList = m_pCameraLink->GetServerNameList();
	//QStringList& grabberNameList = m_pCameraLink->GetGrabberNameList();

	//for (int i = 0; i < severNameList.count(); i++)
	//{
	//	ui->textEdit1->append(severNameList[i]);
	//}

	ui->comboBox_selServer->addItems(m_pCameraLink->GetServerNameList());
	ui->comboBox_selDevice->addItems(m_pCameraLink->GetGrabberNameList());
	OnSeverNameChanged();


	// ������Ϣ���
	connect(ui->comboBox_selServer, &QComboBox::currentTextChanged, this, &MainWindow::OnSeverNameChanged);
	connect(ui->pushButton_selCCF, &QPushButton::clicked, this, &MainWindow::OnSelCCFClicked);
	connect(ui->pushButton_openCamera, &QPushButton::clicked, this, &MainWindow::OnOpenCameraClicked);
}



/*
* ������
* ���أ�
* ���ܣ���������
*/
MainWindow::~MainWindow()
{
	if (m_pCameraLink)
	{
		delete m_pCameraLink;
	}

    delete ui;
}


/*
* ������
* ���أ�
* ���ܣ��ۺ���������ѡ���server���г���server�µ�resource
*/
void MainWindow::OnSeverNameChanged()
{
	QString serverName = ui->comboBox_selServer->itemText(ui->comboBox_selServer->currentIndex());
	QStringList& resouceNameList = m_pCameraLink->GetResourceNameList(serverName);
	ui->comboBox_selResource->addItems(resouceNameList);
}


/*
* ������
* ���أ�
* ���ܣ��ۺ�����ѡ����������ļ�
*/
void MainWindow::OnSelCCFClicked()
{
	// ѡ����������ļ�
	m_ccfPath = QFileDialog::getOpenFileName(this,
		QStringLiteral("ѡ�������ļ�"), ".", "Config Files (*.ccf)");

	// ��ʾ��������ļ�
	int index = m_ccfPath.lastIndexOf("/");
	int count = m_ccfPath.count();
	ui->lineEdit_ccfPath->setText(m_ccfPath.right(count - index - 1));
}


/*
* ������
* ���أ�
* ���ܣ��ۺ�����ѡ������
*/
void MainWindow::OnOpenCameraClicked()
{
	QString serverName = ui->comboBox_selServer->itemText(ui->comboBox_selServer->currentIndex());
	QString grabberName = ui->comboBox_selDevice->itemText(ui->comboBox_selDevice->currentIndex());
	int resourceIndex = ui->comboBox_selResource->currentIndex();
	m_pCameraLink->OpenCamera(serverName, grabberName, resourceIndex, m_ccfPath);
	m_pCameraLink->CloseCamera();
}


/*
* ������
* ���أ�
* ���ܣ��ۺ�������ʾ�ɼ�����ͼƬ
*/
void MainWindow::ShowImage()
{
	uchar* pData;
	int w = 0;
	int h = 0;

	m_pSapBuffers = m_pCameraLink->GetBuffers();

	m_pSapBuffers->GetAddress(0, (void**)&pData);
	w = m_pSapBuffers->GetWidth();
	h = m_pSapBuffers->GetHeight();

	QImage img((const uchar*)pData, w, h, QImage::Format_Mono);
	ui->label_imgShow->setPixmap(QPixmap::fromImage(img));
	ui->label_imgShow->resize(w, h);
	ui->scrollArea_imgShow->setWidget(ui->label_imgShow);
}