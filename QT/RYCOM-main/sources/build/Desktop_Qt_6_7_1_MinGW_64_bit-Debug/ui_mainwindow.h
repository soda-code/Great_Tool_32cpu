/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "mycombobox.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEditTime;
    QLabel *labelMS;
    QCheckBox *checkBoxPeriodicSend;
    QGroupBox *groupBoxComSet;
    QPushButton *pushButtonOpen;
    QLabel *labelBaud;
    QLabel *labelStop;
    QComboBox *comboBoxCheck;
    QLabel *labelData;
    QComboBox *comboBoxStop;
    myComboBox *comboBoxNo;
    QComboBox *comboBoxData;
    QLabel *labelCheck;
    QComboBox *comboBoxComBaud;
    QGroupBox *groupBoxSendSet;
    QPushButton *pushButtonClearSend;
    QPushButton *pushButtonRdFile;
    QCheckBox *checkBoxSendHex;
    QCheckBox *checkBoxAddNewShift;
    QGroupBox *groupBoxRevSet;
    QCheckBox *checkBoxRevHex;
    QCheckBox *checkBoxReVTime;
    QPushButton *pushButtonClearRev;
    QPushButton *pushButtonStopRev;
    QPushButton *pushButtonSaveRev;
    QGroupBox *groupBoxSend;
    QPlainTextEdit *TextSend;
    QPushButton *pushButtonSend;
    QGroupBox *groupBoxRev;
    QPlainTextEdit *TextRev;
    QRadioButton *radioButton;
    QGroupBox *groupBoxMutiSend;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditMuti8;
    QCheckBox *checkBoxMuti_4;
    QLineEdit *lineEditMuti2;
    QPushButton *pushButtonMuti1;
    QLineEdit *lineEditMuti10;
    QCheckBox *checkBoxMuti_7;
    QCheckBox *checkBoxMuti_8;
    QPushButton *pushButtonMuti4;
    QCheckBox *checkBoxMuti_6;
    QCheckBox *checkBoxMuti_2;
    QLineEdit *lineEditMuti9;
    QLineEdit *lineEditMuti3;
    QPushButton *pushButtonMuti9;
    QCheckBox *checkBoxMuti_9;
    QLineEdit *lineEditMuti5;
    QPushButton *pushButtonMuti2;
    QLineEdit *lineEditMuti1;
    QPushButton *pushButtonMuti6;
    QCheckBox *checkBoxMuti_1;
    QPushButton *pushButtonMuti5;
    QLineEdit *lineEditMuti6;
    QPushButton *pushButtonMuti7;
    QCheckBox *checkBoxMuti_5;
    QLineEdit *lineEditMuti4;
    QPushButton *pushButtonMuti3;
    QCheckBox *checkBoxMuti_3;
    QPushButton *pushButtonMuti10;
    QPushButton *pushButtonMuti8;
    QCheckBox *checkBoxMuti_10;
    QLineEdit *lineEditMuti7;
    QGroupBox *groupBox_2;
    QPushButton *pushButtonMutiReset;
    QCheckBox *checkBoxPeriodicMutiSend;
    QGroupBox *groupBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1228, 624);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setDockNestingEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        lineEditTime = new QLineEdit(centralWidget);
        lineEditTime->setObjectName("lineEditTime");
        lineEditTime->setGeometry(QRect(660, 370, 31, 16));
        labelMS = new QLabel(centralWidget);
        labelMS->setObjectName("labelMS");
        labelMS->setGeometry(QRect(700, 370, 16, 16));
        checkBoxPeriodicSend = new QCheckBox(centralWidget);
        checkBoxPeriodicSend->setObjectName("checkBoxPeriodicSend");
        checkBoxPeriodicSend->setGeometry(QRect(580, 370, 81, 16));
        checkBoxPeriodicSend->setCheckable(true);
        groupBoxComSet = new QGroupBox(centralWidget);
        groupBoxComSet->setObjectName("groupBoxComSet");
        groupBoxComSet->setGeometry(QRect(0, 0, 161, 191));
        pushButtonOpen = new QPushButton(groupBoxComSet);
        pushButtonOpen->setObjectName("pushButtonOpen");
        pushButtonOpen->setGeometry(QRect(80, 160, 71, 23));
        labelBaud = new QLabel(groupBoxComSet);
        labelBaud->setObjectName("labelBaud");
        labelBaud->setGeometry(QRect(10, 45, 51, 19));
        labelStop = new QLabel(groupBoxComSet);
        labelStop->setObjectName("labelStop");
        labelStop->setGeometry(QRect(10, 95, 51, 19));
        comboBoxCheck = new QComboBox(groupBoxComSet);
        comboBoxCheck->addItem(QString());
        comboBoxCheck->addItem(QString());
        comboBoxCheck->addItem(QString());
        comboBoxCheck->addItem(QString());
        comboBoxCheck->addItem(QString());
        comboBoxCheck->setObjectName("comboBoxCheck");
        comboBoxCheck->setGeometry(QRect(80, 125, 69, 20));
        labelData = new QLabel(groupBoxComSet);
        labelData->setObjectName("labelData");
        labelData->setGeometry(QRect(10, 70, 51, 19));
        comboBoxStop = new QComboBox(groupBoxComSet);
        comboBoxStop->addItem(QString());
        comboBoxStop->addItem(QString());
        comboBoxStop->addItem(QString());
        comboBoxStop->setObjectName("comboBoxStop");
        comboBoxStop->setGeometry(QRect(80, 99, 69, 20));
        comboBoxNo = new myComboBox(groupBoxComSet);
        comboBoxNo->setObjectName("comboBoxNo");
        comboBoxNo->setGeometry(QRect(8, 21, 141, 20));
        comboBoxData = new QComboBox(groupBoxComSet);
        comboBoxData->addItem(QString());
        comboBoxData->addItem(QString());
        comboBoxData->addItem(QString());
        comboBoxData->addItem(QString());
        comboBoxData->setObjectName("comboBoxData");
        comboBoxData->setGeometry(QRect(80, 73, 69, 20));
        labelCheck = new QLabel(groupBoxComSet);
        labelCheck->setObjectName("labelCheck");
        labelCheck->setGeometry(QRect(10, 120, 51, 19));
        comboBoxComBaud = new QComboBox(groupBoxComSet);
        comboBoxComBaud->addItem(QString());
        comboBoxComBaud->addItem(QString());
        comboBoxComBaud->addItem(QString());
        comboBoxComBaud->addItem(QString());
        comboBoxComBaud->addItem(QString());
        comboBoxComBaud->addItem(QString());
        comboBoxComBaud->addItem(QString());
        comboBoxComBaud->addItem(QString());
        comboBoxComBaud->addItem(QString());
        comboBoxComBaud->addItem(QString());
        comboBoxComBaud->addItem(QString());
        comboBoxComBaud->addItem(QString());
        comboBoxComBaud->setObjectName("comboBoxComBaud");
        comboBoxComBaud->setEnabled(true);
        comboBoxComBaud->setGeometry(QRect(80, 47, 69, 20));
        groupBoxSendSet = new QGroupBox(centralWidget);
        groupBoxSendSet->setObjectName("groupBoxSendSet");
        groupBoxSendSet->setGeometry(QRect(10, 388, 161, 141));
        pushButtonClearSend = new QPushButton(groupBoxSendSet);
        pushButtonClearSend->setObjectName("pushButtonClearSend");
        pushButtonClearSend->setGeometry(QRect(60, 70, 95, 23));
        pushButtonRdFile = new QPushButton(groupBoxSendSet);
        pushButtonRdFile->setObjectName("pushButtonRdFile");
        pushButtonRdFile->setGeometry(QRect(60, 50, 95, 23));
        checkBoxSendHex = new QCheckBox(groupBoxSendSet);
        checkBoxSendHex->setObjectName("checkBoxSendHex");
        checkBoxSendHex->setGeometry(QRect(60, 120, 101, 16));
        checkBoxAddNewShift = new QCheckBox(groupBoxSendSet);
        checkBoxAddNewShift->setObjectName("checkBoxAddNewShift");
        checkBoxAddNewShift->setGeometry(QRect(60, 100, 95, 16));
        checkBoxAddNewShift->setCheckable(true);
        groupBoxRevSet = new QGroupBox(centralWidget);
        groupBoxRevSet->setObjectName("groupBoxRevSet");
        groupBoxRevSet->setGeometry(QRect(0, 220, 171, 131));
        checkBoxRevHex = new QCheckBox(groupBoxRevSet);
        checkBoxRevHex->setObjectName("checkBoxRevHex");
        checkBoxRevHex->setGeometry(QRect(60, 110, 101, 16));
        checkBoxRevHex->setCheckable(true);
        checkBoxRevHex->setChecked(false);
        checkBoxRevHex->setTristate(false);
        checkBoxReVTime = new QCheckBox(groupBoxRevSet);
        checkBoxReVTime->setObjectName("checkBoxReVTime");
        checkBoxReVTime->setGeometry(QRect(60, 90, 95, 16));
        pushButtonClearRev = new QPushButton(groupBoxRevSet);
        pushButtonClearRev->setObjectName("pushButtonClearRev");
        pushButtonClearRev->setGeometry(QRect(60, 60, 95, 23));
        pushButtonStopRev = new QPushButton(groupBoxRevSet);
        pushButtonStopRev->setObjectName("pushButtonStopRev");
        pushButtonStopRev->setGeometry(QRect(60, 40, 95, 23));
        pushButtonSaveRev = new QPushButton(groupBoxRevSet);
        pushButtonSaveRev->setObjectName("pushButtonSaveRev");
        pushButtonSaveRev->setGeometry(QRect(60, 20, 95, 23));
        groupBoxSend = new QGroupBox(centralWidget);
        groupBoxSend->setObjectName("groupBoxSend");
        groupBoxSend->setGeometry(QRect(180, 388, 541, 141));
        TextSend = new QPlainTextEdit(groupBoxSend);
        TextSend->setObjectName("TextSend");
        TextSend->setEnabled(true);
        TextSend->setGeometry(QRect(10, 20, 521, 111));
        pushButtonSend = new QPushButton(groupBoxSend);
        pushButtonSend->setObjectName("pushButtonSend");
        pushButtonSend->setGeometry(QRect(460, 110, 71, 23));
        pushButtonSend->setCheckable(false);
        pushButtonSend->setChecked(false);
        pushButtonSend->setAutoDefault(false);
        groupBoxRev = new QGroupBox(centralWidget);
        groupBoxRev->setObjectName("groupBoxRev");
        groupBoxRev->setGeometry(QRect(180, 0, 341, 361));
        TextRev = new QPlainTextEdit(groupBoxRev);
        TextRev->setObjectName("TextRev");
        TextRev->setGeometry(QRect(10, 20, 501, 331));
        TextRev->setReadOnly(true);
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(500, 370, 81, 16));
        groupBoxMutiSend = new QGroupBox(centralWidget);
        groupBoxMutiSend->setObjectName("groupBoxMutiSend");
        groupBoxMutiSend->setGeometry(QRect(730, -10, 191, 361));
        label_3 = new QLabel(groupBoxMutiSend);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 20, 31, 16));
        label = new QLabel(groupBoxMutiSend);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 41, 16));
        label_2 = new QLabel(groupBoxMutiSend);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 20, 61, 16));
        lineEditMuti8 = new QLineEdit(groupBoxMutiSend);
        lineEditMuti8->setObjectName("lineEditMuti8");
        lineEditMuti8->setGeometry(QRect(30, 239, 121, 20));
        checkBoxMuti_4 = new QCheckBox(groupBoxMutiSend);
        checkBoxMuti_4->setObjectName("checkBoxMuti_4");
        checkBoxMuti_4->setGeometry(QRect(9, 130, 16, 16));
        lineEditMuti2 = new QLineEdit(groupBoxMutiSend);
        lineEditMuti2->setObjectName("lineEditMuti2");
        lineEditMuti2->setGeometry(QRect(30, 72, 121, 20));
        pushButtonMuti1 = new QPushButton(groupBoxMutiSend);
        pushButtonMuti1->setObjectName("pushButtonMuti1");
        pushButtonMuti1->setGeometry(QRect(157, 42, 31, 23));
        lineEditMuti10 = new QLineEdit(groupBoxMutiSend);
        lineEditMuti10->setObjectName("lineEditMuti10");
        lineEditMuti10->setGeometry(QRect(30, 299, 121, 20));
        checkBoxMuti_7 = new QCheckBox(groupBoxMutiSend);
        checkBoxMuti_7->setObjectName("checkBoxMuti_7");
        checkBoxMuti_7->setGeometry(QRect(9, 215, 16, 16));
        checkBoxMuti_8 = new QCheckBox(groupBoxMutiSend);
        checkBoxMuti_8->setObjectName("checkBoxMuti_8");
        checkBoxMuti_8->setGeometry(QRect(9, 242, 16, 16));
        pushButtonMuti4 = new QPushButton(groupBoxMutiSend);
        pushButtonMuti4->setObjectName("pushButtonMuti4");
        pushButtonMuti4->setGeometry(QRect(158, 126, 31, 23));
        checkBoxMuti_6 = new QCheckBox(groupBoxMutiSend);
        checkBoxMuti_6->setObjectName("checkBoxMuti_6");
        checkBoxMuti_6->setGeometry(QRect(9, 187, 16, 16));
        checkBoxMuti_2 = new QCheckBox(groupBoxMutiSend);
        checkBoxMuti_2->setObjectName("checkBoxMuti_2");
        checkBoxMuti_2->setGeometry(QRect(9, 75, 16, 16));
        lineEditMuti9 = new QLineEdit(groupBoxMutiSend);
        lineEditMuti9->setObjectName("lineEditMuti9");
        lineEditMuti9->setGeometry(QRect(31, 269, 121, 20));
        lineEditMuti3 = new QLineEdit(groupBoxMutiSend);
        lineEditMuti3->setObjectName("lineEditMuti3");
        lineEditMuti3->setGeometry(QRect(30, 100, 121, 20));
        pushButtonMuti9 = new QPushButton(groupBoxMutiSend);
        pushButtonMuti9->setObjectName("pushButtonMuti9");
        pushButtonMuti9->setGeometry(QRect(158, 267, 31, 23));
        checkBoxMuti_9 = new QCheckBox(groupBoxMutiSend);
        checkBoxMuti_9->setObjectName("checkBoxMuti_9");
        checkBoxMuti_9->setGeometry(QRect(10, 272, 16, 16));
        lineEditMuti5 = new QLineEdit(groupBoxMutiSend);
        lineEditMuti5->setObjectName("lineEditMuti5");
        lineEditMuti5->setGeometry(QRect(30, 156, 121, 20));
        pushButtonMuti2 = new QPushButton(groupBoxMutiSend);
        pushButtonMuti2->setObjectName("pushButtonMuti2");
        pushButtonMuti2->setGeometry(QRect(158, 70, 31, 23));
        lineEditMuti1 = new QLineEdit(groupBoxMutiSend);
        lineEditMuti1->setObjectName("lineEditMuti1");
        lineEditMuti1->setGeometry(QRect(30, 44, 121, 20));
        pushButtonMuti6 = new QPushButton(groupBoxMutiSend);
        pushButtonMuti6->setObjectName("pushButtonMuti6");
        pushButtonMuti6->setGeometry(QRect(158, 182, 31, 23));
        checkBoxMuti_1 = new QCheckBox(groupBoxMutiSend);
        checkBoxMuti_1->setObjectName("checkBoxMuti_1");
        checkBoxMuti_1->setGeometry(QRect(9, 47, 16, 16));
        pushButtonMuti5 = new QPushButton(groupBoxMutiSend);
        pushButtonMuti5->setObjectName("pushButtonMuti5");
        pushButtonMuti5->setGeometry(QRect(158, 154, 31, 23));
        lineEditMuti6 = new QLineEdit(groupBoxMutiSend);
        lineEditMuti6->setObjectName("lineEditMuti6");
        lineEditMuti6->setGeometry(QRect(30, 184, 121, 20));
        pushButtonMuti7 = new QPushButton(groupBoxMutiSend);
        pushButtonMuti7->setObjectName("pushButtonMuti7");
        pushButtonMuti7->setGeometry(QRect(158, 210, 31, 23));
        checkBoxMuti_5 = new QCheckBox(groupBoxMutiSend);
        checkBoxMuti_5->setObjectName("checkBoxMuti_5");
        checkBoxMuti_5->setGeometry(QRect(9, 159, 16, 16));
        lineEditMuti4 = new QLineEdit(groupBoxMutiSend);
        lineEditMuti4->setObjectName("lineEditMuti4");
        lineEditMuti4->setGeometry(QRect(30, 127, 121, 20));
        pushButtonMuti3 = new QPushButton(groupBoxMutiSend);
        pushButtonMuti3->setObjectName("pushButtonMuti3");
        pushButtonMuti3->setGeometry(QRect(158, 98, 31, 23));
        checkBoxMuti_3 = new QCheckBox(groupBoxMutiSend);
        checkBoxMuti_3->setObjectName("checkBoxMuti_3");
        checkBoxMuti_3->setGeometry(QRect(9, 103, 16, 16));
        pushButtonMuti10 = new QPushButton(groupBoxMutiSend);
        pushButtonMuti10->setObjectName("pushButtonMuti10");
        pushButtonMuti10->setGeometry(QRect(158, 297, 31, 23));
        pushButtonMuti8 = new QPushButton(groupBoxMutiSend);
        pushButtonMuti8->setObjectName("pushButtonMuti8");
        pushButtonMuti8->setGeometry(QRect(158, 238, 31, 23));
        checkBoxMuti_10 = new QCheckBox(groupBoxMutiSend);
        checkBoxMuti_10->setObjectName("checkBoxMuti_10");
        checkBoxMuti_10->setGeometry(QRect(9, 302, 16, 16));
        lineEditMuti7 = new QLineEdit(groupBoxMutiSend);
        lineEditMuti7->setObjectName("lineEditMuti7");
        lineEditMuti7->setGeometry(QRect(30, 212, 121, 20));
        groupBox_2 = new QGroupBox(groupBoxMutiSend);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 330, 191, 31));
        pushButtonMutiReset = new QPushButton(groupBox_2);
        pushButtonMutiReset->setObjectName("pushButtonMutiReset");
        pushButtonMutiReset->setGeometry(QRect(10, 0, 31, 23));
        checkBoxPeriodicMutiSend = new QCheckBox(groupBox_2);
        checkBoxPeriodicMutiSend->setObjectName("checkBoxPeriodicMutiSend");
        checkBoxPeriodicMutiSend->setGeometry(QRect(50, 0, 131, 23));
        checkBoxPeriodicMutiSend->setCheckable(true);
        groupBox = new QGroupBox(groupBoxMutiSend);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 20, 191, 16));
        MainWindow->setCentralWidget(centralWidget);
        labelMS->raise();
        checkBoxPeriodicSend->raise();
        groupBoxComSet->raise();
        groupBoxSendSet->raise();
        groupBoxRevSet->raise();
        groupBoxSend->raise();
        groupBoxRev->raise();
        radioButton->raise();
        groupBoxMutiSend->raise();
        lineEditTime->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1228, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        statusBar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        comboBoxData->setCurrentIndex(3);
        comboBoxComBaud->setCurrentIndex(3);
        pushButtonSend->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "RYMCU\344\270\262\345\217\243\350\260\203\350\257\225\345\212\251\346\211\213V1.0  www.rymcu.com", nullptr));
        lineEditTime->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        labelMS->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        checkBoxPeriodicSend->setText(QCoreApplication::translate("MainWindow", "\345\221\250\346\234\237\345\217\221\351\200\201", nullptr));
        groupBoxComSet->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        pushButtonOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        labelBaud->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        labelStop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        comboBoxCheck->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        comboBoxCheck->setItemText(1, QCoreApplication::translate("MainWindow", "Even", nullptr));
        comboBoxCheck->setItemText(2, QCoreApplication::translate("MainWindow", "Odd", nullptr));
        comboBoxCheck->setItemText(3, QCoreApplication::translate("MainWindow", "Mark", nullptr));
        comboBoxCheck->setItemText(4, QCoreApplication::translate("MainWindow", "Space", nullptr));

        labelData->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        comboBoxStop->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBoxStop->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        comboBoxStop->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        comboBoxData->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBoxData->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBoxData->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBoxData->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        labelCheck->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        comboBoxComBaud->setItemText(0, QCoreApplication::translate("MainWindow", "1200", nullptr));
        comboBoxComBaud->setItemText(1, QCoreApplication::translate("MainWindow", "2400", nullptr));
        comboBoxComBaud->setItemText(2, QCoreApplication::translate("MainWindow", "4800", nullptr));
        comboBoxComBaud->setItemText(3, QCoreApplication::translate("MainWindow", "9600", nullptr));
        comboBoxComBaud->setItemText(4, QCoreApplication::translate("MainWindow", "19200", nullptr));
        comboBoxComBaud->setItemText(5, QCoreApplication::translate("MainWindow", "38400", nullptr));
        comboBoxComBaud->setItemText(6, QCoreApplication::translate("MainWindow", "57600", nullptr));
        comboBoxComBaud->setItemText(7, QCoreApplication::translate("MainWindow", "74880", nullptr));
        comboBoxComBaud->setItemText(8, QCoreApplication::translate("MainWindow", "115200", nullptr));
        comboBoxComBaud->setItemText(9, QCoreApplication::translate("MainWindow", "230400", nullptr));
        comboBoxComBaud->setItemText(10, QCoreApplication::translate("MainWindow", "460800", nullptr));
        comboBoxComBaud->setItemText(11, QCoreApplication::translate("MainWindow", "576000", nullptr));

        groupBoxSendSet->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\350\256\276\347\275\256", nullptr));
        pushButtonClearSend->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\217\221\351\200\201\345\214\272", nullptr));
        pushButtonRdFile->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\346\226\207\344\273\266", nullptr));
        checkBoxSendHex->setText(QCoreApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266", nullptr));
        checkBoxAddNewShift->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\226\260\350\241\214", nullptr));
        groupBoxRevSet->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\350\256\276\347\275\256", nullptr));
        checkBoxRevHex->setText(QCoreApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266", nullptr));
        checkBoxReVTime->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\346\227\266\351\227\264", nullptr));
        pushButtonClearRev->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", nullptr));
        pushButtonStopRev->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\346\230\276\347\244\272", nullptr));
        pushButtonSaveRev->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        groupBoxSend->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\214\272", nullptr));
        TextSend->setPlainText(QString());
        pushButtonSend->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        groupBoxRev->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\345\214\272", nullptr));
        TextRev->setPlainText(QString());
        radioButton->setText(QCoreApplication::translate("MainWindow", "\345\244\232\350\241\214\345\217\221\351\200\201", nullptr));
        groupBoxMutiSend->setTitle(QCoreApplication::translate("MainWindow", "\345\244\232\350\241\214\345\217\221\351\200\201\345\214\272", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\351\200\211\344\270\255", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245\345\255\227\347\254\246", nullptr));
        lineEditMuti8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        checkBoxMuti_4->setText(QString());
        lineEditMuti2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButtonMuti1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        lineEditMuti10->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        checkBoxMuti_7->setText(QString());
        checkBoxMuti_8->setText(QString());
        pushButtonMuti4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        checkBoxMuti_6->setText(QString());
        checkBoxMuti_2->setText(QString());
        lineEditMuti9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        lineEditMuti3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButtonMuti9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        checkBoxMuti_9->setText(QString());
        lineEditMuti5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButtonMuti2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        lineEditMuti1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButtonMuti6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        checkBoxMuti_1->setText(QString());
        pushButtonMuti5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        lineEditMuti6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButtonMuti7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        checkBoxMuti_5->setText(QString());
        lineEditMuti4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButtonMuti3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        checkBoxMuti_3->setText(QString());
        pushButtonMuti10->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        pushButtonMuti8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        checkBoxMuti_10->setText(QString());
        lineEditMuti7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        groupBox_2->setTitle(QString());
        pushButtonMutiReset->setText(QCoreApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
        checkBoxPeriodicMutiSend->setText(QCoreApplication::translate("MainWindow", "\345\244\232\350\241\214\345\276\252\347\216\257\345\217\221\351\200\201", nullptr));
        groupBox->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
