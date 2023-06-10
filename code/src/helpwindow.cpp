#include "helpwindow.h"
#include "ui_helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    logoWindow = nullptr; // initialize logoWindow to nullptr

    connect(ui->okButtonHelp, &QPushButton::clicked, this, &HelpWindow::on_okButtonHelp_clicked);
    connect(ui->logoButtonHelp, &QPushButton::clicked, this, &HelpWindow::on_logoButtonHelp_clicked);
    connect(ui->languageHelpBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onLanguageBoxChanged(int)));
}


HelpWindow::~HelpWindow()
{
    delete ui;
}


void HelpWindow::on_okButtonHelp_clicked()
{
    this->close();
}


void HelpWindow::on_logoButtonHelp_clicked()
{
    // Check if the logoWindow is already open
    if(logoWindow == nullptr)
    {
        logoWindow = new LogoWindow(this);
        logoWindow->setAttribute(Qt::WA_DeleteOnClose); // Set the attribute so that the window is deleted when it's closed
        logoWindow->show();

        // Connect the logoWindow's close signal to a lambda function that sets logoWindow to nullptr
        connect(logoWindow, &QWidget::destroyed, [this]() {
            this->logoWindow = nullptr;
        });
    }
}


void HelpWindow::onLanguageBoxChanged(int index)
{
    // index 0 = English (default)
    // index 1 = Russian (optional)
    emit languageChanged(index);
}
