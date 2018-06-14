/****************************************************************************
** Meta object code from reading C++ file 'frmcomtool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../frmcomtool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmcomtool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmComTool_t {
    QByteArrayData data[23];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmComTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmComTool_t qt_meta_stringdata_frmComTool = {
    {
QT_MOC_LITERAL(0, 0, 10), // "frmComTool"
QT_MOC_LITERAL(1, 11, 8), // "initForm"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "initConfig"
QT_MOC_LITERAL(4, 32, 10), // "saveConfig"
QT_MOC_LITERAL(5, 43, 8), // "readData"
QT_MOC_LITERAL(6, 52, 8), // "sendData"
QT_MOC_LITERAL(7, 61, 4), // "data"
QT_MOC_LITERAL(8, 66, 8), // "saveData"
QT_MOC_LITERAL(9, 75, 12), // "changeEnable"
QT_MOC_LITERAL(10, 88, 1), // "b"
QT_MOC_LITERAL(11, 90, 6), // "append"
QT_MOC_LITERAL(12, 97, 4), // "type"
QT_MOC_LITERAL(13, 102, 3), // "msg"
QT_MOC_LITERAL(14, 106, 14), // "InitQextSerial"
QT_MOC_LITERAL(15, 121, 18), // "on_btnOpen_clicked"
QT_MOC_LITERAL(16, 140, 22), // "on_btnStopShow_clicked"
QT_MOC_LITERAL(17, 163, 23), // "on_btnSendCount_clicked"
QT_MOC_LITERAL(18, 187, 26), // "on_btnReceiveCount_clicked"
QT_MOC_LITERAL(19, 214, 19), // "on_btnClear_clicked"
QT_MOC_LITERAL(20, 234, 18), // "on_btnData_clicked"
QT_MOC_LITERAL(21, 253, 26), // "on_ckAutoSave_stateChanged"
QT_MOC_LITERAL(22, 280, 4) // "arg1"

    },
    "frmComTool\0initForm\0\0initConfig\0"
    "saveConfig\0readData\0sendData\0data\0"
    "saveData\0changeEnable\0b\0append\0type\0"
    "msg\0InitQextSerial\0on_btnOpen_clicked\0"
    "on_btnStopShow_clicked\0on_btnSendCount_clicked\0"
    "on_btnReceiveCount_clicked\0"
    "on_btnClear_clicked\0on_btnData_clicked\0"
    "on_ckAutoSave_stateChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmComTool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       6,    1,  104,    2, 0x08 /* Private */,
       8,    0,  107,    2, 0x08 /* Private */,
       9,    1,  108,    2, 0x08 /* Private */,
      11,    2,  111,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,
      20,    0,  122,    2, 0x08 /* Private */,
      21,    1,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::UChar, QMetaType::QString,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,

       0        // eod
};

void frmComTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        frmComTool *_t = static_cast<frmComTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initForm(); break;
        case 1: _t->initConfig(); break;
        case 2: _t->saveConfig(); break;
        case 3: _t->readData(); break;
        case 4: _t->sendData(); break;
        case 5: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->saveData(); break;
        case 7: _t->changeEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->append((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->InitQextSerial(); break;
        case 10: _t->on_btnOpen_clicked(); break;
        case 11: _t->on_btnStopShow_clicked(); break;
        case 12: _t->on_btnSendCount_clicked(); break;
        case 13: _t->on_btnReceiveCount_clicked(); break;
        case 14: _t->on_btnClear_clicked(); break;
        case 15: _t->on_btnData_clicked(); break;
        case 16: _t->on_ckAutoSave_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject frmComTool::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_frmComTool.data,
      qt_meta_data_frmComTool,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *frmComTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmComTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmComTool.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::frmComTool"))
        return static_cast< Ui::frmComTool*>(this);
    return QWidget::qt_metacast(_clname);
}

int frmComTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
