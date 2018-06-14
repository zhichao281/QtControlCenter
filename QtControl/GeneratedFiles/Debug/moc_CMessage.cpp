/****************************************************************************
** Meta object code from reading C++ file 'CMessage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CMessage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CMessage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMessage_t {
    QByteArrayData data[13];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMessage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMessage_t qt_meta_stringdata_CMessage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CMessage"
QT_MOC_LITERAL(1, 9, 18), // "on_btnBack_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 18), // "on_btnHome_clicked"
QT_MOC_LITERAL(4, 48, 16), // "on_btnOk_clicked"
QT_MOC_LITERAL(5, 65, 20), // "on_btnReturn_clicked"
QT_MOC_LITERAL(6, 86, 15), // "on_slot_timeout"
QT_MOC_LITERAL(7, 102, 11), // "MSGBOX_TYPE"
QT_MOC_LITERAL(8, 114, 15), // "MSGBOX_WAITSAVE"
QT_MOC_LITERAL(9, 130, 14), // "MSGBOX_WAITGET"
QT_MOC_LITERAL(10, 145, 14), // "MSGBOX_SAVEEND"
QT_MOC_LITERAL(11, 160, 13), // "MSGBOX_GETEND"
QT_MOC_LITERAL(12, 174, 12) // "MSGBOX_CLOSE"

    },
    "CMessage\0on_btnBack_clicked\0\0"
    "on_btnHome_clicked\0on_btnOk_clicked\0"
    "on_btnReturn_clicked\0on_slot_timeout\0"
    "MSGBOX_TYPE\0MSGBOX_WAITSAVE\0MSGBOX_WAITGET\0"
    "MSGBOX_SAVEEND\0MSGBOX_GETEND\0MSGBOX_CLOSE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMessage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       1,   44, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // enums: name, flags, count, data
       7, 0x1,    5,   48,

 // enum data: key, value
       8, uint(CMessage::MSGBOX_WAITSAVE),
       9, uint(CMessage::MSGBOX_WAITGET),
      10, uint(CMessage::MSGBOX_SAVEEND),
      11, uint(CMessage::MSGBOX_GETEND),
      12, uint(CMessage::MSGBOX_CLOSE),

       0        // eod
};

void CMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMessage *_t = static_cast<CMessage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnBack_clicked(); break;
        case 1: _t->on_btnHome_clicked(); break;
        case 2: _t->on_btnOk_clicked(); break;
        case 3: _t->on_btnReturn_clicked(); break;
        case 4: _t->on_slot_timeout(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CMessage::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CMessage.data,
      qt_meta_data_CMessage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMessage.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::CMessage"))
        return static_cast< Ui::CMessage*>(this);
    return QDialog::qt_metacast(_clname);
}

int CMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
