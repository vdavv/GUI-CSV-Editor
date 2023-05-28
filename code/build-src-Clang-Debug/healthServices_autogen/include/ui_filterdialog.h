/********************************************************************************
** Form generated from reading UI file 'filterdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERDIALOG_H
#define UI_FILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FilterDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QComboBox *comboBox_3;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEdit_3;
    QComboBox *comboBox_4;
    QLabel *label_3;
    QComboBox *comboBox_5;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *lineEdit_5;
    QComboBox *comboBox_6;
    QLabel *label_4;
    QComboBox *comboBox_7;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;

    void setupUi(QDialog *FilterDialog)
    {
        if (FilterDialog->objectName().isEmpty())
            FilterDialog->setObjectName("FilterDialog");
        FilterDialog->resize(400, 600);
        gridLayout = new QGridLayout(FilterDialog);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(FilterDialog);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(FilterDialog);
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        lineEdit = new QLineEdit(FilterDialog);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_5->addWidget(lineEdit);

        comboBox_2 = new QComboBox(FilterDialog);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(comboBox_2);

        label_2 = new QLabel(FilterDialog);
        label_2->setObjectName("label_2");

        horizontalLayout_5->addWidget(label_2);

        comboBox_3 = new QComboBox(FilterDialog);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        sizePolicy.setHeightForWidth(comboBox_3->sizePolicy().hasHeightForWidth());
        comboBox_3->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(comboBox_3);

        lineEdit_2 = new QLineEdit(FilterDialog);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_5->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        lineEdit_3 = new QLineEdit(FilterDialog);
        lineEdit_3->setObjectName("lineEdit_3");

        horizontalLayout_10->addWidget(lineEdit_3);

        comboBox_4 = new QComboBox(FilterDialog);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        sizePolicy.setHeightForWidth(comboBox_4->sizePolicy().hasHeightForWidth());
        comboBox_4->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(comboBox_4);

        label_3 = new QLabel(FilterDialog);
        label_3->setObjectName("label_3");

        horizontalLayout_10->addWidget(label_3);

        comboBox_5 = new QComboBox(FilterDialog);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName("comboBox_5");
        sizePolicy.setHeightForWidth(comboBox_5->sizePolicy().hasHeightForWidth());
        comboBox_5->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(comboBox_5);

        lineEdit_4 = new QLineEdit(FilterDialog);
        lineEdit_4->setObjectName("lineEdit_4");

        horizontalLayout_10->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        lineEdit_5 = new QLineEdit(FilterDialog);
        lineEdit_5->setObjectName("lineEdit_5");

        horizontalLayout_9->addWidget(lineEdit_5);

        comboBox_6 = new QComboBox(FilterDialog);
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->setObjectName("comboBox_6");
        sizePolicy.setHeightForWidth(comboBox_6->sizePolicy().hasHeightForWidth());
        comboBox_6->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(comboBox_6);

        label_4 = new QLabel(FilterDialog);
        label_4->setObjectName("label_4");

        horizontalLayout_9->addWidget(label_4);

        comboBox_7 = new QComboBox(FilterDialog);
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName("comboBox_7");

        horizontalLayout_9->addWidget(comboBox_7);

        lineEdit_6 = new QLineEdit(FilterDialog);
        lineEdit_6->setObjectName("lineEdit_6");

        horizontalLayout_9->addWidget(lineEdit_6);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");

        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");

        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");

        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");

        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(FilterDialog);

        QMetaObject::connectSlotsByName(FilterDialog);
    } // setupUi

    void retranslateUi(QDialog *FilterDialog)
    {
        FilterDialog->setWindowTitle(QCoreApplication::translate("FilterDialog", "Filter", nullptr));
        label->setText(QCoreApplication::translate("FilterDialog", "State:", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("FilterDialog", "<", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("FilterDialog", "\342\211\244", nullptr));

        label_2->setText(QCoreApplication::translate("FilterDialog", "RateMDs", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("FilterDialog", "<", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("FilterDialog", "\342\211\244", nullptr));

        comboBox_4->setItemText(0, QCoreApplication::translate("FilterDialog", "<", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("FilterDialog", "\342\211\244", nullptr));

        label_3->setText(QCoreApplication::translate("FilterDialog", "NumHospitals", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("FilterDialog", "<", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("FilterDialog", "\342\211\244", nullptr));

        comboBox_6->setItemText(0, QCoreApplication::translate("FilterDialog", "<", nullptr));
        comboBox_6->setItemText(1, QCoreApplication::translate("FilterDialog", "\342\211\244", nullptr));

        label_4->setText(QCoreApplication::translate("FilterDialog", "RateBeds", nullptr));
        comboBox_7->setItemText(0, QCoreApplication::translate("FilterDialog", "<", nullptr));
        comboBox_7->setItemText(1, QCoreApplication::translate("FilterDialog", "\342\211\244", nullptr));

    } // retranslateUi

};

namespace Ui {
    class FilterDialog: public Ui_FilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERDIALOG_H
