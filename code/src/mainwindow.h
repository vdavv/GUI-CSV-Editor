#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemWatcher>
#include "csvmodel.h"
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *event) override;
    ~MainWindow();

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);
    void handleRowHeaderClicked(int row);
    void AddRow();
    void RemoveRow();
    void SaveCSV();
    void onFileChanged(const QString &path);

private:
    Ui::MainWindow *ui;
    CSVModel m_model;
    QFileSystemWatcher m_watcher;

};
#endif // MAINWINDOW_H
