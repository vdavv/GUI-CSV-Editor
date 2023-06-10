#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include "logowindow.h"
#include "ui_helpwindow.h"
#include <QDialog>

namespace Ui
{
class HelpWindow;
}

class HelpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HelpWindow(QWidget* parent = nullptr);
    int lang = 0;
    ~HelpWindow();


public slots:
    void translateUi(int lang);


signals:
    void languageChanged(int index);


private slots:
    void on_okButtonHelp_clicked();
    void on_logoButtonHelp_clicked();
    void onLanguageBoxChanged(int index);


private:
    Ui::HelpWindow* ui;
    LogoWindow* logoWindow;
};

#endif// HELPWINDOW_H
