/********************************************************************************
** Form generated from reading UI file 'weather.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHER_H
#define UI_WEATHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Weather
{
public:
    QLabel *label;
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
    QPushButton *pushButton;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton_2;
    QLabel *label_13;

    void setupUi(QWidget *Weather)
    {
        if (Weather->objectName().isEmpty())
            Weather->setObjectName(QString::fromUtf8("Weather"));
        Weather->resize(800, 600);
        Weather->setStyleSheet(QString::fromUtf8("background:#22ACEF"));
        label = new QLabel(Weather);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(12, 320, 100, 250));
        label->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 255)"));
        label_2 = new QLabel(Weather);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(124, 320, 100, 250));
        label_2->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 255)"));
        label_3 = new QLabel(Weather);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(348, 320, 100, 250));
        label_3->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 255)"));
        label_4 = new QLabel(Weather);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(572, 320, 100, 250));
        label_4->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 255)"));
        label_5 = new QLabel(Weather);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(684, 320, 100, 250));
        label_5->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 255)"));
        label_6 = new QLabel(Weather);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(236, 320, 100, 250));
        label_6->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 255)"));
        label_7 = new QLabel(Weather);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(460, 320, 100, 250));
        label_7->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 255)"));
        label_date1 = new QLabel(Weather);
        label_date1->setObjectName(QString::fromUtf8("label_date1"));
        label_date1->setGeometry(QRect(12, 320, 100, 60));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_date1->setFont(font);
        label_date1->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 0)"));
        label_date1->setAlignment(Qt::AlignCenter);
        label_icon1 = new QLabel(Weather);
        label_icon1->setObjectName(QString::fromUtf8("label_icon1"));
        label_icon1->setGeometry(QRect(12, 380, 100, 100));
        QFont font1;
        font1.setPointSize(12);
        label_icon1->setFont(font1);
        label_icon1->setStyleSheet(QString::fromUtf8("background:rgb(255, 170, 0)"));
        label_icon1->setAlignment(Qt::AlignCenter);
        label_wea1 = new QLabel(Weather);
        label_wea1->setObjectName(QString::fromUtf8("label_wea1"));
        label_wea1->setGeometry(QRect(12, 480, 100, 45));
        QFont font2;
        font2.setPointSize(7);
        font2.setBold(true);
        font2.setWeight(75);
        label_wea1->setFont(font2);
        label_wea1->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 0)"));
        label_wea1->setAlignment(Qt::AlignCenter);
        label_temperature1 = new QLabel(Weather);
        label_temperature1->setObjectName(QString::fromUtf8("label_temperature1"));
        label_temperature1->setGeometry(QRect(12, 525, 100, 45));
        QFont font3;
        font3.setPointSize(11);
        label_temperature1->setFont(font3);
        label_temperature1->setStyleSheet(QString::fromUtf8("background:rgb(39, 255, 118)"));
        label_temperature1->setAlignment(Qt::AlignCenter);
        label_temperature2 = new QLabel(Weather);
        label_temperature2->setObjectName(QString::fromUtf8("label_temperature2"));
        label_temperature2->setGeometry(QRect(124, 525, 100, 45));
        label_temperature2->setFont(font3);
        label_temperature2->setStyleSheet(QString::fromUtf8("background:rgb(39, 255, 118)"));
        label_temperature2->setAlignment(Qt::AlignCenter);
        label_date2 = new QLabel(Weather);
        label_date2->setObjectName(QString::fromUtf8("label_date2"));
        label_date2->setGeometry(QRect(124, 320, 100, 60));
        label_date2->setFont(font);
        label_date2->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 0)"));
        label_date2->setAlignment(Qt::AlignCenter);
        label_icon2 = new QLabel(Weather);
        label_icon2->setObjectName(QString::fromUtf8("label_icon2"));
        label_icon2->setGeometry(QRect(124, 380, 100, 100));
        label_icon2->setFont(font1);
        label_icon2->setStyleSheet(QString::fromUtf8("background:rgb(255, 170, 0)"));
        label_icon2->setAlignment(Qt::AlignCenter);
        label_wea2 = new QLabel(Weather);
        label_wea2->setObjectName(QString::fromUtf8("label_wea2"));
        label_wea2->setGeometry(QRect(124, 480, 100, 45));
        label_wea2->setFont(font2);
        label_wea2->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 0)"));
        label_wea2->setAlignment(Qt::AlignCenter);
        label_temperature3 = new QLabel(Weather);
        label_temperature3->setObjectName(QString::fromUtf8("label_temperature3"));
        label_temperature3->setGeometry(QRect(236, 525, 100, 45));
        label_temperature3->setFont(font3);
        label_temperature3->setStyleSheet(QString::fromUtf8("background:rgb(39, 255, 118)"));
        label_temperature3->setAlignment(Qt::AlignCenter);
        label_date3 = new QLabel(Weather);
        label_date3->setObjectName(QString::fromUtf8("label_date3"));
        label_date3->setGeometry(QRect(236, 320, 100, 60));
        label_date3->setFont(font);
        label_date3->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 0)"));
        label_date3->setAlignment(Qt::AlignCenter);
        label_icon3 = new QLabel(Weather);
        label_icon3->setObjectName(QString::fromUtf8("label_icon3"));
        label_icon3->setGeometry(QRect(236, 380, 100, 100));
        label_icon3->setFont(font1);
        label_icon3->setStyleSheet(QString::fromUtf8("background:rgb(255, 170, 0)"));
        label_icon3->setAlignment(Qt::AlignCenter);
        label_wea3 = new QLabel(Weather);
        label_wea3->setObjectName(QString::fromUtf8("label_wea3"));
        label_wea3->setGeometry(QRect(236, 480, 100, 45));
        label_wea3->setFont(font2);
        label_wea3->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 0)"));
        label_wea3->setAlignment(Qt::AlignCenter);
        label_temperature4 = new QLabel(Weather);
        label_temperature4->setObjectName(QString::fromUtf8("label_temperature4"));
        label_temperature4->setGeometry(QRect(348, 525, 100, 45));
        label_temperature4->setFont(font3);
        label_temperature4->setStyleSheet(QString::fromUtf8("background:rgb(39, 255, 118)"));
        label_temperature4->setAlignment(Qt::AlignCenter);
        label_date4 = new QLabel(Weather);
        label_date4->setObjectName(QString::fromUtf8("label_date4"));
        label_date4->setGeometry(QRect(348, 320, 100, 60));
        label_date4->setFont(font);
        label_date4->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 0)"));
        label_date4->setAlignment(Qt::AlignCenter);
        label_icon4 = new QLabel(Weather);
        label_icon4->setObjectName(QString::fromUtf8("label_icon4"));
        label_icon4->setGeometry(QRect(348, 380, 100, 100));
        label_icon4->setFont(font1);
        label_icon4->setStyleSheet(QString::fromUtf8("background:rgb(255, 170, 0)"));
        label_icon4->setAlignment(Qt::AlignCenter);
        label_wea4 = new QLabel(Weather);
        label_wea4->setObjectName(QString::fromUtf8("label_wea4"));
        label_wea4->setGeometry(QRect(348, 480, 100, 45));
        label_wea4->setFont(font2);
        label_wea4->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 0)"));
        label_wea4->setAlignment(Qt::AlignCenter);
        label_date5 = new QLabel(Weather);
        label_date5->setObjectName(QString::fromUtf8("label_date5"));
        label_date5->setGeometry(QRect(460, 320, 100, 60));
        label_date5->setFont(font);
        label_date5->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 0)"));
        label_date5->setAlignment(Qt::AlignCenter);
        label_temperature5 = new QLabel(Weather);
        label_temperature5->setObjectName(QString::fromUtf8("label_temperature5"));
        label_temperature5->setGeometry(QRect(460, 525, 100, 45));
        label_temperature5->setFont(font3);
        label_temperature5->setStyleSheet(QString::fromUtf8("background:rgb(39, 255, 118)"));
        label_temperature5->setAlignment(Qt::AlignCenter);
        label_icon5 = new QLabel(Weather);
        label_icon5->setObjectName(QString::fromUtf8("label_icon5"));
        label_icon5->setGeometry(QRect(460, 380, 100, 100));
        label_icon5->setFont(font1);
        label_icon5->setStyleSheet(QString::fromUtf8("background:rgb(255, 170, 0)"));
        label_icon5->setAlignment(Qt::AlignCenter);
        label_wea5 = new QLabel(Weather);
        label_wea5->setObjectName(QString::fromUtf8("label_wea5"));
        label_wea5->setGeometry(QRect(460, 480, 100, 45));
        label_wea5->setFont(font2);
        label_wea5->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 0)"));
        label_wea5->setAlignment(Qt::AlignCenter);
        label_date6 = new QLabel(Weather);
        label_date6->setObjectName(QString::fromUtf8("label_date6"));
        label_date6->setGeometry(QRect(572, 320, 100, 60));
        label_date6->setFont(font);
        label_date6->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 0)"));
        label_date6->setAlignment(Qt::AlignCenter);
        label_temperature6 = new QLabel(Weather);
        label_temperature6->setObjectName(QString::fromUtf8("label_temperature6"));
        label_temperature6->setGeometry(QRect(572, 525, 100, 45));
        label_temperature6->setFont(font3);
        label_temperature6->setStyleSheet(QString::fromUtf8("background:rgb(39, 255, 118)"));
        label_temperature6->setAlignment(Qt::AlignCenter);
        label_icon6 = new QLabel(Weather);
        label_icon6->setObjectName(QString::fromUtf8("label_icon6"));
        label_icon6->setGeometry(QRect(572, 380, 100, 100));
        label_icon6->setFont(font1);
        label_icon6->setStyleSheet(QString::fromUtf8("background:rgb(255, 170, 0)"));
        label_icon6->setAlignment(Qt::AlignCenter);
        label_wea6 = new QLabel(Weather);
        label_wea6->setObjectName(QString::fromUtf8("label_wea6"));
        label_wea6->setGeometry(QRect(572, 480, 100, 45));
        label_wea6->setFont(font2);
        label_wea6->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 0)"));
        label_wea6->setAlignment(Qt::AlignCenter);
        label_date7 = new QLabel(Weather);
        label_date7->setObjectName(QString::fromUtf8("label_date7"));
        label_date7->setGeometry(QRect(684, 320, 100, 60));
        label_date7->setFont(font);
        label_date7->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 0)"));
        label_date7->setAlignment(Qt::AlignCenter);
        label_temperature7 = new QLabel(Weather);
        label_temperature7->setObjectName(QString::fromUtf8("label_temperature7"));
        label_temperature7->setGeometry(QRect(684, 525, 100, 45));
        label_temperature7->setFont(font3);
        label_temperature7->setStyleSheet(QString::fromUtf8("background:rgb(39, 255, 118)"));
        label_temperature7->setAlignment(Qt::AlignCenter);
        label_icon7 = new QLabel(Weather);
        label_icon7->setObjectName(QString::fromUtf8("label_icon7"));
        label_icon7->setGeometry(QRect(684, 380, 100, 100));
        label_icon7->setFont(font1);
        label_icon7->setStyleSheet(QString::fromUtf8("background:rgb(255, 170, 0)"));
        label_icon7->setAlignment(Qt::AlignCenter);
        label_wea7 = new QLabel(Weather);
        label_wea7->setObjectName(QString::fromUtf8("label_wea7"));
        label_wea7->setGeometry(QRect(684, 480, 100, 45));
        label_wea7->setFont(font2);
        label_wea7->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 0)"));
        label_wea7->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(Weather);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(570, 100, 112, 34));
        label_8 = new QLabel(Weather);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(490, 90, 81, 51));
        label_9 = new QLabel(Weather);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(500, 160, 81, 71));
        label_10 = new QLabel(Weather);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(600, 160, 101, 101));
        label_11 = new QLabel(Weather);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(500, 240, 81, 18));
        label_12 = new QLabel(Weather);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(70, 140, 321, 111));
        pushButton_2 = new QPushButton(Weather);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 30, 60, 60));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/back.png);"));
        label_13 = new QLabel(Weather);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(30, 90, 60, 20));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignCenter);

        retranslateUi(Weather);

        QMetaObject::connectSlotsByName(Weather);
    } // setupUi

    void retranslateUi(QWidget *Weather)
    {
        Weather->setWindowTitle(QCoreApplication::translate("Weather", "Form", nullptr));
        label->setText(QString());
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
        pushButton->setText(QCoreApplication::translate("Weather", "\346\210\220\351\203\275\345\270\202", nullptr));
        label_8->setText(QCoreApplication::translate("Weather", "\345\256\232\344\275\215\345\233\276\346\240\207", nullptr));
        label_9->setText(QCoreApplication::translate("Weather", "\345\244\251\346\260\224\345\233\276\346\240\207", nullptr));
        label_10->setText(QCoreApplication::translate("Weather", "\345\275\223\345\211\215\346\260\224\346\270\251", nullptr));
        label_11->setText(QCoreApplication::translate("Weather", "\345\275\223\345\211\215\345\244\251\346\260\224", nullptr));
        label_12->setText(QCoreApplication::translate("Weather", "2025-6-24 \345\221\250\344\272\214\n"
"17:00:00", nullptr));
        pushButton_2->setText(QString());
        label_13->setText(QCoreApplication::translate("Weather", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Weather: public Ui_Weather {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHER_H
