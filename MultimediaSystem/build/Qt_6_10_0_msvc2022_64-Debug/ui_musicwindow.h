/********************************************************************************
** Form generated from reading UI file 'musicwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICWINDOW_H
#define UI_MUSICWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicWindow
{
public:
    QTabWidget *tabWidget;
    QWidget *local;
    QListWidget *songList;
    QWidget *online;
    QListWidget *onlienList;
    QLabel *lb_background;
    QPushButton *btn_pre;
    QSlider *music_slider;
    QPushButton *btn_play;
    QPushButton *btn_next;
    QLabel *lb_voice0;
    QLabel *lb_voice1;
    QSlider *voice_slider;
    QPushButton *btn_back;
    QPushButton *btn_loadFile;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *songName;
    QLabel *lb_emp1;
    QLabel *lb_1;
    QLabel *lb_2;
    QLabel *lb_3;
    QLabel *lb_4;
    QLabel *lb_5;
    QLabel *lb_6;
    QLabel *lb_7;
    QLabel *lb_emp2;
    QPushButton *btn_mode;
    QLabel *lb_time;

    void setupUi(QWidget *MusicWindow)
    {
        if (MusicWindow->objectName().isEmpty())
            MusicWindow->setObjectName("MusicWindow");
        MusicWindow->resize(800, 600);
        MusicWindow->setStyleSheet(QString::fromUtf8("\n"
"#btn_play[mode='play']{\n"
"	border-image: url(:/resource/music_images/play1.png);\n"
"}\n"
"\n"
"#btn_play[mode='play']:hover{\n"
"	border-image: url(:/resource/music_images/play1_hover.png);\n"
"}\n"
"\n"
"#btn_play[mode='pause']{\n"
"	\n"
"	border-image: url(:/resource/music_images/pause.png);\n"
"}\n"
"\n"
"#btn_play[mode='pause']:hover{\n"
"	border-image: url(:/resource/music_images/pause_hover.png);\n"
"}\n"
"\n"
"#btn_pre{\n"
"	border-image: url(:/resource/music_images/pre.png);\n"
"}\n"
"\n"
"#btn_pre:hover{\n"
"	border-image: url(:/resource/music_images/pre_hover.png);\n"
"}\n"
"\n"
"#btn_next{\n"
"	border-image: url(:/resource/music_images/next.png);\n"
"}\n"
"\n"
"#btn_next:hover{\n"
"	border-image: url(:/resource/music_images/next_hover.png);\n"
"}\n"
"\n"
"#btn_mode[mode='loop']{\n"
"	border-image: url(:/resource/music_images/Loop.png);\n"
"}\n"
"#btn_mode[mode='sequential']{\n"
"	border-image: url(:/resource/music_images/Sequence.png);\n"
"}\n"
"#btn_mode[mode='currentloop']{\n"
"	border-ima"
                        "ge: url(:/resource/music_images/CurrentInLoop.png);\n"
"}\n"
"#btn_mode[mode='random']{\n"
"	border-image: url(:/resource/music_images/Random.png);\n"
"}\n"
"\n"
"#lb_1,#lb_2,#lb_3,#lb_4,#lb_5,#lb_6,#lb_7,#lb_emp1,#lb_emp2{\n"
"	background-color:rgb(255, 193, 217);\n"
"}\n"
""));
        tabWidget = new QTabWidget(MusicWindow);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 40, 221, 460));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"border-radius:10px;\n"
"\n"
"\n"
""));
        tabWidget->setIconSize(QSize(20, 16));
        local = new QWidget();
        local->setObjectName("local");
        songList = new QListWidget(local);
        songList->setObjectName("songList");
        songList->setGeometry(QRect(0, 0, 210, 430));
        tabWidget->addTab(local, QString());
        online = new QWidget();
        online->setObjectName("online");
        onlienList = new QListWidget(online);
        onlienList->setObjectName("onlienList");
        onlienList->setGeometry(QRect(0, 0, 210, 430));
        tabWidget->addTab(online, QString());
        lb_background = new QLabel(MusicWindow);
        lb_background->setObjectName("lb_background");
        lb_background->setGeometry(QRect(0, 500, 800, 100));
        lb_background->setStyleSheet(QString::fromUtf8("background:rgb(255, 170, 186);\n"
"border-radius:10px"));
        btn_pre = new QPushButton(MusicWindow);
        btn_pre->setObjectName("btn_pre");
        btn_pre->setGeometry(QRect(20, 540, 50, 50));
        btn_pre->setStyleSheet(QString::fromUtf8("background:none;"));
        music_slider = new QSlider(MusicWindow);
        music_slider->setObjectName("music_slider");
        music_slider->setGeometry(QRect(220, 560, 570, 10));
        music_slider->setStyleSheet(QString::fromUtf8("background:none;\n"
"\n"
""));
        music_slider->setMaximum(100);
        music_slider->setSingleStep(1);
        music_slider->setValue(0);
        music_slider->setSliderPosition(0);
        music_slider->setOrientation(Qt::Horizontal);
        btn_play = new QPushButton(MusicWindow);
        btn_play->setObjectName("btn_play");
        btn_play->setGeometry(QRect(80, 535, 60, 60));
        btn_play->setStyleSheet(QString::fromUtf8("background:none;"));
        btn_next = new QPushButton(MusicWindow);
        btn_next->setObjectName("btn_next");
        btn_next->setGeometry(QRect(150, 540, 50, 50));
        btn_next->setStyleSheet(QString::fromUtf8("background:none;"));
        lb_voice0 = new QLabel(MusicWindow);
        lb_voice0->setObjectName("lb_voice0");
        lb_voice0->setGeometry(QRect(200, 510, 15, 15));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font.setPointSize(5);
        lb_voice0->setFont(font);
        lb_voice0->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/music_images/24gf-volumeHigh.png);\n"
"background:none;"));
        lb_voice1 = new QLabel(MusicWindow);
        lb_voice1->setObjectName("lb_voice1");
        lb_voice1->setGeometry(QRect(10, 510, 15, 15));
        QFont font1;
        font1.setPointSize(5);
        lb_voice1->setFont(font1);
        lb_voice1->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/music_images/24gf-volumeLow.png);\n"
"background:none;"));
        voice_slider = new QSlider(MusicWindow);
        voice_slider->setObjectName("voice_slider");
        voice_slider->setGeometry(QRect(30, 512, 160, 10));
        voice_slider->setStyleSheet(QString::fromUtf8("background:none;\n"
"\n"
"\n"
"\n"
""));
        voice_slider->setMaximum(100);
        voice_slider->setSingleStep(1);
        voice_slider->setValue(50);
        voice_slider->setOrientation(Qt::Horizontal);
        btn_back = new QPushButton(MusicWindow);
        btn_back->setObjectName("btn_back");
        btn_back->setGeometry(QRect(0, 0, 40, 40));
        btn_back->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/music_images/back3.png);\n"
"background:none;"));
        btn_loadFile = new QPushButton(MusicWindow);
        btn_loadFile->setObjectName("btn_loadFile");
        btn_loadFile->setGeometry(QRect(360, 510, 30, 30));
        btn_loadFile->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/music_images/file_open.png);\n"
"background:none;"));
        verticalLayoutWidget = new QWidget(MusicWindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(220, 40, 581, 461));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        songName = new QLabel(verticalLayoutWidget);
        songName->setObjectName("songName");
        QFont font2;
        font2.setPointSize(16);
        songName->setFont(font2);
        songName->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 162, 192)"));
        songName->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(songName);

        lb_emp1 = new QLabel(verticalLayoutWidget);
        lb_emp1->setObjectName("lb_emp1");
        QFont font3;
        font3.setPointSize(13);
        lb_emp1->setFont(font3);
        lb_emp1->setStyleSheet(QString::fromUtf8(""));
        lb_emp1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_emp1);

        lb_1 = new QLabel(verticalLayoutWidget);
        lb_1->setObjectName("lb_1");
        QFont font4;
        font4.setPointSize(10);
        lb_1->setFont(font4);
        lb_1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_1);

        lb_2 = new QLabel(verticalLayoutWidget);
        lb_2->setObjectName("lb_2");
        lb_2->setFont(font4);
        lb_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_2);

        lb_3 = new QLabel(verticalLayoutWidget);
        lb_3->setObjectName("lb_3");
        lb_3->setFont(font4);
        lb_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_3);

        lb_4 = new QLabel(verticalLayoutWidget);
        lb_4->setObjectName("lb_4");
        lb_4->setFont(font4);
        lb_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_4);

        lb_5 = new QLabel(verticalLayoutWidget);
        lb_5->setObjectName("lb_5");
        lb_5->setFont(font4);
        lb_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_5);

        lb_6 = new QLabel(verticalLayoutWidget);
        lb_6->setObjectName("lb_6");
        lb_6->setFont(font4);
        lb_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_6);

        lb_7 = new QLabel(verticalLayoutWidget);
        lb_7->setObjectName("lb_7");
        lb_7->setFont(font4);
        lb_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_7);

        lb_emp2 = new QLabel(verticalLayoutWidget);
        lb_emp2->setObjectName("lb_emp2");
        lb_emp2->setFont(font3);
        lb_emp2->setStyleSheet(QString::fromUtf8(""));
        lb_emp2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_emp2);

        btn_mode = new QPushButton(MusicWindow);
        btn_mode->setObjectName("btn_mode");
        btn_mode->setGeometry(QRect(290, 510, 30, 30));
        btn_mode->setStyleSheet(QString::fromUtf8("background:none"));
        lb_time = new QLabel(MusicWindow);
        lb_time->setObjectName("lb_time");
        lb_time->setGeometry(QRect(670, 520, 120, 30));
        lb_time->setStyleSheet(QString::fromUtf8("background:none"));
        lb_time->setAlignment(Qt::AlignCenter);

        retranslateUi(MusicWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MusicWindow);
    } // setupUi

    void retranslateUi(QWidget *MusicWindow)
    {
        MusicWindow->setWindowTitle(QCoreApplication::translate("MusicWindow", "\350\275\246\350\275\275\345\244\232\345\252\222\344\275\223-\351\237\263\344\271\220", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(local), QCoreApplication::translate("MusicWindow", "\346\234\254\345\234\260\345\210\227\350\241\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(online), QCoreApplication::translate("MusicWindow", "\345\234\250\347\272\277\345\210\227\350\241\250", nullptr));
        lb_background->setText(QString());
        btn_pre->setText(QString());
        btn_play->setText(QString());
        btn_next->setText(QString());
        lb_voice0->setText(QString());
        lb_voice1->setText(QString());
        btn_back->setText(QString());
        btn_loadFile->setText(QString());
        songName->setText(QCoreApplication::translate("MusicWindow", "\346\255\214\345\220\215", nullptr));
        lb_emp1->setText(QString());
        lb_1->setText(QCoreApplication::translate("MusicWindow", "\346\232\202\346\227\240\346\233\264\345\244\232\346\255\214\350\257\215", nullptr));
        lb_2->setText(QString());
        lb_3->setText(QString());
        lb_4->setText(QString());
        lb_5->setText(QString());
        lb_6->setText(QString());
        lb_7->setText(QString());
        lb_emp2->setText(QString());
        btn_mode->setText(QString());
        lb_time->setText(QCoreApplication::translate("MusicWindow", "10:10/10:10", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicWindow: public Ui_MusicWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICWINDOW_H
