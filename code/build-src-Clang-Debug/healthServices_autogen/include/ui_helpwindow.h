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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HelpWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QPushButton *logoButtonHelp;
    QComboBox *languageHelpBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButtonHelp;

    void setupUi(QDialog *HelpWindow)
    {
        if (HelpWindow->objectName().isEmpty())
            HelpWindow->setObjectName("HelpWindow");
        HelpWindow->resize(800, 800);
        gridLayout = new QGridLayout(HelpWindow);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        textBrowser = new QTextBrowser(HelpWindow);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        logoButtonHelp = new QPushButton(HelpWindow);
        logoButtonHelp->setObjectName("logoButtonHelp");

        horizontalLayout->addWidget(logoButtonHelp);

        languageHelpBox = new QComboBox(HelpWindow);
        languageHelpBox->addItem(QString());
        languageHelpBox->addItem(QString());
        languageHelpBox->setObjectName("languageHelpBox");

        horizontalLayout->addWidget(languageHelpBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButtonHelp = new QPushButton(HelpWindow);
        okButtonHelp->setObjectName("okButtonHelp");

        horizontalLayout->addWidget(okButtonHelp);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(HelpWindow);

        QMetaObject::connectSlotsByName(HelpWindow);
    } // setupUi

    void retranslateUi(QDialog *HelpWindow)
    {
        HelpWindow->setWindowTitle(QCoreApplication::translate("HelpWindow", "Help", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("HelpWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.AppleSystemUIFont','serif'; font-size:24pt; font-weight:700;\">About</span> </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.AppleSystemUIFont','serif'; font-weight:700;\">\302\240</span> </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-lef"
                        "t:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.AppleSystemUIFont','serif'; font-size:14pt;\">The U.S. Census Bureau regularly collects information for many metropolitan areas in the United States, including data on number of physicians and number (and size) of hospitals. This dataset has such information for 83 different metropolitan areas.</span> </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.AppleSystemUIFont','serif';\">\302\240</span> </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-i"
                        "ndent:0; text-indent:0px;\"><span style=\" font-family:'.AppleSystemUIFont','serif'; font-size:24pt; font-weight:700;\">Functionality</span> </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.AppleSystemUIFont','serif'; font-weight:700;\">\302\240</span> </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.AppleSystemUIFont','serif'; font-size:18pt;\">Basic:</span><span style=\" font-size:18pt;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Symbol';\">\302\267</span><span style=\" font-family:'Times New Roman'; font-size:7pt;\">\302\240\302\240\302\240\302\240 </span>Add row via \342\200\234Add\342\200\235 button. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-l"
                        "eft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Symbol';\">\302\267</span><span style=\" font-family:'Times New Roman'; font-size:7pt;\">\302\240\302\240\302\240\302\240 </span>Edit row via \342\200\234Edit\342\200\235 button. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Symbol';\">\302\267</span><span style=\" font-family:'Times New Roman'; font-size:7pt;\">\302\240\302\240\302\240\302\240 </span>Delete row via \342\200\234Delete\342\200\235 button. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Symbol';\">\302\267</span><span style=\" font-family:'Times New Roman'; font-size:7pt;\">\302\240\302\240\302\240\302\240 </span>Save the current table to the file via \342\200\234Save\342\200\235 button. </p>\n"
"<p style=\" margin-top:12px; margin"
                        "-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Symbol';\">\302\267</span><span style=\" font-family:'Times New Roman'; font-size:7pt;\">\302\240\302\240\302\240\302\240 </span>Load data from the original file losing the data in the table. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Symbol';\">\302\267</span><span style=\" font-family:'Times New Roman'; font-size:7pt;\">\302\240\302\240\302\240\302\240 </span>Display the app logo via \342\200\234Logo\342\200\235 button. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Symbol';\">\302\267</span><span style=\" font-family:'Times New Roman'; font-size:7pt;\">\302\240\302\240\302\240\302\240 </span>Edit any cell by double-clicking on it. </p>\n"
"<p style=\" margin-top:12px;"
                        " margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Symbol';\">\302\267</span><span style=\" font-family:'Times New Roman'; font-size:7pt;\">\302\240\302\240\302\240\302\240 </span>View the info of any row by clicking on its number to the left of the table. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\302\240 \302\240 </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">Advanced: </span>\302\240 </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Symbol';\">\302\267</span><span style=\" font-family:'Times New Roman'; font-size:7pt;\">\302\240\302\240\302\240\302\240 </span>Undo add, edit or delete action by clicking &quot;Undo&quot; butto"
                        "n.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Symbol';\">\302\267</span><span style=\" font-family:'Times New Roman'; font-size:7pt;\">\302\240\302\240\302\240\302\240 </span>Sort data by choosing the parameter in combo box by default stating \342\200\234Not Sorted\342\200\235. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Symbol';\">\302\267</span><span style=\" font-family:'Times New Roman'; font-size:7pt;\">\302\240\302\240\302\240\302\240 </span>Reverse the sort order by clicking small radio button to the left of the combo box. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Symbol';\">\302\267</span><span style=\" font-family:'Times New Roman'; font-size:7pt;\">\302\240"
                        "\302\240\302\240\302\240 </span>Sort by clicking on the column header </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Symbol';\">\302\267</span><span style=\" font-family:'Times New Roman'; font-size:7pt;\">\302\240\302\240\302\240\302\240 </span>Reverse the sort order by double-clicking on the same column header </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Symbol';\">\302\267</span><span style=\" font-family:'Times New Roman'; font-size:7pt;\">\302\240\302\240\302\240\302\240 </span>Filter the data based on any parameter via pressing on the \342\200\234Filter\342\200\235 button. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\302\240 </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-"
                        "bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:700;\">Author</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">Authored by DSBA student</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:700;\"> *Student1613*</span></p></body></html>", nullptr));
        logoButtonHelp->setText(QCoreApplication::translate("HelpWindow", "Logo", nullptr));
        languageHelpBox->setItemText(0, QCoreApplication::translate("HelpWindow", "English", nullptr));
        languageHelpBox->setItemText(1, QCoreApplication::translate("HelpWindow", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));

        okButtonHelp->setText(QCoreApplication::translate("HelpWindow", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpWindow: public Ui_HelpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
