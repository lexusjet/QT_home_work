/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.12.2
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // D:/studies/courses(c++)/qt_creator/task_adder/task_adder/task_base/tasks.txt
  0x0,0x0,0x0,0x2b,
  0x0,
  0x0,0x0,0xe8,0x78,0x9c,0x4b,0x4c,0x49,0x4b,0x2c,0x4e,0x49,0x4b,0x29,0x4e,0x53,
  0x30,0xd0,0x33,0x0,0x22,0x5,0x43,0x2e,0x18,0xcb,0x0,0x2b,0x2b,0x3d,0x3d,0x1d,
  0xc6,0x31,0x1a,0x3a,0x1c,0x0,0xda,0xa2,0x31,0x96,
  
};

static const unsigned char qt_resource_name[] = {
  // base
  0x0,0x4,
  0x0,0x6,0x88,0x95,
  0x0,0x62,
  0x0,0x61,0x0,0x73,0x0,0x65,
    // task_base
  0x0,0x9,
  0xa,0x15,0x7d,0x95,
  0x0,0x74,
  0x0,0x61,0x0,0x73,0x0,0x6b,0x0,0x5f,0x0,0x62,0x0,0x61,0x0,0x73,0x0,0x65,
    // tasks.txt
  0x0,0x9,
  0xa,0x26,0xae,0xf4,
  0x0,0x74,
  0x0,0x61,0x0,0x73,0x0,0x6b,0x0,0x73,0x0,0x2e,0x0,0x74,0x0,0x78,0x0,0x74,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/base
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/base/task_base
  0x0,0x0,0x0,0xe,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x3,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/base/task_base/tasks.txt
  0x0,0x0,0x0,0x26,0x0,0x1,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x86,0x94,0x4d,0xa0,0x5b,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_source)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_source)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_source)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_source)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_source)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_source)(); }
   } dummy;
}
