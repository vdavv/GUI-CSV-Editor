/********************************************************************************
** Form generated from reading UI file 'logowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGOWINDOW_H
#define UI_LOGOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogoWindow
{
public:

    void setupUi(QWidget *LogoWindow)
    {
        if (LogoWindow->objectName().isEmpty())
            LogoWindow->setObjectName("LogoWindow");
        LogoWindow->resize(400, 300);

        retranslateUi(LogoWindow);

        QMetaObject::connectSlotsByName(LogoWindow);
    } // setupUi

    void retranslateUi(QWidget *LogoWindow)
    {
        LogoWindow->setWindowTitle(QCoreApplication::translate("LogoWindow", "Logo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogoWindow: public Ui_LogoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGOWINDOW_H
