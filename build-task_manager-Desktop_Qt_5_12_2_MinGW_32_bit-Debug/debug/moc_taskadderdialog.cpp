/****************************************************************************
** Meta object code from reading C++ file 'taskadderdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../task_manager/taskadderdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'taskadderdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TaskAdderDialog_t {
    QByteArrayData data[8];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TaskAdderDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TaskAdderDialog_t qt_meta_stringdata_TaskAdderDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TaskAdderDialog"
QT_MOC_LITERAL(1, 16, 9), // "taskadded"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "Task"
QT_MOC_LITERAL(4, 32, 4), // "task"
QT_MOC_LITERAL(5, 37, 6), // "closed"
QT_MOC_LITERAL(6, 44, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(7, 68, 24) // "on_addTuskButton_clicked"

    },
    "TaskAdderDialog\0taskadded\0\0Task\0task\0"
    "closed\0on_pushButton_2_clicked\0"
    "on_addTuskButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TaskAdderDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   38,    2, 0x08 /* Private */,
       7,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TaskAdderDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TaskAdderDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->taskadded((*reinterpret_cast< Task(*)>(_a[1]))); break;
        case 1: _t->closed(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_addTuskButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Task >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TaskAdderDialog::*)(Task );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TaskAdderDialog::taskadded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TaskAdderDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TaskAdderDialog::closed)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TaskAdderDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_TaskAdderDialog.data,
    qt_meta_data_TaskAdderDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TaskAdderDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TaskAdderDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TaskAdderDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TaskAdderDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TaskAdderDialog::taskadded(Task _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TaskAdderDialog::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
