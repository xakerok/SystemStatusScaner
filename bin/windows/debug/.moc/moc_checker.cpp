/****************************************************************************
** Meta object code from reading C++ file 'checker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/include/core/checker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'checker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CChecker_t {
    QByteArrayData data[6];
    char stringdata[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CChecker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CChecker_t qt_meta_stringdata_CChecker = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CChecker"
QT_MOC_LITERAL(1, 9, 10), // "alertGreen"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "alertYellow"
QT_MOC_LITERAL(4, 33, 8), // "alertRed"
QT_MOC_LITERAL(5, 42, 8) // "on_check"

    },
    "CChecker\0alertGreen\0\0alertYellow\0"
    "alertRed\0on_check"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CChecker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CChecker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CChecker *_t = static_cast<CChecker *>(_o);
        switch (_id) {
        case 0: _t->alertGreen(); break;
        case 1: _t->alertYellow(); break;
        case 2: _t->alertRed(); break;
        case 3: _t->on_check(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CChecker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CChecker::alertGreen)) {
                *result = 0;
            }
        }
        {
            typedef void (CChecker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CChecker::alertYellow)) {
                *result = 1;
            }
        }
        {
            typedef void (CChecker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CChecker::alertRed)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CChecker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CChecker.data,
      qt_meta_data_CChecker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CChecker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CChecker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CChecker.stringdata))
        return static_cast<void*>(const_cast< CChecker*>(this));
    return QObject::qt_metacast(_clname);
}

int CChecker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CChecker::alertGreen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CChecker::alertYellow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CChecker::alertRed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
