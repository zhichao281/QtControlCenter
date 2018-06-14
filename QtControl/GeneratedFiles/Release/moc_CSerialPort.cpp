/****************************************************************************
** Meta object code from reading C++ file 'CSerialPort.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CSerialPort.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CSerialPort.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CSerialPort_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSerialPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSerialPort_t qt_meta_stringdata_CSerialPort = {
    {
QT_MOC_LITERAL(0, 0, 11) // "CSerialPort"

    },
    "CSerialPort"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSerialPort[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CSerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject CSerialPort::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CSerialPort.data,
      qt_meta_data_CSerialPort,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CSerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CSerialPort.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CSerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_CSerialPort_232_t {
    QByteArrayData data[9];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSerialPort_232_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSerialPort_232_t qt_meta_stringdata_CSerialPort_232 = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CSerialPort_232"
QT_MOC_LITERAL(1, 16, 12), // "sig_ReadData"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "strData"
QT_MOC_LITERAL(4, 38, 8), // "readData"
QT_MOC_LITERAL(5, 47, 12), // "QextreadData"
QT_MOC_LITERAL(6, 60, 8), // "sendData"
QT_MOC_LITERAL(7, 69, 4), // "data"
QT_MOC_LITERAL(8, 74, 12) // "QextsendData"

    },
    "CSerialPort_232\0sig_ReadData\0\0strData\0"
    "readData\0QextreadData\0sendData\0data\0"
    "QextsendData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSerialPort_232[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    1,   44,    2, 0x08 /* Private */,
       8,    1,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void CSerialPort_232::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSerialPort_232 *_t = static_cast<CSerialPort_232 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_ReadData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->readData(); break;
        case 2: _t->QextreadData(); break;
        case 3: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->QextsendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CSerialPort_232::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSerialPort_232::sig_ReadData)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CSerialPort_232::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CSerialPort_232.data,
      qt_meta_data_CSerialPort_232,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CSerialPort_232::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSerialPort_232::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CSerialPort_232.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CSerialPort_232::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void CSerialPort_232::sig_ReadData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CSerialPort_485_t {
    QByteArrayData data[7];
    char stringdata0[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSerialPort_485_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSerialPort_485_t qt_meta_stringdata_CSerialPort_485 = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CSerialPort_485"
QT_MOC_LITERAL(1, 16, 12), // "sig_ReadData"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "strData"
QT_MOC_LITERAL(4, 38, 8), // "readData"
QT_MOC_LITERAL(5, 47, 8), // "sendData"
QT_MOC_LITERAL(6, 56, 4) // "data"

    },
    "CSerialPort_485\0sig_ReadData\0\0strData\0"
    "readData\0sendData\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSerialPort_485[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   32,    2, 0x08 /* Private */,
       5,    1,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void CSerialPort_485::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSerialPort_485 *_t = static_cast<CSerialPort_485 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_ReadData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->readData(); break;
        case 2: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CSerialPort_485::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSerialPort_485::sig_ReadData)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CSerialPort_485::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CSerialPort_485.data,
      qt_meta_data_CSerialPort_485,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CSerialPort_485::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSerialPort_485::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CSerialPort_485.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CSerialPort_485::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CSerialPort_485::sig_ReadData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
