/********************************************************************************
** Form generated from reading UI file 'mapwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWINDOW_H
#define UI_MAPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWindow
{
public:
    QWidget *centralwidget;
    QLabel *lb_bacground;
    QPushButton *btn_exit;
    QPushButton *btn_zoomIn;
    QPushButton *btn_zoomOut;

    void setupUi(QMainWindow *MapWindow)
    {
        if (MapWindow->objectName().isEmpty())
            MapWindow->setObjectName(QString::fromUtf8("MapWindow"));
        MapWindow->resize(800, 600);
        centralwidget = new QWidget(MapWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        lb_bacground = new QLabel(centralwidget);
        lb_bacground->setObjectName(QString::fromUtf8("lb_bacground"));
        lb_bacground->setGeometry(QRect(0, 0, 800, 600));
        lb_bacground->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/map/bcakground.jpg);"));
        btn_exit = new QPushButton(centralwidget);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setGeometry(QRect(720, 10, 50, 50));
        btn_exit->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/map/exit.png);"));
        btn_zoomIn = new QPushButton(centralwidget);
        btn_zoomIn->setObjectName(QString::fromUtf8("btn_zoomIn"));
        btn_zoomIn->setGeometry(QRect(720, 430, 50, 50));
        btn_zoomIn->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/map/zoomin.png);"));
        btn_zoomOut = new QPushButton(centralwidget);
        btn_zoomOut->setObjectName(QString::fromUtf8("btn_zoomOut"));
        btn_zoomOut->setGeometry(QRect(720, 510, 50, 50));
        btn_zoomOut->setStyleSheet(QString::fromUtf8("border-image: url(:/resource/map/zoomout.png);"));
        MapWindow->setCentralWidget(centralwidget);

        retranslateUi(MapWindow);

        QMetaObject::connectSlotsByName(MapWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MapWindow)
    {
        MapWindow->setWindowTitle(QCoreApplication::translate("MapWindow", "\350\275\246\350\275\275\345\244\232\345\252\222\344\275\223-\345\234\260\345\233\276", nullptr));
        lb_bacground->setText(QString());
        btn_exit->setText(QString());
        btn_zoomIn->setText(QString());
        btn_zoomOut->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MapWindow: public Ui_MapWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWINDOW_H
