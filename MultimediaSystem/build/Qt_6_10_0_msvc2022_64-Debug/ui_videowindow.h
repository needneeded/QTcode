/********************************************************************************
** Form generated from reading UI file 'videowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWINDOW_H
#define UI_VIDEOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_pre;
    QPushButton *btn_mode;
    QPushButton *btn_next;
    QPushButton *btn_exit;
    QTabWidget *tabWidget;
    QWidget *local;
    QListWidget *localList;
    QWidget *online;
    QListWidget *onlineList;
    QPushButton *btn_loadFile;
    QSlider *voiceSlider;
    QPushButton *btn_fullScreen;
    QComboBox *playbackSpeed;
    QLabel *lb_voiceMin;
    QLabel *lb_voiceMax;

    void setupUi(QMainWindow *VideoWindow)
    {
        if (VideoWindow->objectName().isEmpty())
            VideoWindow->setObjectName("VideoWindow");
        VideoWindow->resize(800, 600);
        VideoWindow->setStyleSheet(QString::fromUtf8("background-color:white"));
        centralwidget = new QWidget(VideoWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("#btn_mode[mode='pause']{\n"
"	border-image: url(:/resource/video/play.png);\n"
"}\n"
"#btn_mode[mode='play']{\n"
"	border-image: url(:/resource/video/pause.png);\n"
"}\n"
"#playbackSpeed {\n"
"        padding-right: 5px; /* \345\217\257\351\200\211\357\274\232\351\201\277\345\205\215\346\226\207\345\255\227\350\264\264\350\276\271 */\n"
"        border: none;\n"
"        background-color: transparent;\n"
"    }\n"
"\n"
"#playbackSpeed :down-arrow {\n"
"        image: none; /* \351\232\220\350\227\217\351\273\230\350\256\244\347\256\255\345\244\264 */\n"
"    }\n"
"\n"
"#playbackSpeed :drop-down {\n"
"        border: none;\n"
"        background: transparent;\n"
"    }\n"
"#playbackSpeed {\n"
"    border: 2px solid rgb(0, 0, 0); /* \350\276\271\346\241\206\345\256\275\345\272\246\343\200\201\347\261\273\345\236\213\343\200\201\351\242\234\350\211\262 */\n"
"    padding: 2px;              /* \345\217\257\351\200\211\357\274\232\345\206\205\350\276\271\350\267\235\357\274\214\350\256\251\345\206\205\345\256\271\344"
                        "\270\215\350\264\264\350\276\271 */\n"
"    border-radius: 4px;        /* \345\217\257\351\200\211\357\274\232\345\234\206\350\247\222\350\276\271\346\241\206 */\n"
"}"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(220, 0, 571, 521));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btn_pre = new QPushButton(centralwidget);
        btn_pre->setObjectName("btn_pre");
        btn_pre->setGeometry(QRect(400, 540, 50, 50));
        btn_pre->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/video/pre.png);"));
        btn_mode = new QPushButton(centralwidget);
        btn_mode->setObjectName("btn_mode");
        btn_mode->setGeometry(QRect(470, 540, 50, 50));
        btn_mode->setStyleSheet(QString::fromUtf8(""));
        btn_next = new QPushButton(centralwidget);
        btn_next->setObjectName("btn_next");
        btn_next->setGeometry(QRect(550, 540, 50, 50));
        btn_next->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/video/next.png);"));
        btn_exit = new QPushButton(centralwidget);
        btn_exit->setObjectName("btn_exit");
        btn_exit->setGeometry(QRect(640, 545, 40, 40));
        btn_exit->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/back.png);"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 220, 520));
        tabWidget->setToolTipDuration(0);
        local = new QWidget();
        local->setObjectName("local");
        localList = new QListWidget(local);
        localList->setObjectName("localList");
        localList->setGeometry(QRect(0, 0, 220, 490));
        localList->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        tabWidget->addTab(local, QString());
        online = new QWidget();
        online->setObjectName("online");
        onlineList = new QListWidget(online);
        onlineList->setObjectName("onlineList");
        onlineList->setGeometry(QRect(0, 0, 220, 490));
        onlineList->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        tabWidget->addTab(online, QString());
        btn_loadFile = new QPushButton(centralwidget);
        btn_loadFile->setObjectName("btn_loadFile");
        btn_loadFile->setGeometry(QRect(240, 550, 30, 30));
        btn_loadFile->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/video/load.png);"));
        voiceSlider = new QSlider(centralwidget);
        voiceSlider->setObjectName("voiceSlider");
        voiceSlider->setGeometry(QRect(40, 560, 130, 10));
        voiceSlider->setMaximum(100);
        voiceSlider->setValue(50);
        voiceSlider->setOrientation(Qt::Horizontal);
        btn_fullScreen = new QPushButton(centralwidget);
        btn_fullScreen->setObjectName("btn_fullScreen");
        btn_fullScreen->setGeometry(QRect(720, 545, 50, 40));
        btn_fullScreen->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/video/full.png);"));
        playbackSpeed = new QComboBox(centralwidget);
        playbackSpeed->addItem(QString());
        playbackSpeed->addItem(QString());
        playbackSpeed->addItem(QString());
        playbackSpeed->addItem(QString());
        playbackSpeed->setObjectName("playbackSpeed");
        playbackSpeed->setGeometry(QRect(310, 550, 60, 30));
        lb_voiceMin = new QLabel(centralwidget);
        lb_voiceMin->setObjectName("lb_voiceMin");
        lb_voiceMin->setGeometry(QRect(10, 555, 20, 20));
        lb_voiceMin->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/video/voiceMin.png);"));
        lb_voiceMax = new QLabel(centralwidget);
        lb_voiceMax->setObjectName("lb_voiceMax");
        lb_voiceMax->setGeometry(QRect(180, 555, 20, 20));
        lb_voiceMax->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/video/voiceMax.png);"));
        VideoWindow->setCentralWidget(centralwidget);

        retranslateUi(VideoWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(VideoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *VideoWindow)
    {
        VideoWindow->setWindowTitle(QCoreApplication::translate("VideoWindow", "\350\275\246\350\275\275\345\244\232\345\252\222\344\275\223-\350\247\206\351\242\221", nullptr));
        btn_pre->setText(QString());
        btn_mode->setText(QString());
        btn_next->setText(QString());
        btn_exit->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(local), QCoreApplication::translate("VideoWindow", "\346\234\254\345\234\260\345\210\227\350\241\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(online), QCoreApplication::translate("VideoWindow", "\345\234\250\347\272\277\345\210\227\350\241\250", nullptr));
        btn_loadFile->setText(QString());
        btn_fullScreen->setText(QString());
        playbackSpeed->setItemText(0, QCoreApplication::translate("VideoWindow", "0.5", nullptr));
        playbackSpeed->setItemText(1, QCoreApplication::translate("VideoWindow", "1.0", nullptr));
        playbackSpeed->setItemText(2, QCoreApplication::translate("VideoWindow", "1.5", nullptr));
        playbackSpeed->setItemText(3, QCoreApplication::translate("VideoWindow", "2.0", nullptr));

        lb_voiceMin->setText(QString());
        lb_voiceMax->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VideoWindow: public Ui_VideoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWINDOW_H
