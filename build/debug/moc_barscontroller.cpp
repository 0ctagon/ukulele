/****************************************************************************
** Meta object code from reading C++ file 'barscontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../uku/barscontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'barscontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BarsController_t {
    QByteArrayData data[13];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BarsController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BarsController_t qt_meta_stringdata_BarsController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "BarsController"
QT_MOC_LITERAL(1, 15, 10), // "barChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "chordsFound"
QT_MOC_LITERAL(4, 39, 14), // "chordsNotFound"
QT_MOC_LITERAL(5, 54, 9), // "checkBars"
QT_MOC_LITERAL(6, 64, 11), // "checkChords"
QT_MOC_LITERAL(7, 76, 7), // "unCheck"
QT_MOC_LITERAL(8, 84, 8), // "saveBars"
QT_MOC_LITERAL(9, 93, 11), // "std::string"
QT_MOC_LITERAL(10, 105, 4), // "name"
QT_MOC_LITERAL(11, 110, 12), // "setBarsValue"
QT_MOC_LITERAL(12, 123, 1) // "i"

    },
    "BarsController\0barChanged\0\0chordsFound\0"
    "chordsNotFound\0checkBars\0checkChords\0"
    "unCheck\0saveBars\0std::string\0name\0"
    "setBarsValue\0i"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BarsController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    1,   60,    2, 0x0a /* Public */,
      11,    2,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,   10,   12,

       0        // eod
};

void BarsController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BarsController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->barChanged(); break;
        case 1: _t->chordsFound(); break;
        case 2: _t->chordsNotFound(); break;
        case 3: _t->checkBars(); break;
        case 4: _t->checkChords(); break;
        case 5: _t->unCheck(); break;
        case 6: _t->saveBars((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 7: _t->setBarsValue((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BarsController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BarsController::barChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BarsController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BarsController::chordsFound)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BarsController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BarsController::chordsNotFound)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BarsController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_BarsController.data,
    qt_meta_data_BarsController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BarsController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BarsController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BarsController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BarsController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void BarsController::barChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BarsController::chordsFound()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BarsController::chordsNotFound()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
