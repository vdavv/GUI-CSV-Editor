#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "csvmodel.h"
#include <QMainWindow>
#include <QFileSystemWatcher>
#include <QList>
#include <QSortFilterProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    static const QVector<int> CSVCOLUMNS; // = {0,1,2,3,4,5,6,7,8,9};
    static const QString FILEPATH; // = "/Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/data/MetroHealth83.csv";

public:
    explicit MainWindow(QWidget *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *event) override;
    ~MainWindow();

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);
    void handleRowHeaderClicked(int row);

    void AddRow();
    void RemoveRow();
    void EditRow();
    void SaveCSV();

    void onFileChanged(const QString &path);

    void openHelpWindow();
    void openFilterDialog();

    void onSortBoxChanged(int index);
    void onHeaderSectionClicked(int logicalIndex);
    void sort(int column, bool ascending);


public slots:
    void ReloadCSV();

private:
    Ui::MainWindow *ui;
    CSVModel m_model;
    QFileSystemWatcher m_watcher;
    QSortFilterProxyModel *m_proxyModel;
    int m_lastClickedSection = -1;


};
#endif // MAINWINDOW_H
