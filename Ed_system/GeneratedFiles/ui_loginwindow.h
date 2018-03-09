/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginwindow
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_3;

    void setupUi(QWidget *loginwindow)
    {
        if (loginwindow->objectName().isEmpty())
            loginwindow->setObjectName(QStringLiteral("loginwindow"));
        loginwindow->resize(478, 362);
        pushButton = new QPushButton(loginwindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 240, 93, 28));
        lineEdit = new QLineEdit(loginwindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 150, 201, 21));
        lineEdit_2 = new QLineEdit(loginwindow);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 190, 201, 21));
        pushButton_2 = new QPushButton(loginwindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 240, 93, 28));
        label = new QLabel(loginwindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 150, 61, 21));
        label_2 = new QLabel(loginwindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 190, 31, 21));
        label_3 = new QLabel(loginwindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 70, 301, 41));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        pushButton_3 = new QPushButton(loginwindow);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 280, 93, 28));

        retranslateUi(loginwindow);

        QMetaObject::connectSlotsByName(loginwindow);
    } // setupUi

    void retranslateUi(QWidget *loginwindow)
    {
        loginwindow->setWindowTitle(QApplication::translate("loginwindow", "loginwindow", 0));
        pushButton->setText(QApplication::translate("loginwindow", "\345\255\246\347\224\237\347\231\273\345\275\225", 0));
        pushButton_2->setText(QApplication::translate("loginwindow", "\346\225\231\345\270\210\347\231\273\345\275\225", 0));
        label->setText(QApplication::translate("loginwindow", "\347\224\250\346\210\267\347\274\226\345\217\267", 0));
        label_2->setText(QApplication::translate("loginwindow", "\345\257\206\347\240\201", 0));
        label_3->setText(QApplication::translate("loginwindow", "\351\200\211\350\257\276\347\263\273\347\273\237\347\224\250\346\210\267\347\231\273\345\275\225", 0));
        pushButton_3->setText(QApplication::translate("loginwindow", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class loginwindow: public Ui_loginwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
