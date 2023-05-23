#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractTableModel>
#include "csvmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QTableView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *event) override;
    ~MainWindow();


private slots:
    // void on_tableView_doubleClicked(const QModelIndex &index);
    void handleRowHeaderClicked(int row);


private:
    Ui::MainWindow *ui;
    CSVModel m_model;
    QTableView *m_view;

};
#endif // MAINWINDOW_H
