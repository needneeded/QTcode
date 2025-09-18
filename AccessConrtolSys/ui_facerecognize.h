/********************************************************************************
** Form generated from reading UI file 'facerecognize.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACERECOGNIZE_H
#define UI_FACERECOGNIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceRecognize
{
public:
    QWidget *centralwidget;
    QPushButton *btn_back;
    QLabel *lb_camera;

    void setupUi(QMainWindow *FaceRecognize)
    {
        if (FaceRecognize->objectName().isEmpty())
            FaceRecognize->setObjectName("FaceRecognize");
        FaceRecognize->resize(800, 494);
        centralwidget = new QWidget(FaceRecognize);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("#lb_camera{\n"
"	border:1px solid black;\n"
"}"));
        btn_back = new QPushButton(centralwidget);
        btn_back->setObjectName("btn_back");
        btn_back->setGeometry(QRect(30, 30, 80, 35));
        QFont font;
        font.setPointSize(8);
        btn_back->setFont(font);
        lb_camera = new QLabel(centralwidget);
        lb_camera->setObjectName("lb_camera");
        lb_camera->setGeometry(QRect(225, 136, 350, 216));
        FaceRecognize->setCentralWidget(centralwidget);

        retranslateUi(FaceRecognize);

        QMetaObject::connectSlotsByName(FaceRecognize);
    } // setupUi

    void retranslateUi(QMainWindow *FaceRecognize)
    {
        FaceRecognize->setWindowTitle(QCoreApplication::translate("FaceRecognize", "\344\272\272\350\204\270\350\257\206\345\210\253", nullptr));
        btn_back->setText(QCoreApplication::translate("FaceRecognize", "\350\277\224\345\233\236", nullptr));
        lb_camera->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FaceRecognize: public Ui_FaceRecognize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACERECOGNIZE_H
