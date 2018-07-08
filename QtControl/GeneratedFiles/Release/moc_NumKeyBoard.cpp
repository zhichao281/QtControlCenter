/****************************************************************************
** Meta object code from reading C++ file 'NumKeyBoard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../NumKeyBoard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NumKeyBoard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NumKeyBoard_t {
    QByteArrayData data[10];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NumKeyBoard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NumKeyBoard_t qt_meta_stringdata_NumKeyBoard = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NumKeyBoard"
QT_MOC_LITERAL(1, 12, 11), // "setDispText"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "text"
QT_MOC_LITERAL(4, 30, 7), // "onEnter"
QT_MOC_LITERAL(5, 38, 11), // "onBackspace"
QT_MOC_LITERAL(6, 50, 9), // "onInvMode"
QT_MOC_LITERAL(7, 60, 19), // "on_slot_textChanged"
QT_MOC_LITERAL(8, 80, 18), // "on_btnBack_clicked"
QT_MOC_LITERAL(9, 99, 18) // "on_btnHome_clicked"

    },
    "NumKeyBoard\0setDispText\0\0text\0onEnter\0"
    "onBackspace\0onInvMode\0on_slot_textChanged\0"
    "on_btnBack_clicked\0on_btnHome_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NumKeyBoard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    0,   52,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    1,   55,    2, 0x08 /* Private */,
       8,    0,   58,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NumKeyBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NumKeyBoard *_t = static_cast<NumKeyBoard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setDispText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onEnter(); break;
        case 2: _t->onBackspace(); break;
        case 3: _t->onInvMode(); break;
        case 4: _t->on_slot_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_btnBack_clicked(); break;
        case 6: _t->on_btnHome_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject NumKeyBoard::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NumKeyBoard.data,
      qt_meta_data_NumKeyBoard,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *NumKeyBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NumKeyBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NumKeyBoard.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::NumKeyBoard"))
        return static_cast< Ui::NumKeyBoard*>(this);
    return QDialog::qt_metacast(_clname);
}

int NumKeyBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
