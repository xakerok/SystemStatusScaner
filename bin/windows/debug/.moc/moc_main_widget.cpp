/****************************************************************************
** Meta object code from reading C++ file 'main_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/include/gui/main_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CMainWindowWidget_t {
    QByteArrayData data[9];
    char stringdata[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMainWindowWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMainWindowWidget_t qt_meta_stringdata_CMainWindowWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CMainWindowWidget"
QT_MOC_LITERAL(1, 18, 9), // "on_undate"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "SDataValue*"
QT_MOC_LITERAL(4, 41, 9), // "dataValue"
QT_MOC_LITERAL(5, 51, 12), // "checkerGreen"
QT_MOC_LITERAL(6, 64, 13), // "checkerYellow"
QT_MOC_LITERAL(7, 78, 10), // "checkerRed"
QT_MOC_LITERAL(8, 89, 17) // "updateCurrentTime"

    },
    "CMainWindowWidget\0on_undate\0\0SDataValue*\0"
    "dataValue\0checkerGreen\0checkerYellow\0"
    "checkerRed\0updateCurrentTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMainWindowWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,
       7,    0,   44,    2, 0x0a /* Public */,
       8,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CMainWindowWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMainWindowWidget *_t = static_cast<CMainWindowWidget *>(_o);
        switch (_id) {
        case 0: _t->on_undate((*reinterpret_cast< SDataValue*(*)>(_a[1]))); break;
        case 1: _t->checkerGreen(); break;
        case 2: _t->checkerYellow(); break;
        case 3: _t->checkerRed(); break;
        case 4: _t->updateCurrentTime(); break;
        default: ;
        }
    }
}

const QMetaObject CMainWindowWidget::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CMainWindowWidget.data,
      qt_meta_data_CMainWindowWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CMainWindowWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMainWindowWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CMainWindowWidget.stringdata))
        return static_cast<void*>(const_cast< CMainWindowWidget*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CMainWindowWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
