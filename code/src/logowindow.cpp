#include "logowindow.h"
#include "ui_logowindow.h"
#include <QPainter>

LogoWindow::LogoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogoWindow)
{
    ui->setupUi(this);
    // You can add the logo in the .ui file or set it here programmatically
}

LogoWindow::~LogoWindow()
{
    delete ui;
}


void LogoWindow::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);

    int diameter = qMin(width(), height()) / 2;

    QPoint center = rect().center();
    QRect circleRect(center.x() - diameter / 2, center.y() - diameter / 2, diameter, diameter);

    painter.setBrush(QColor("orange")); // Let's paint it orange
    painter.drawEllipse(circleRect);
}
