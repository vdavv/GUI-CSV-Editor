/********************************************************************************
** Form generated from reading UI file 'helpwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWINDOW_H
#define UI_HELPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_HelpWindow
{
public:

    void setupUi(QDialog *HelpWindow)
    {
        if (HelpWindow->objectName().isEmpty())
            HelpWindow->setObjectName("HelpWindow");
        HelpWindow->resize(800, 600);

        retranslateUi(HelpWindow);

        QMetaObject::connectSlotsByName(HelpWindow);
    } // setupUi

    void retranslateUi(QDialog *HelpWindow)
    {
        HelpWindow->setWindowTitle(QCoreApplication::translate("HelpWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpWindow: public Ui_HelpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
