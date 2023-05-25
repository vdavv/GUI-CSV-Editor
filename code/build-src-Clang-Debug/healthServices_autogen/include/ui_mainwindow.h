/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *saveButton;
    QPushButton *helpButton;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *orderButton;
    QComboBox *sortBox;
    QPushButton *filterButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *editRowButton;
    QPushButton *addRowButton;
    QPushButton *removeRowButton;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(970, 650);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        undoButton = new QPushButton(centralwidget);
        undoButton->setObjectName("undoButton");

        horizontalLayout_2->addWidget(undoButton);

        redoButton = new QPushButton(centralwidget);
        redoButton->setObjectName("redoButton");

        horizontalLayout_2->addWidget(redoButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");

        horizontalLayout_2->addWidget(saveButton);

        helpButton = new QPushButton(centralwidget);
        helpButton->setObjectName("helpButton");

        horizontalLayout_2->addWidget(helpButton);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
#ifndef Q_OS_MAC
        verticalLayout_3->setSpacing(-1);
#endif
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        orderButton = new QRadioButton(centralwidget);
        orderButton->setObjectName("orderButton");

        horizontalLayout_3->addWidget(orderButton);

        sortBox = new QComboBox(centralwidget);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("view-fullscreen");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        sortBox->addItem(icon, QString());
        sortBox->addItem(QString());
        sortBox->addItem(QString());
        sortBox->setObjectName("sortBox");
        sortBox->setFrame(true);

        horizontalLayout_3->addWidget(sortBox);

        filterButton = new QPushButton(centralwidget);
        filterButton->setObjectName("filterButton");

        horizontalLayout_3->addWidget(filterButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        editRowButton = new QPushButton(centralwidget);
        editRowButton->setObjectName("editRowButton");

        horizontalLayout_3->addWidget(editRowButton);

        addRowButton = new QPushButton(centralwidget);
        addRowButton->setObjectName("addRowButton");

        horizontalLayout_3->addWidget(addRowButton);

        removeRowButton = new QPushButton(centralwidget);
        removeRowButton->setObjectName("removeRowButton");

        horizontalLayout_3->addWidget(removeRowButton);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_3, 3, 0, 1, 1);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(tableView, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 970, 37));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        undoButton->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        redoButton->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        helpButton->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        orderButton->setText(QString());
        sortBox->setItemText(0, QCoreApplication::translate("MainWindow", "Not Sorted", nullptr));
        sortBox->setItemText(1, QCoreApplication::translate("MainWindow", "NumMDS", nullptr));
        sortBox->setItemText(2, QCoreApplication::translate("MainWindow", "RateMDS", nullptr));

        filterButton->setText(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        editRowButton->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        addRowButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removeRowButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
