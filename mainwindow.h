/*
* �������ڣ�2016-08-11
* ����޸ģ�2016-08-12
* ��    �ߣ�syf
* ��    ����
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
	// ѡ��server�ı�ʱ�����server�µ�resource
	void OnSeverNameChanged();

	// ѡ�������ļ�
	void OnSelCCFClicked();

	// �����
	void OnOpenCameraClicked();

	// ��ʾ�ɼ�����ͼƬ
	void ShowImage();
	

private:
    Ui::MainWindow *ui;

	CameraLink* m_pCameraLink;
	SapBuffer*  m_pSapBuffers;
	QString m_ccfPath;

};

#endif // MAINWINDOW_H
