/****************************************************************************
** Meta object code from reading C++ file 'downloader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../12_home_work/downloader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Downloader_t {
    QByteArrayData data[8];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Downloader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Downloader_t qt_meta_stringdata_Downloader = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Downloader"
QT_MOC_LITERAL(1, 11, 16), // "downloadProgress"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "done"
QT_MOC_LITERAL(4, 34, 3), // "url"
QT_MOC_LITERAL(5, 38, 5), // "error"
QT_MOC_LITERAL(6, 44, 12), // "slotFinished"
QT_MOC_LITERAL(7, 57, 14) // "QNetworkReply*"

    },
    "Downloader\0downloadProgress\0\0done\0url\0"
    "error\0slotFinished\0QNetworkReply*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Downloader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       3,    2,   39,    2, 0x06 /* Public */,
       5,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,
    QMetaType::Void, QMetaType::QUrl, QMetaType::QByteArray,    4,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void Downloader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Downloader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: _t->done((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 2: _t->error(); break;
        case 3: _t->slotFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Downloader::*)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Downloader::downloadProgress)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Downloader::*)(const QUrl & , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Downloader::done)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Downloader::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Downloader::error)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Downloader::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Downloader.data,
    qt_meta_data_Downloader,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Downloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Downloader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Downloader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Downloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Downloader::downloadProgress(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Downloader::done(const QUrl & _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Downloader::error()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
