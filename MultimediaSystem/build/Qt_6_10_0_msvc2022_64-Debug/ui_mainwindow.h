/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #F0F8FF, stop:1 #87CEEB)"));
        btn_weather = new QPushButton(centralwidget);
        btn_weather->setObjectName("btn_weather");
        btn_weather->setGeometry(QRect(100, 100, 150, 150));
        btn_weather->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/weather.png);\n"
"background:none;"));
        btn_location = new QPushButton(centralwidget);
        btn_location->setObjectName("btn_location");
        btn_location->setGeometry(QRect(100, 350, 150, 150));
        btn_location->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/navigation.png);\n"
"background:none;"));
        btn_music = new QPushButton(centralwidget);
        btn_music->setObjectName("btn_music");
        btn_music->setGeometry(QRect(333, 360, 130, 130));
        btn_music->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/music.png);\n"
"background:none;"));
        btn_video = new QPushButton(centralwidget);
        btn_video->setObjectName("btn_video");
        btn_video->setGeometry(QRect(566, 350, 140, 140));
        btn_video->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/video.png);\n"
"background:none;"));
        label_time = new QLabel(centralwidget);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(333, 100, 383, 150));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(22);
        font.setBold(true);
        label_time->setFont(font);
        label_time->setStyleSheet(QString::fromUtf8("background:none;\n"
"font-family:\345\276\256\350\275\257\351\233\205\351\273\221\n"
"\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 250, 130, 30));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background:none;"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 510, 130, 30));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("background:none;"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(330, 510, 130, 30));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background:none;"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(570, 510, 130, 30));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("background:none;"));
        label_4->setAlignment(Qt::AlignCenter);
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
        label->setText(QCoreApplication::translate("MainWindow", "\345\244\251\346\260\224", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\234\260\345\233\276", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\351\237\263\344\271\220", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
