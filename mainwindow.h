/*
* 创建日期：2016-08-11
* 最后修改：2016-08-12
* 作    者：syf
* 描    述：
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include "cameralink.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
	// 选择server改变时，检测server下的resource
	void OnSeverNameChanged();

	// 选择配置文件
	void OnSelCCFClicked();

	// 打开相机
	void OnOpenCameraClicked();

	// 显示采集到的图片
	void ShowImage();
	

private:
    Ui::MainWindow *ui;

	CameraLink* m_pCameraLink;
	SapBuffer*  m_pSapBuffers;
	QString m_ccfPath;

};

#endif // MAINWINDOW_H
