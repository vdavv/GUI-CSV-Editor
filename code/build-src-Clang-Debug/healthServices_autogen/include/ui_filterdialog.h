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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FilterDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *state;
    QLineEdit *stateChoiceLineEdit;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *ratemdsMin;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLabel *rateMDs;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QLineEdit *ratemdsMax;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *numhospitalsMin;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *numHospitals;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_4;
    QLineEdit *numhospitalsMax;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *ratebedsMin;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_7;
    QLabel *rateBeds;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_7;
    QLineEdit *ratebedsMax;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *nummedicareMin;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_9;
    QLineEdit *nummedicareMax;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *pctchangemedicareMin;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_11;
    QLabel *pctChangeMedicare;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_11;
    QLineEdit *pctchangemedicareMax;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *medicarerateMin;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_13;
    QLabel *medicareRate;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_13;
    QLineEdit *medicarerateMax;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *numretiredMin;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_15;
    QLabel *numRetired;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_15;
    QLineEdit *numretiredMax;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *ssinumMin;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_17;
    QLabel *ssiNum;
    QSpacerItem *horizontalSpacer_18;
    QLabel *label_17;
    QLineEdit *ssinumMax;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *filterApplyButton;
    QPushButton *filterResetButton;

    void setupUi(QDialog *FilterDialog)
    {
        if (FilterDialog->objectName().isEmpty())
            FilterDialog->setObjectName("FilterDialog");
        FilterDialog->resize(500, 400);
        gridLayout = new QGridLayout(FilterDialog);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        state = new QLabel(FilterDialog);
        state->setObjectName("state");

        horizontalLayout->addWidget(state);

        stateChoiceLineEdit = new QLineEdit(FilterDialog);
        stateChoiceLineEdit->setObjectName("stateChoiceLineEdit");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stateChoiceLineEdit->sizePolicy().hasHeightForWidth());
        stateChoiceLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(stateChoiceLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        ratemdsMin = new QLineEdit(FilterDialog);
        ratemdsMin->setObjectName("ratemdsMin");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ratemdsMin->sizePolicy().hasHeightForWidth());
        ratemdsMin->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(ratemdsMin);

        label = new QLabel(FilterDialog);
        label->setObjectName("label");

        horizontalLayout_5->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        rateMDs = new QLabel(FilterDialog);
        rateMDs->setObjectName("rateMDs");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rateMDs->sizePolicy().hasHeightForWidth());
        rateMDs->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(rateMDs);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        label_2 = new QLabel(FilterDialog);
        label_2->setObjectName("label_2");

        horizontalLayout_5->addWidget(label_2);

        ratemdsMax = new QLineEdit(FilterDialog);
        ratemdsMax->setObjectName("ratemdsMax");
        sizePolicy1.setHeightForWidth(ratemdsMax->sizePolicy().hasHeightForWidth());
        ratemdsMax->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(ratemdsMax);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        numhospitalsMin = new QLineEdit(FilterDialog);
        numhospitalsMin->setObjectName("numhospitalsMin");
        sizePolicy1.setHeightForWidth(numhospitalsMin->sizePolicy().hasHeightForWidth());
        numhospitalsMin->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(numhospitalsMin);

        label_3 = new QLabel(FilterDialog);
        label_3->setObjectName("label_3");

        horizontalLayout_10->addWidget(label_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);

        numHospitals = new QLabel(FilterDialog);
        numHospitals->setObjectName("numHospitals");
        sizePolicy2.setHeightForWidth(numHospitals->sizePolicy().hasHeightForWidth());
        numHospitals->setSizePolicy(sizePolicy2);

        horizontalLayout_10->addWidget(numHospitals);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);

        label_4 = new QLabel(FilterDialog);
        label_4->setObjectName("label_4");

        horizontalLayout_10->addWidget(label_4);

        numhospitalsMax = new QLineEdit(FilterDialog);
        numhospitalsMax->setObjectName("numhospitalsMax");
        sizePolicy1.setHeightForWidth(numhospitalsMax->sizePolicy().hasHeightForWidth());
        numhospitalsMax->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(numhospitalsMax);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        ratebedsMin = new QLineEdit(FilterDialog);
        ratebedsMin->setObjectName("ratebedsMin");
        sizePolicy1.setHeightForWidth(ratebedsMin->sizePolicy().hasHeightForWidth());
        ratebedsMin->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(ratebedsMin);

        label_6 = new QLabel(FilterDialog);
        label_6->setObjectName("label_6");

        horizontalLayout_9->addWidget(label_6);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);

        rateBeds = new QLabel(FilterDialog);
        rateBeds->setObjectName("rateBeds");
        sizePolicy2.setHeightForWidth(rateBeds->sizePolicy().hasHeightForWidth());
        rateBeds->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(rateBeds);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        label_7 = new QLabel(FilterDialog);
        label_7->setObjectName("label_7");

        horizontalLayout_9->addWidget(label_7);

        ratebedsMax = new QLineEdit(FilterDialog);
        ratebedsMax->setObjectName("ratebedsMax");
        sizePolicy1.setHeightForWidth(ratebedsMax->sizePolicy().hasHeightForWidth());
        ratebedsMax->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(ratebedsMax);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        nummedicareMin = new QLineEdit(FilterDialog);
        nummedicareMin->setObjectName("nummedicareMin");
        sizePolicy1.setHeightForWidth(nummedicareMin->sizePolicy().hasHeightForWidth());
        nummedicareMin->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(nummedicareMin);

        label_8 = new QLabel(FilterDialog);
        label_8->setObjectName("label_8");

        horizontalLayout_8->addWidget(label_8);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        label_5 = new QLabel(FilterDialog);
        label_5->setObjectName("label_5");
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(label_5);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);

        label_9 = new QLabel(FilterDialog);
        label_9->setObjectName("label_9");

        horizontalLayout_8->addWidget(label_9);

        nummedicareMax = new QLineEdit(FilterDialog);
        nummedicareMax->setObjectName("nummedicareMax");
        sizePolicy1.setHeightForWidth(nummedicareMax->sizePolicy().hasHeightForWidth());
        nummedicareMax->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(nummedicareMax);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        pctchangemedicareMin = new QLineEdit(FilterDialog);
        pctchangemedicareMin->setObjectName("pctchangemedicareMin");
        sizePolicy1.setHeightForWidth(pctchangemedicareMin->sizePolicy().hasHeightForWidth());
        pctchangemedicareMin->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pctchangemedicareMin);

        label_10 = new QLabel(FilterDialog);
        label_10->setObjectName("label_10");

        horizontalLayout_7->addWidget(label_10);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);

        pctChangeMedicare = new QLabel(FilterDialog);
        pctChangeMedicare->setObjectName("pctChangeMedicare");
        sizePolicy2.setHeightForWidth(pctChangeMedicare->sizePolicy().hasHeightForWidth());
        pctChangeMedicare->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(pctChangeMedicare);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);

        label_11 = new QLabel(FilterDialog);
        label_11->setObjectName("label_11");

        horizontalLayout_7->addWidget(label_11);

        pctchangemedicareMax = new QLineEdit(FilterDialog);
        pctchangemedicareMax->setObjectName("pctchangemedicareMax");
        sizePolicy1.setHeightForWidth(pctchangemedicareMax->sizePolicy().hasHeightForWidth());
        pctchangemedicareMax->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pctchangemedicareMax);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        medicarerateMin = new QLineEdit(FilterDialog);
        medicarerateMin->setObjectName("medicarerateMin");
        sizePolicy1.setHeightForWidth(medicarerateMin->sizePolicy().hasHeightForWidth());
        medicarerateMin->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(medicarerateMin);

        label_12 = new QLabel(FilterDialog);
        label_12->setObjectName("label_12");

        horizontalLayout_6->addWidget(label_12);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_13);

        medicareRate = new QLabel(FilterDialog);
        medicareRate->setObjectName("medicareRate");
        sizePolicy2.setHeightForWidth(medicareRate->sizePolicy().hasHeightForWidth());
        medicareRate->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(medicareRate);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_14);

        label_13 = new QLabel(FilterDialog);
        label_13->setObjectName("label_13");

        horizontalLayout_6->addWidget(label_13);

        medicarerateMax = new QLineEdit(FilterDialog);
        medicarerateMax->setObjectName("medicarerateMax");
        sizePolicy1.setHeightForWidth(medicarerateMax->sizePolicy().hasHeightForWidth());
        medicarerateMax->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(medicarerateMax);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        numretiredMin = new QLineEdit(FilterDialog);
        numretiredMin->setObjectName("numretiredMin");
        sizePolicy1.setHeightForWidth(numretiredMin->sizePolicy().hasHeightForWidth());
        numretiredMin->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(numretiredMin);

        label_14 = new QLabel(FilterDialog);
        label_14->setObjectName("label_14");

        horizontalLayout_4->addWidget(label_14);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_15);

        numRetired = new QLabel(FilterDialog);
        numRetired->setObjectName("numRetired");
        sizePolicy2.setHeightForWidth(numRetired->sizePolicy().hasHeightForWidth());
        numRetired->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(numRetired);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_16);

        label_15 = new QLabel(FilterDialog);
        label_15->setObjectName("label_15");

        horizontalLayout_4->addWidget(label_15);

        numretiredMax = new QLineEdit(FilterDialog);
        numretiredMax->setObjectName("numretiredMax");
        sizePolicy1.setHeightForWidth(numretiredMax->sizePolicy().hasHeightForWidth());
        numretiredMax->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(numretiredMax);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        ssinumMin = new QLineEdit(FilterDialog);
        ssinumMin->setObjectName("ssinumMin");
        sizePolicy1.setHeightForWidth(ssinumMin->sizePolicy().hasHeightForWidth());
        ssinumMin->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(ssinumMin);

        label_16 = new QLabel(FilterDialog);
        label_16->setObjectName("label_16");

        horizontalLayout_3->addWidget(label_16);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_17);

        ssiNum = new QLabel(FilterDialog);
        ssiNum->setObjectName("ssiNum");
        sizePolicy2.setHeightForWidth(ssiNum->sizePolicy().hasHeightForWidth());
        ssiNum->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(ssiNum);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_18);

        label_17 = new QLabel(FilterDialog);
        label_17->setObjectName("label_17");

        horizontalLayout_3->addWidget(label_17);

        ssinumMax = new QLineEdit(FilterDialog);
        ssinumMax->setObjectName("ssinumMax");
        sizePolicy1.setHeightForWidth(ssinumMax->sizePolicy().hasHeightForWidth());
        ssinumMax->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(ssinumMax);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);

        filterApplyButton = new QPushButton(FilterDialog);
        filterApplyButton->setObjectName("filterApplyButton");

        horizontalLayout_11->addWidget(filterApplyButton);

        filterResetButton = new QPushButton(FilterDialog);
        filterResetButton->setObjectName("filterResetButton");

        horizontalLayout_11->addWidget(filterResetButton);


        verticalLayout->addLayout(horizontalLayout_11);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(FilterDialog);

        QMetaObject::connectSlotsByName(FilterDialog);
    } // setupUi

    void retranslateUi(QDialog *FilterDialog)
    {
        FilterDialog->setWindowTitle(QCoreApplication::translate("FilterDialog", "Filter", nullptr));
        state->setText(QCoreApplication::translate("FilterDialog", "State:", nullptr));
        label->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        rateMDs->setText(QCoreApplication::translate("FilterDialog", "RateMDs", nullptr));
        label_2->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        label_3->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        numHospitals->setText(QCoreApplication::translate("FilterDialog", "NumHospitals", nullptr));
        label_4->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        label_6->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        rateBeds->setText(QCoreApplication::translate("FilterDialog", "RateBeds", nullptr));
        label_7->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        label_8->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        label_5->setText(QCoreApplication::translate("FilterDialog", "NumMedicare", nullptr));
        label_9->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        label_10->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        pctChangeMedicare->setText(QCoreApplication::translate("FilterDialog", "PctChangeMedicare", nullptr));
        label_11->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        label_12->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        medicareRate->setText(QCoreApplication::translate("FilterDialog", "MedicareRate", nullptr));
        label_13->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        label_14->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        numRetired->setText(QCoreApplication::translate("FilterDialog", "NumRetired", nullptr));
        label_15->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        label_16->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        ssiNum->setText(QCoreApplication::translate("FilterDialog", "SSINum", nullptr));
        label_17->setText(QCoreApplication::translate("FilterDialog", "<", nullptr));
        filterApplyButton->setText(QCoreApplication::translate("FilterDialog", "Apply", nullptr));
        filterResetButton->setText(QCoreApplication::translate("FilterDialog", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterDialog: public Ui_FilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERDIALOG_H
