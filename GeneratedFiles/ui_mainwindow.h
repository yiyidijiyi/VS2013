/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit1;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_ccfPath;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QPushButton *pushButton_selCCF;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_selServer;
    QComboBox *comboBox_selServer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QComboBox *comboBox_selResource;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QComboBox *comboBox_selDevice;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_openCamera;
    QPushButton *pushButton_closeCamera;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_continuousAcq;
    QPushButton *pushButton_singleAcq;
    QScrollArea *scrollArea_imgShow;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QLabel *label_imgShow;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1228, 912);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit1 = new QTextEdit(centralWidget);
        textEdit1->setObjectName(QStringLiteral("textEdit1"));
        textEdit1->setGeometry(QRect(860, 320, 251, 111));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(860, 10, 361, 181));
        lineEdit_ccfPath = new QLineEdit(groupBox);
        lineEdit_ccfPath->setObjectName(QStringLiteral("lineEdit_ccfPath"));
        lineEdit_ccfPath->setEnabled(false);
        lineEdit_ccfPath->setGeometry(QRect(20, 140, 281, 20));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 110, 132, 25));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        pushButton_selCCF = new QPushButton(widget);
        pushButton_selCCF->setObjectName(QStringLiteral("pushButton_selCCF"));
        pushButton_selCCF->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(pushButton_selCCF);

        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(20, 20, 328, 80));
        verticalLayout_3 = new QVBoxLayout(widget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(16, 14, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_selServer = new QLabel(widget1);
        label_selServer->setObjectName(QStringLiteral("label_selServer"));

        horizontalLayout->addWidget(label_selServer);

        comboBox_selServer = new QComboBox(widget1);
        comboBox_selServer->setObjectName(QStringLiteral("comboBox_selServer"));
        comboBox_selServer->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(comboBox_selServer);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        comboBox_selResource = new QComboBox(widget1);
        comboBox_selResource->setObjectName(QStringLiteral("comboBox_selResource"));
        comboBox_selResource->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(comboBox_selResource);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(20, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        comboBox_selDevice = new QComboBox(widget1);
        comboBox_selDevice->setObjectName(QStringLiteral("comboBox_selDevice"));
        comboBox_selDevice->setMinimumSize(QSize(200, 0));

        horizontalLayout_4->addWidget(comboBox_selDevice);


        verticalLayout_3->addLayout(horizontalLayout_4);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(860, 210, 180, 86));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_openCamera = new QPushButton(groupBox_2);
        pushButton_openCamera->setObjectName(QStringLiteral("pushButton_openCamera"));

        verticalLayout->addWidget(pushButton_openCamera);

        pushButton_closeCamera = new QPushButton(groupBox_2);
        pushButton_closeCamera->setObjectName(QStringLiteral("pushButton_closeCamera"));

        verticalLayout->addWidget(pushButton_closeCamera);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_continuousAcq = new QPushButton(groupBox_2);
        pushButton_continuousAcq->setObjectName(QStringLiteral("pushButton_continuousAcq"));

        verticalLayout_2->addWidget(pushButton_continuousAcq);

        pushButton_singleAcq = new QPushButton(groupBox_2);
        pushButton_singleAcq->setObjectName(QStringLiteral("pushButton_singleAcq"));

        verticalLayout_2->addWidget(pushButton_singleAcq);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        pushButton_singleAcq->raise();
        pushButton_singleAcq->raise();
        pushButton_continuousAcq->raise();
        scrollArea_imgShow = new QScrollArea(centralWidget);
        scrollArea_imgShow->setObjectName(QStringLiteral("scrollArea_imgShow"));
        scrollArea_imgShow->setGeometry(QRect(20, 20, 820, 820));
        scrollArea_imgShow->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 818, 818));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_imgShow = new QLabel(scrollAreaWidgetContents);
        label_imgShow->setObjectName(QStringLiteral("label_imgShow"));

        gridLayout_2->addWidget(label_imgShow, 0, 0, 1, 1);

        scrollArea_imgShow->setWidget(scrollAreaWidgetContents);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1228, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\233\270\346\234\272\351\205\215\347\275\256", 0));
        lineEdit_ccfPath->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\351\205\215\347\275\256\346\226\207\344\273\266\357\274\232", 0));
        pushButton_selCCF->setText(QApplication::translate("MainWindow", "\357\274\216\357\274\216\357\274\216", 0));
        label_selServer->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\351\207\207\351\233\206\345\215\241\347\261\273\345\236\213\357\274\232", 0));
        label->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\347\233\270\346\234\272\347\261\273\345\236\213\357\274\232", 0));
        label_3->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\351\207\207\351\233\206\350\256\276\345\244\207\357\274\232", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\347\233\270\346\234\272\346\223\215\344\275\234", 0));
        pushButton_openCamera->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\347\233\270\346\234\272", 0));
        pushButton_closeCamera->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\347\233\270\346\234\272", 0));
        pushButton_continuousAcq->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255\351\207\207\351\233\206", 0));
        pushButton_singleAcq->setText(QApplication::translate("MainWindow", "\345\215\225\346\254\241\351\207\207\351\233\206", 0));
        label_imgShow->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
