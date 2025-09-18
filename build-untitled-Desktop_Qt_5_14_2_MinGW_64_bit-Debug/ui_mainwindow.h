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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 400);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 255, 231);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 40, 140, 40));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 100, 60, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";\n"
"background-color: rgb(85, 170, 255);"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 100, 180, 20));
        lineEdit->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(190, 204, 255);"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 140, 180, 20));
        lineEdit_2->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(190, 204, 255);"));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 140, 60, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";\n"
"background-color: rgb(85, 170, 255);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 180, 80, 20));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 255, 243);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 180, 80, 20));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 255, 243);"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\223\211\345\215\216\346\225\231\350\202\262", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\257\206  \347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
