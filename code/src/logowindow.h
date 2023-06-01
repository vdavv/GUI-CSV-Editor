#ifndef LOGOWINDOW_H
#define LOGOWINDOW_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class LogoWindow;
}

class LogoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LogoWindow(QWidget *parent = nullptr);
    ~LogoWindow();
    void paintEvent(QPaintEvent * /* event */);

private:
    Ui::LogoWindow *ui;
};

#endif // LOGOWINDOW_H
