/****************************************************************************
** Meta object code from reading C++ file 'CQRWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CQRWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CQRWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CQRWidget_t {
    QByteArrayData data[8];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CQRWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CQRWidget_t qt_meta_stringdata_CQRWidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CQRWidget"
QT_MOC_LITERAL(1, 10, 18), // "on_btnBack_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18), // "on_btnHome_clicked"
QT_MOC_LITERAL(4, 49, 15), // "on_slot_timeout"
QT_MOC_LITERAL(5, 65, 18), // "on_slot_SendResult"
QT_MOC_LITERAL(6, 84, 9), // "strResult"
QT_MOC_LITERAL(7, 94, 22) // "on_slot_OpendoorFinish"

    },
    "CQRWidget\0on_btnBack_clicked\0\0"
    "on_btnHome_clicked\0on_slot_timeout\0"
    "on_slot_SendResult\0strResult\0"
    "on_slot_OpendoorFinish"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CQRWidget[] = {

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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void CQRWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CQRWidget *_t = static_cast<CQRWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnBack_clicked(); break;
        case 1: _t->on_btnHome_clicked(); break;
        case 2: _t->on_slot_timeout(); break;
        case 3: _t->on_slot_SendResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_slot_OpendoorFinish(); break;
        default: ;
        }
    }
}

const QMetaObject CQRWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CQRWidget.data,
      qt_meta_data_CQRWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CQRWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CQRWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CQRWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::CQRWidget"))
        return static_cast< Ui::CQRWidget*>(this);
    return QDialog::qt_metacast(_clname);
}

int CQRWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
