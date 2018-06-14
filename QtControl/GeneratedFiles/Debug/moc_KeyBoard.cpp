/****************************************************************************
** Meta object code from reading C++ file 'KeyBoard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../KeyBoard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KeyBoard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KeyBoard_t {
    QByteArrayData data[13];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KeyBoard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KeyBoard_t qt_meta_stringdata_KeyBoard = {
    {
QT_MOC_LITERAL(0, 0, 8), // "KeyBoard"
QT_MOC_LITERAL(1, 9, 8), // "setvalue"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "text"
QT_MOC_LITERAL(4, 24, 11), // "setDispText"
QT_MOC_LITERAL(5, 36, 7), // "onEnter"
QT_MOC_LITERAL(6, 44, 11), // "onBackspace"
QT_MOC_LITERAL(7, 56, 13), // "onCursorRight"
QT_MOC_LITERAL(8, 70, 12), // "onCursorLeft"
QT_MOC_LITERAL(9, 83, 10), // "onCursorUp"
QT_MOC_LITERAL(10, 94, 12), // "onCursorDown"
QT_MOC_LITERAL(11, 107, 9), // "onInvMode"
QT_MOC_LITERAL(12, 117, 10) // "onCapslock"

    },
    "KeyBoard\0setvalue\0\0text\0setDispText\0"
    "onEnter\0onBackspace\0onCursorRight\0"
    "onCursorLeft\0onCursorUp\0onCursorDown\0"
    "onInvMode\0onCapslock"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KeyBoard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   67,    2, 0x08 /* Private */,
       5,    0,   70,    2, 0x08 /* Private */,
       6,    0,   71,    2, 0x08 /* Private */,
       7,    0,   72,    2, 0x08 /* Private */,
       8,    0,   73,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void KeyBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KeyBoard *_t = static_cast<KeyBoard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setvalue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setDispText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onEnter(); break;
        case 3: _t->onBackspace(); break;
        case 4: _t->onCursorRight(); break;
        case 5: _t->onCursorLeft(); break;
        case 6: _t->onCursorUp(); break;
        case 7: _t->onCursorDown(); break;
        case 8: _t->onInvMode(); break;
        case 9: _t->onCapslock(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KeyBoard::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KeyBoard::setvalue)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject KeyBoard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_KeyBoard.data,
      qt_meta_data_KeyBoard,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *KeyBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KeyBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KeyBoard.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int KeyBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void KeyBoard::setvalue(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
