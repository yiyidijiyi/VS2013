/*
* 创建日期：2016-08-11
* 最后修改：2016-08-12
* 作    者：syf
* 描    述：
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"


/*
* 参数：
* 返回：
* 功能：构造函数
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
	m_pCameraLink(NULL),
	m_pSapBuffers(NULL)
{
    ui->setupUi(this);

	// 初始配置文件路径为空
	m_ccfPath = "";

	// 检测设备
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


	// 连接消息与槽
	connect(ui->comboBox_selServer, &QComboBox::currentTextChanged, this, &MainWindow::OnSeverNameChanged);
	connect(ui->pushButton_selCCF, &QPushButton::clicked, this, &MainWindow::OnSelCCFClicked);
	connect(ui->pushButton_openCamera, &QPushButton::clicked, this, &MainWindow::OnOpenCameraClicked);
}



/*
* 参数：
* 返回：
* 功能：析构函数
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
* 参数：
* 返回：
* 功能：槽函数，根据选择的server，列出该server下的resource
*/
void MainWindow::OnSeverNameChanged()
{
	QString serverName = ui->comboBox_selServer->itemText(ui->comboBox_selServer->currentIndex());
	QStringList& resouceNameList = m_pCameraLink->GetResourceNameList(serverName);
	ui->comboBox_selResource->addItems(resouceNameList);
}


/*
* 参数：
* 返回：
* 功能：槽函数，选择相机配置文件
*/
void MainWindow::OnSelCCFClicked()
{
	// 选择相机配置文件
	m_ccfPath = QFileDialog::getOpenFileName(this,
		QStringLiteral("选择配置文件"), ".", "Config Files (*.ccf)");

	// 显示相机配置文件
	int index = m_ccfPath.lastIndexOf("/");
	int count = m_ccfPath.count();
	ui->lineEdit_ccfPath->setText(m_ccfPath.right(count - index - 1));
}


/*
* 参数：
* 返回：
* 功能：槽函数，选择打开相机
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
* 参数：
* 返回：
* 功能：槽函数，显示采集到的图片
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