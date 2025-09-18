/********************************************************************************
** Form generated from reading UI file 'weatherwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERWINDOW_H
#define UI_WEATHERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Weather
{
public:
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_date1;
    QLabel *label_icon1;
    QLabel *label_wea1;
    QLabel *label_temperature1;
    QLabel *label_temperature2;
    QLabel *label_date2;
    QLabel *label_icon2;
    QLabel *label_wea2;
    QLabel *label_temperature3;
    QLabel *label_date3;
    QLabel *label_icon3;
    QLabel *label_wea3;
    QLabel *label_temperature4;
    QLabel *label_date4;
    QLabel *label_icon4;
    QLabel *label_wea4;
    QLabel *label_date5;
    QLabel *label_temperature5;
    QLabel *label_icon5;
    QLabel *label_wea5;
    QLabel *label_date6;
    QLabel *label_temperature6;
    QLabel *label_icon6;
    QLabel *label_wea6;
    QLabel *label_date7;
    QLabel *label_temperature7;
    QLabel *label_icon7;
    QLabel *label_wea7;
    QPushButton *btn_localName;
    QLabel *label_icon;
    QLabel *label_weatherIcon;
    QLabel *label_tem;
    QLabel *label_wea;
    QLabel *label_datetime;
    QPushButton *btn_backIcon;
    QLabel *label_backName;
    QLabel *label_temMax;
    QLabel *label_temMin;

    void setupUi(QWidget *Weather)
    {
        if (Weather->objectName().isEmpty())
            Weather->setObjectName(QString::fromUtf8("Weather"));
        Weather->resize(800, 600);
        Weather->setStyleSheet(QString::fromUtf8("background:qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 rgb(125, 199, 255), stop:1 rgb(229, 255, 255))\n"
"\n"
""));
        label_1 = new QLabel(Weather);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(12, 320, 100, 260));
        label_1->setStyleSheet(QString::fromUtf8("background:rgb(213, 255, 255);\n"
"border-top: 3px double yellow; "));
        label_2 = new QLabel(Weather);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(124, 320, 100, 260));
        label_2->setStyleSheet(QString::fromUtf8("background:rgb(231, 255, 255)"));
        label_3 = new QLabel(Weather);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(348, 320, 100, 260));
        label_3->setStyleSheet(QString::fromUtf8("background:rgb(231, 255, 255)"));
        label_4 = new QLabel(Weather);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(572, 320, 100, 260));
        label_4->setStyleSheet(QString::fromUtf8("background:rgb(231, 255, 255)"));
        label_5 = new QLabel(Weather);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(684, 320, 100, 260));
        label_5->setStyleSheet(QString::fromUtf8("background:rgb(231, 255, 255)"));
        label_6 = new QLabel(Weather);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(236, 320, 100, 260));
        label_6->setStyleSheet(QString::fromUtf8("background:rgb(231, 255, 255)"));
        label_7 = new QLabel(Weather);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(460, 320, 100, 260));
        label_7->setStyleSheet(QString::fromUtf8("background:rgb(231, 255, 255)"));
        label_date1 = new QLabel(Weather);
        label_date1->setObjectName(QString::fromUtf8("label_date1"));
        label_date1->setGeometry(QRect(12, 320, 100, 60));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_date1->setFont(font);
        label_date1->setStyleSheet(QString::fromUtf8("background:none"));
        label_date1->setAlignment(Qt::AlignCenter);
        label_icon1 = new QLabel(Weather);
        label_icon1->setObjectName(QString::fromUtf8("label_icon1"));
        label_icon1->setGeometry(QRect(12, 380, 100, 100));
        QFont font1;
        font1.setPointSize(12);
        label_icon1->setFont(font1);
        label_icon1->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-image: url(:/resource/wea_images/bingbao.png);"));
        label_icon1->setAlignment(Qt::AlignCenter);
        label_wea1 = new QLabel(Weather);
        label_wea1->setObjectName(QString::fromUtf8("label_wea1"));
        label_wea1->setGeometry(QRect(12, 480, 100, 45));
        QFont font2;
        font2.setPointSize(7);
        font2.setBold(true);
        font2.setWeight(75);
        label_wea1->setFont(font2);
        label_wea1->setStyleSheet(QString::fromUtf8("background:none"));
        label_wea1->setAlignment(Qt::AlignCenter);
        label_temperature1 = new QLabel(Weather);
        label_temperature1->setObjectName(QString::fromUtf8("label_temperature1"));
        label_temperature1->setGeometry(QRect(12, 525, 100, 45));
        QFont font3;
        font3.setPointSize(11);
        label_temperature1->setFont(font3);
        label_temperature1->setStyleSheet(QString::fromUtf8("background:none"));
        label_temperature1->setAlignment(Qt::AlignCenter);
        label_temperature2 = new QLabel(Weather);
        label_temperature2->setObjectName(QString::fromUtf8("label_temperature2"));
        label_temperature2->setGeometry(QRect(124, 525, 100, 45));
        label_temperature2->setFont(font3);
        label_temperature2->setStyleSheet(QString::fromUtf8("background:none"));
        label_temperature2->setAlignment(Qt::AlignCenter);
        label_date2 = new QLabel(Weather);
        label_date2->setObjectName(QString::fromUtf8("label_date2"));
        label_date2->setGeometry(QRect(124, 320, 100, 60));
        label_date2->setFont(font);
        label_date2->setStyleSheet(QString::fromUtf8("background:none"));
        label_date2->setAlignment(Qt::AlignCenter);
        label_icon2 = new QLabel(Weather);
        label_icon2->setObjectName(QString::fromUtf8("label_icon2"));
        label_icon2->setGeometry(QRect(124, 380, 100, 100));
        label_icon2->setFont(font1);
        label_icon2->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-image: url(:/resource/wea_images/bingbao.png);"));
        label_icon2->setAlignment(Qt::AlignCenter);
        label_wea2 = new QLabel(Weather);
        label_wea2->setObjectName(QString::fromUtf8("label_wea2"));
        label_wea2->setGeometry(QRect(124, 480, 100, 45));
        label_wea2->setFont(font2);
        label_wea2->setStyleSheet(QString::fromUtf8("background:none"));
        label_wea2->setAlignment(Qt::AlignCenter);
        label_temperature3 = new QLabel(Weather);
        label_temperature3->setObjectName(QString::fromUtf8("label_temperature3"));
        label_temperature3->setGeometry(QRect(236, 525, 100, 45));
        label_temperature3->setFont(font3);
        label_temperature3->setStyleSheet(QString::fromUtf8("background:none"));
        label_temperature3->setAlignment(Qt::AlignCenter);
        label_date3 = new QLabel(Weather);
        label_date3->setObjectName(QString::fromUtf8("label_date3"));
        label_date3->setGeometry(QRect(236, 320, 100, 60));
        label_date3->setFont(font);
        label_date3->setStyleSheet(QString::fromUtf8("background:none"));
        label_date3->setAlignment(Qt::AlignCenter);
        label_icon3 = new QLabel(Weather);
        label_icon3->setObjectName(QString::fromUtf8("label_icon3"));
        label_icon3->setGeometry(QRect(236, 380, 100, 100));
        label_icon3->setFont(font1);
        label_icon3->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-image: url(:/resource/wea_images/bingbao.png);"));
        label_icon3->setAlignment(Qt::AlignCenter);
        label_wea3 = new QLabel(Weather);
        label_wea3->setObjectName(QString::fromUtf8("label_wea3"));
        label_wea3->setGeometry(QRect(236, 480, 100, 45));
        label_wea3->setFont(font2);
        label_wea3->setStyleSheet(QString::fromUtf8("background:none"));
        label_wea3->setAlignment(Qt::AlignCenter);
        label_temperature4 = new QLabel(Weather);
        label_temperature4->setObjectName(QString::fromUtf8("label_temperature4"));
        label_temperature4->setGeometry(QRect(348, 525, 100, 45));
        label_temperature4->setFont(font3);
        label_temperature4->setStyleSheet(QString::fromUtf8("background:none"));
        label_temperature4->setAlignment(Qt::AlignCenter);
        label_date4 = new QLabel(Weather);
        label_date4->setObjectName(QString::fromUtf8("label_date4"));
        label_date4->setGeometry(QRect(348, 320, 100, 60));
        label_date4->setFont(font);
        label_date4->setStyleSheet(QString::fromUtf8("background:none"));
        label_date4->setAlignment(Qt::AlignCenter);
        label_icon4 = new QLabel(Weather);
        label_icon4->setObjectName(QString::fromUtf8("label_icon4"));
        label_icon4->setGeometry(QRect(348, 380, 100, 100));
        label_icon4->setFont(font1);
        label_icon4->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-image: url(:/resource/wea_images/bingbao.png);"));
        label_icon4->setAlignment(Qt::AlignCenter);
        label_wea4 = new QLabel(Weather);
        label_wea4->setObjectName(QString::fromUtf8("label_wea4"));
        label_wea4->setGeometry(QRect(348, 480, 100, 45));
        label_wea4->setFont(font2);
        label_wea4->setStyleSheet(QString::fromUtf8("background:none"));
        label_wea4->setAlignment(Qt::AlignCenter);
        label_date5 = new QLabel(Weather);
        label_date5->setObjectName(QString::fromUtf8("label_date5"));
        label_date5->setGeometry(QRect(460, 320, 100, 60));
        label_date5->setFont(font);
        label_date5->setStyleSheet(QString::fromUtf8("background:none"));
        label_date5->setAlignment(Qt::AlignCenter);
        label_temperature5 = new QLabel(Weather);
        label_temperature5->setObjectName(QString::fromUtf8("label_temperature5"));
        label_temperature5->setGeometry(QRect(460, 525, 100, 45));
        label_temperature5->setFont(font3);
        label_temperature5->setStyleSheet(QString::fromUtf8("background:none"));
        label_temperature5->setAlignment(Qt::AlignCenter);
        label_icon5 = new QLabel(Weather);
        label_icon5->setObjectName(QString::fromUtf8("label_icon5"));
        label_icon5->setGeometry(QRect(460, 380, 100, 100));
        label_icon5->setFont(font1);
        label_icon5->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-image: url(:/resource/wea_images/bingbao.png);"));
        label_icon5->setAlignment(Qt::AlignCenter);
        label_wea5 = new QLabel(Weather);
        label_wea5->setObjectName(QString::fromUtf8("label_wea5"));
        label_wea5->setGeometry(QRect(460, 480, 100, 45));
        label_wea5->setFont(font2);
        label_wea5->setStyleSheet(QString::fromUtf8("background:none"));
        label_wea5->setAlignment(Qt::AlignCenter);
        label_date6 = new QLabel(Weather);
        label_date6->setObjectName(QString::fromUtf8("label_date6"));
        label_date6->setGeometry(QRect(572, 320, 100, 60));
        label_date6->setFont(font);
        label_date6->setStyleSheet(QString::fromUtf8("background:none"));
        label_date6->setAlignment(Qt::AlignCenter);
        label_temperature6 = new QLabel(Weather);
        label_temperature6->setObjectName(QString::fromUtf8("label_temperature6"));
        label_temperature6->setGeometry(QRect(572, 525, 100, 45));
        label_temperature6->setFont(font3);
        label_temperature6->setStyleSheet(QString::fromUtf8("background:none"));
        label_temperature6->setAlignment(Qt::AlignCenter);
        label_icon6 = new QLabel(Weather);
        label_icon6->setObjectName(QString::fromUtf8("label_icon6"));
        label_icon6->setGeometry(QRect(572, 380, 100, 100));
        label_icon6->setFont(font1);
        label_icon6->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-image: url(:/resource/wea_images/bingbao.png);"));
        label_icon6->setAlignment(Qt::AlignCenter);
        label_wea6 = new QLabel(Weather);
        label_wea6->setObjectName(QString::fromUtf8("label_wea6"));
        label_wea6->setGeometry(QRect(572, 480, 100, 45));
        label_wea6->setFont(font2);
        label_wea6->setStyleSheet(QString::fromUtf8("background:none"));
        label_wea6->setAlignment(Qt::AlignCenter);
        label_date7 = new QLabel(Weather);
        label_date7->setObjectName(QString::fromUtf8("label_date7"));
        label_date7->setGeometry(QRect(684, 320, 100, 60));
        label_date7->setFont(font);
        label_date7->setStyleSheet(QString::fromUtf8("background:none"));
        label_date7->setAlignment(Qt::AlignCenter);
        label_temperature7 = new QLabel(Weather);
        label_temperature7->setObjectName(QString::fromUtf8("label_temperature7"));
        label_temperature7->setGeometry(QRect(684, 525, 100, 45));
        label_temperature7->setFont(font3);
        label_temperature7->setStyleSheet(QString::fromUtf8("background:none"));
        label_temperature7->setAlignment(Qt::AlignCenter);
        label_icon7 = new QLabel(Weather);
        label_icon7->setObjectName(QString::fromUtf8("label_icon7"));
        label_icon7->setGeometry(QRect(684, 380, 100, 100));
        label_icon7->setFont(font1);
        label_icon7->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-image: url(:/resource/wea_images/bingbao.png);"));
        label_icon7->setAlignment(Qt::AlignCenter);
        label_wea7 = new QLabel(Weather);
        label_wea7->setObjectName(QString::fromUtf8("label_wea7"));
        label_wea7->setGeometry(QRect(684, 480, 100, 45));
        label_wea7->setFont(font2);
        label_wea7->setStyleSheet(QString::fromUtf8("background:none"));
        label_wea7->setAlignment(Qt::AlignCenter);
        btn_localName = new QPushButton(Weather);
        btn_localName->setObjectName(QString::fromUtf8("btn_localName"));
        btn_localName->setGeometry(QRect(460, 60, 280, 80));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(28);
        font4.setBold(true);
        font4.setWeight(75);
        btn_localName->setFont(font4);
        btn_localName->setLayoutDirection(Qt::LeftToRight);
        btn_localName->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
""));
        label_icon = new QLabel(Weather);
        label_icon->setObjectName(QString::fromUtf8("label_icon"));
        label_icon->setGeometry(QRect(575, 20, 50, 50));
        label_icon->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-image: url(:/resource/wea_images/location.png);"));
        label_weatherIcon = new QLabel(Weather);
        label_weatherIcon->setObjectName(QString::fromUtf8("label_weatherIcon"));
        label_weatherIcon->setGeometry(QRect(460, 160, 80, 80));
        label_weatherIcon->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/wea_images/bingbao.png);\n"
"background:none;"));
        label_tem = new QLabel(Weather);
        label_tem->setObjectName(QString::fromUtf8("label_tem"));
        label_tem->setGeometry(QRect(540, 170, 140, 100));
        QFont font5;
        font5.setPointSize(18);
        font5.setBold(true);
        font5.setWeight(75);
        label_tem->setFont(font5);
        label_tem->setStyleSheet(QString::fromUtf8("background:none;"));
        label_tem->setAlignment(Qt::AlignCenter);
        label_wea = new QLabel(Weather);
        label_wea->setObjectName(QString::fromUtf8("label_wea"));
        label_wea->setGeometry(QRect(450, 250, 100, 30));
        label_wea->setFont(font2);
        label_wea->setStyleSheet(QString::fromUtf8("background:none;"));
        label_wea->setAlignment(Qt::AlignCenter);
        label_datetime = new QLabel(Weather);
        label_datetime->setObjectName(QString::fromUtf8("label_datetime"));
        label_datetime->setGeometry(QRect(40, 140, 380, 110));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(22);
        font6.setBold(true);
        font6.setWeight(75);
        label_datetime->setFont(font6);
        label_datetime->setStyleSheet(QString::fromUtf8("background:none;\n"
"font-family:\345\276\256\350\275\257\351\233\205\351\273\221;"));
        btn_backIcon = new QPushButton(Weather);
        btn_backIcon->setObjectName(QString::fromUtf8("btn_backIcon"));
        btn_backIcon->setGeometry(QRect(12, 30, 60, 60));
        btn_backIcon->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/back.png);\n"
"background:none;"));
        label_backName = new QLabel(Weather);
        label_backName->setObjectName(QString::fromUtf8("label_backName"));
        label_backName->setGeometry(QRect(12, 90, 60, 20));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font7.setPointSize(9);
        font7.setBold(true);
        font7.setWeight(75);
        label_backName->setFont(font7);
        label_backName->setStyleSheet(QString::fromUtf8("background:none;\n"
"font-family:\345\276\256\350\275\257\351\233\205\351\273\221;"));
        label_backName->setAlignment(Qt::AlignCenter);
        label_temMax = new QLabel(Weather);
        label_temMax->setObjectName(QString::fromUtf8("label_temMax"));
        label_temMax->setGeometry(QRect(680, 170, 90, 50));
        QFont font8;
        font8.setPointSize(13);
        label_temMax->setFont(font8);
        label_temMax->setStyleSheet(QString::fromUtf8("background:none;\n"
""));
        label_temMax->setAlignment(Qt::AlignCenter);
        label_temMin = new QLabel(Weather);
        label_temMin->setObjectName(QString::fromUtf8("label_temMin"));
        label_temMin->setGeometry(QRect(680, 220, 90, 50));
        label_temMin->setFont(font8);
        label_temMin->setStyleSheet(QString::fromUtf8("background:none;"));
        label_temMin->setAlignment(Qt::AlignCenter);

        retranslateUi(Weather);

        QMetaObject::connectSlotsByName(Weather);
    } // setupUi

    void retranslateUi(QWidget *Weather)
    {
        Weather->setWindowTitle(QCoreApplication::translate("Weather", "\350\275\246\350\275\275\345\244\232\345\252\222\344\275\223-\345\244\251\346\260\224", nullptr));
        label_1->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_date1->setText(QCoreApplication::translate("Weather", "6-24\n"
"\345\221\250\344\272\214", nullptr));
        label_icon1->setText(QString());
        label_wea1->setText(QCoreApplication::translate("Weather", "\345\260\217\351\233\250", nullptr));
        label_temperature1->setText(QCoreApplication::translate("Weather", "22\342\204\203\n"
"19\342\204\203", nullptr));
        label_temperature2->setText(QCoreApplication::translate("Weather", "22\342\204\203\n"
"19\342\204\203", nullptr));
        label_date2->setText(QCoreApplication::translate("Weather", "6-24\n"
"\345\221\250\344\272\214", nullptr));
        label_icon2->setText(QString());
        label_wea2->setText(QCoreApplication::translate("Weather", "\345\260\217\351\233\250", nullptr));
        label_temperature3->setText(QCoreApplication::translate("Weather", "22\342\204\203\n"
"19\342\204\203", nullptr));
        label_date3->setText(QCoreApplication::translate("Weather", "6-24\n"
"\345\221\250\344\272\214", nullptr));
        label_icon3->setText(QString());
        label_wea3->setText(QCoreApplication::translate("Weather", "\345\260\217\351\233\250", nullptr));
        label_temperature4->setText(QCoreApplication::translate("Weather", "22\342\204\203\n"
"19\342\204\203", nullptr));
        label_date4->setText(QCoreApplication::translate("Weather", "6-24\n"
"\345\221\250\344\272\214", nullptr));
        label_icon4->setText(QString());
        label_wea4->setText(QCoreApplication::translate("Weather", "\345\260\217\351\233\250", nullptr));
        label_date5->setText(QCoreApplication::translate("Weather", "6-24\n"
"\345\221\250\344\272\214", nullptr));
        label_temperature5->setText(QCoreApplication::translate("Weather", "22\342\204\203\n"
"19\342\204\203", nullptr));
        label_icon5->setText(QString());
        label_wea5->setText(QCoreApplication::translate("Weather", "\345\260\217\351\233\250", nullptr));
        label_date6->setText(QCoreApplication::translate("Weather", "6-24\n"
"\345\221\250\344\272\214", nullptr));
        label_temperature6->setText(QCoreApplication::translate("Weather", "22\342\204\203\n"
"19\342\204\203", nullptr));
        label_icon6->setText(QString());
        label_wea6->setText(QCoreApplication::translate("Weather", "\345\260\217\351\233\250", nullptr));
        label_date7->setText(QCoreApplication::translate("Weather", "6-24\n"
"\345\221\250\344\272\214", nullptr));
        label_temperature7->setText(QCoreApplication::translate("Weather", "22\342\204\203\n"
"19\342\204\203", nullptr));
        label_icon7->setText(QString());
        label_wea7->setText(QCoreApplication::translate("Weather", "\345\260\217\351\233\250", nullptr));
        btn_localName->setText(QCoreApplication::translate("Weather", "\345\221\274\345\222\214\346\265\251\347\211\271\345\270\202", nullptr));
        label_icon->setText(QString());
        label_weatherIcon->setText(QString());
        label_tem->setText(QCoreApplication::translate("Weather", "-10.1\342\204\203", nullptr));
        label_wea->setText(QCoreApplication::translate("Weather", "\345\260\217\351\233\250", nullptr));
        label_datetime->setText(QCoreApplication::translate("Weather", "2025-06-24 \345\221\250\344\272\214\n"
"17:00:00", nullptr));
        btn_backIcon->setText(QString());
        label_backName->setText(QCoreApplication::translate("Weather", "\350\277\224\345\233\236", nullptr));
        label_temMax->setText(QCoreApplication::translate("Weather", "-10.1\342\204\203", nullptr));
        label_temMin->setText(QCoreApplication::translate("Weather", "-10.1\342\204\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Weather: public Ui_Weather {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERWINDOW_H
