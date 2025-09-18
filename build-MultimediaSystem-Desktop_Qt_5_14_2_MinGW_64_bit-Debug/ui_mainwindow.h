/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_weather;
    QPushButton *btn_location;
    QPushButton *btn_music;
    QPushButton *btn_video;
    QLabel *label_time;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #F0F8FF, stop:1 #87CEEB)\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        btn_weather = new QPushButton(centralwidget);
        btn_weather->setObjectName(QString::fromUtf8("btn_weather"));
        btn_weather->setGeometry(QRect(100, 100, 150, 150));
        btn_weather->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/weather.png);\n"
"background:none;"));
        btn_location = new QPushButton(centralwidget);
        btn_location->setObjectName(QString::fromUtf8("btn_location"));
        btn_location->setGeometry(QRect(100, 350, 150, 150));
        btn_location->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/navigation.png);\n"
"background:none;"));
        btn_music = new QPushButton(centralwidget);
        btn_music->setObjectName(QString::fromUtf8("btn_music"));
        btn_music->setGeometry(QRect(333, 350, 150, 150));
        btn_music->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/music.png);\n"
"background:none;"));
        btn_video = new QPushButton(centralwidget);
        btn_video->setObjectName(QString::fromUtf8("btn_video"));
        btn_video->setGeometry(QRect(566, 350, 150, 150));
        btn_video->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/video.png);\n"
"background:none;"));
        label_time = new QLabel(centralwidget);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(333, 100, 383, 150));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        label_time->setFont(font);
        label_time->setStyleSheet(QString::fromUtf8("background:none;\n"
"font-family:\345\276\256\350\275\257\351\233\205\351\273\221\n"
"\n"
""));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\275\246\350\275\275\345\244\232\345\252\222\344\275\223", nullptr));
        btn_weather->setText(QString());
        btn_location->setText(QString());
        btn_music->setText(QString());
        btn_video->setText(QString());
        label_time->setText(QCoreApplication::translate("MainWindow", "2025-6-24 \345\221\250\344\272\214\n"
"16:50:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
