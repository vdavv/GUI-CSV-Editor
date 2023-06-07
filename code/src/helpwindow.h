#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QDialog>
#include "ui_helpwindow.h"
#include "logowindow.h"

namespace Ui {
class HelpWindow;
}

class HelpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HelpWindow(QWidget *parent = nullptr);
    ~HelpWindow();


private slots:
    void on_okButtonHelp_clicked();
    void on_logoButtonHelp_clicked();
    void onLanguageBoxChanged(int index);


private:
    Ui::HelpWindow *ui;
    LogoWindow *logoWindow;
};

#endif // HELPWINDOW_H
