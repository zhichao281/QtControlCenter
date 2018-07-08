/****************************************************************************
** Meta object code from reading C++ file 'QtControl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CMainWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtControl_t {
    QByteArrayData data[7];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtControl_t qt_meta_stringdata_QtControl = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QtControl"
QT_MOC_LITERAL(1, 10, 19), // "displayInputContent"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "text"
QT_MOC_LITERAL(4, 36, 11), // "on_slot_Get"
QT_MOC_LITERAL(5, 48, 12), // "on_slot_Save"
QT_MOC_LITERAL(6, 61, 15) // "on_slot_setting"

    },
    "QtControl\0displayInputContent\0\0text\0"
    "on_slot_Get\0on_slot_Save\0on_slot_setting"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CMainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMainWidget *_t = static_cast<CMainWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->displayInputContent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_slot_Get(); break;
        case 2: _t->on_slot_Save(); break;
        case 3: _t->on_slot_setting(); break;
        default: ;
        }
    }
}

const QMetaObject CMainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QtControl.data,
      qt_meta_data_QtControl,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CMainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtControl.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::QtControlClass"))
        return static_cast< Ui::QtControlClass*>(this);
    return QWidget::qt_metacast(_clname);
}

int CMainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
