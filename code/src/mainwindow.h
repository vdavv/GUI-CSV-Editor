#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "csvmodel.h"
#include <QMainWindow>
#include <QFileSystemWatcher>
#include <QList>
#include <QSortFilterProxyModel>
#include <QUndoStack>
#include "csvfiltermodel.h"
#include "filterdialog.h"
#include "csvitemdelegate.h"
#include "logowindow.h"
#include "helpwindow.h"


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
    void openFilterDialog();
    ~MainWindow();

private slots:
    void on_undoButton_clicked();
    void on_logoButton_clicked();
    void handleRowHeaderClicked(int row);

    void AddRow();
    void RemoveRow();
    void EditRow();
    void SaveCSV();

    void onFileChanged(const QString &path);
    void applyFilter();

    void openHelpWindow();

    void onSortBoxChanged(int index);
    void onHeaderSectionClicked(int logicalIndex);
    void sort(int column, bool ascending);


public slots:
    void ReloadCSV();
    void translateUi(int lang);

private:
    Ui::MainWindow *ui;
    CSVModel model;
    QFileSystemWatcher watcher;
    QSortFilterProxyModel *proxyModel;
    int lastClickedSection = -1;
    CSVFilterModel filterModel;
    FilterDialog *filterDialog;
    HelpWindow *helpWindow;
    LogoWindow *logoWindow = nullptr;
    QUndoStack *undoStack;
    CSVItemDelegate *delegate;


};
#endif // MAINWINDOW_H
