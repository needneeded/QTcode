/********************************************************************************
** Form generated from reading UI file 'faceenter.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEENTER_H
#define UI_FACEENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceEnter
{
public:
    QWidget *centralwidget;
    QLabel *lb_name;
    QLabel *lb_num;
    QLabel *lb_phone;
    QLineEdit *le_num;
    QPushButton *btn_enter;
    QPushButton *btn_back;
    QLabel *lb_notice;
    QLineEdit *le_name;
    QLineEdit *le_phone;
    QPushButton *btn_submit;
    QLabel *cameraArea;
    QPushButton *btn_submit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FaceEnter)
    {
        if (FaceEnter->objectName().isEmpty())
            FaceEnter->setObjectName("FaceEnter");
        FaceEnter->resize(800, 494);
        centralwidget = new QWidget(FaceEnter);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("\n"
"#cameraArea{\n"
"	border:1px solid black;\n"
"	border-radius: 2px\n"
"}"));
        lb_name = new QLabel(centralwidget);
        lb_name->setObjectName("lb_name");
        lb_name->setGeometry(QRect(420, 40, 70, 30));
        QFont font;
        font.setPointSize(8);
        lb_name->setFont(font);
        lb_num = new QLabel(centralwidget);
        lb_num->setObjectName("lb_num");
        lb_num->setGeometry(QRect(420, 200, 70, 30));
        lb_num->setFont(font);
        lb_phone = new QLabel(centralwidget);
        lb_phone->setObjectName("lb_phone");
        lb_phone->setGeometry(QRect(420, 120, 70, 30));
        lb_phone->setFont(font);
        le_num = new QLineEdit(centralwidget);
        le_num->setObjectName("le_num");
        le_num->setGeometry(QRect(500, 200, 250, 30));
        btn_enter = new QPushButton(centralwidget);
        btn_enter->setObjectName("btn_enter");
        btn_enter->setGeometry(QRect(220, 360, 100, 35));
        btn_enter->setFont(font);
        btn_back = new QPushButton(centralwidget);
        btn_back->setObjectName("btn_back");
        btn_back->setGeometry(QRect(40, 360, 100, 35));
        btn_back->setFont(font);
        lb_notice = new QLabel(centralwidget);
        lb_notice->setObjectName("lb_notice");
        lb_notice->setGeometry(QRect(130, 260, 411, 65));
        lb_notice->setFont(font);
        le_name = new QLineEdit(centralwidget);
        le_name->setObjectName("le_name");
        le_name->setGeometry(QRect(500, 40, 250, 30));
        le_phone = new QLineEdit(centralwidget);
        le_phone->setObjectName("le_phone");
        le_phone->setGeometry(QRect(500, 120, 250, 30));
        btn_submit = new QPushButton(centralwidget);
        btn_submit->setObjectName("btn_submit");
        btn_submit->setGeometry(QRect(620, 360, 100, 35));
        cameraArea = new QLabel(centralwidget);
        cameraArea->setObjectName("cameraArea");
        cameraArea->setGeometry(QRect(20, 30, 350, 220));
        btn_submit_2 = new QPushButton(centralwidget);
        btn_submit_2->setObjectName("btn_submit_2");
        btn_submit_2->setGeometry(QRect(430, 360, 100, 35));
        FaceEnter->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FaceEnter);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 29));
        FaceEnter->setMenuBar(menubar);
        statusbar = new QStatusBar(FaceEnter);
        statusbar->setObjectName("statusbar");
        FaceEnter->setStatusBar(statusbar);

        retranslateUi(FaceEnter);

        QMetaObject::connectSlotsByName(FaceEnter);
    } // setupUi

    void retranslateUi(QMainWindow *FaceEnter)
    {
        FaceEnter->setWindowTitle(QCoreApplication::translate("FaceEnter", "MainWindow", nullptr));
        lb_name->setText(QCoreApplication::translate("FaceEnter", "\344\275\217\346\210\267\345\247\223\345\220\215\357\274\232", nullptr));
        lb_num->setText(QCoreApplication::translate("FaceEnter", "\351\227\250 \347\211\214 \345\217\267\357\274\232", nullptr));
        lb_phone->setText(QCoreApplication::translate("FaceEnter", "\344\275\217\346\210\267\347\224\265\350\257\235\357\274\232", nullptr));
        btn_enter->setText(QCoreApplication::translate("FaceEnter", "\345\274\200\345\247\213\345\275\225\345\205\245", nullptr));
        btn_back->setText(QCoreApplication::translate("FaceEnter", "\350\277\224\345\233\236", nullptr));
        lb_notice->setText(QCoreApplication::translate("FaceEnter", "\346\263\250\346\204\217\344\272\213\351\241\271\n"
"    \350\257\267\347\202\271\345\207\273\342\200\234\345\274\200\345\247\213\345\275\225\345\205\245\342\200\235\345\220\216\357\274\214\345\206\215\351\235\242\345\257\271\350\256\276\345\244\207\343\200\202\n"
"    \351\207\207\351\233\206\345\256\214\346\210\220\357\274\214\347\202\271\345\207\273\342\200\234\347\273\223\346\235\237\345\275\225\345\205\245\345\220\216\357\274\214\350\256\276\345\244\207\344\270\215\345\206\215\351\207\207\351\233\206\343\200\202\342\200\235", nullptr));
        btn_submit->setText(QCoreApplication::translate("FaceEnter", "\346\217\220\344\272\244", nullptr));
        cameraArea->setText(QString());
        btn_submit_2->setText(QCoreApplication::translate("FaceEnter", "\345\244\232\350\247\222\345\272\246\351\207\207\351\233\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaceEnter: public Ui_FaceEnter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEENTER_H
