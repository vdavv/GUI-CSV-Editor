/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_tableView_doubleClicked",
    "",
    "QModelIndex",
    "index",
    "handleRowHeaderClicked",
    "row",
    "AddRow",
    "RemoveRow",
    "EditRow",
    "SaveCSV",
    "onFileChanged",
    "path",
    "openHelpWindow",
    "onSortBoxChanged",
    "onHeaderSectionClicked",
    "logicalIndex",
    "sort",
    "column",
    "ascending",
    "ReloadCSV"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[42];
    char stringdata0[11];
    char stringdata1[27];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[6];
    char stringdata5[23];
    char stringdata6[4];
    char stringdata7[7];
    char stringdata8[10];
    char stringdata9[8];
    char stringdata10[8];
    char stringdata11[14];
    char stringdata12[5];
    char stringdata13[15];
    char stringdata14[17];
    char stringdata15[23];
    char stringdata16[13];
    char stringdata17[5];
    char stringdata18[7];
    char stringdata19[10];
    char stringdata20[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 26),  // "on_tableView_doubleClicked"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 11),  // "QModelIndex"
        QT_MOC_LITERAL(51, 5),  // "index"
        QT_MOC_LITERAL(57, 22),  // "handleRowHeaderClicked"
        QT_MOC_LITERAL(80, 3),  // "row"
        QT_MOC_LITERAL(84, 6),  // "AddRow"
        QT_MOC_LITERAL(91, 9),  // "RemoveRow"
        QT_MOC_LITERAL(101, 7),  // "EditRow"
        QT_MOC_LITERAL(109, 7),  // "SaveCSV"
        QT_MOC_LITERAL(117, 13),  // "onFileChanged"
        QT_MOC_LITERAL(131, 4),  // "path"
        QT_MOC_LITERAL(136, 14),  // "openHelpWindow"
        QT_MOC_LITERAL(151, 16),  // "onSortBoxChanged"
        QT_MOC_LITERAL(168, 22),  // "onHeaderSectionClicked"
        QT_MOC_LITERAL(191, 12),  // "logicalIndex"
        QT_MOC_LITERAL(204, 4),  // "sort"
        QT_MOC_LITERAL(209, 6),  // "column"
        QT_MOC_LITERAL(216, 9),  // "ascending"
        QT_MOC_LITERAL(226, 9)   // "ReloadCSV"
    },
    "MainWindow",
    "on_tableView_doubleClicked",
    "",
    "QModelIndex",
    "index",
    "handleRowHeaderClicked",
    "row",
    "AddRow",
    "RemoveRow",
    "EditRow",
    "SaveCSV",
    "onFileChanged",
    "path",
    "openHelpWindow",
    "onSortBoxChanged",
    "onHeaderSectionClicked",
    "logicalIndex",
    "sort",
    "column",
    "ascending",
    "ReloadCSV"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x08,    1 /* Private */,
       5,    1,   89,    2, 0x08,    3 /* Private */,
       7,    0,   92,    2, 0x08,    5 /* Private */,
       8,    0,   93,    2, 0x08,    6 /* Private */,
       9,    0,   94,    2, 0x08,    7 /* Private */,
      10,    0,   95,    2, 0x08,    8 /* Private */,
      11,    1,   96,    2, 0x08,    9 /* Private */,
      13,    0,   99,    2, 0x08,   11 /* Private */,
      14,    1,  100,    2, 0x08,   12 /* Private */,
      15,    1,  103,    2, 0x08,   14 /* Private */,
      17,    2,  106,    2, 0x08,   16 /* Private */,
      20,    0,  111,    2, 0x0a,   19 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   18,   19,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_tableView_doubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'handleRowHeaderClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'AddRow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RemoveRow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'EditRow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SaveCSV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFileChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'openHelpWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSortBoxChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onHeaderSectionClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'ReloadCSV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_tableView_doubleClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 1: _t->handleRowHeaderClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->AddRow(); break;
        case 3: _t->RemoveRow(); break;
        case 4: _t->EditRow(); break;
        case 5: _t->SaveCSV(); break;
        case 6: _t->onFileChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->openHelpWindow(); break;
        case 8: _t->onSortBoxChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->onHeaderSectionClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->sort((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 11: _t->ReloadCSV(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
