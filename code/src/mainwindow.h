#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "csvfiltermodel.h"
#include "csvitemdelegate.h"
#include "csvmodel.h"
#include "filterdialog.h"
#include "helpwindow.h"
#include "logowindow.h"
#include <QFileSystemWatcher>
#include <QList>
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QUndoStack>


QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    static const QVector<int> CSVCOLUMNS;
    static const QString FILEPATH;
    int lang = 0;

public:
    explicit MainWindow(QWidget* parent = nullptr);
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
    void onFileChanged(const QString& path);

    void applyFilter();
    void openHelpWindow();
    void onSortBoxChanged(int index);
    void onHeaderSectionClicked(int logicalIndex);
    void sort(int column, bool ascending);


public slots:
    void ReloadCSV();
    void translateUi(int lang);

private:
    Ui::MainWindow* ui;
    CSVModel model;
    QFileSystemWatcher watcher;
    int lastClickedSection = -1;
    CSVFilterModel filterModel;
    FilterDialog* filterDialog;
    HelpWindow* helpWindow;
    LogoWindow* logoWindow = nullptr;
    QUndoStack* undoStack;
    CSVItemDelegate* delegate;
};

#endif// MAINWINDOW_H
