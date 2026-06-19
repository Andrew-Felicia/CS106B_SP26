/****************************************************************************
** Meta object code from reading C++ file 'gscrollbar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Library/graphics/gscrollbar.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gscrollbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASS_Internal_QScrollBarENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASS_Internal_QScrollBarENDCLASS = QtMocHelpers::stringData(
    "_Internal_QScrollBar",
    "handleValueChange",
    "",
    "value"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASS_Internal_QScrollBarENDCLASS_t {
    uint offsetsAndSizes[8];
    char stringdata0[21];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASS_Internal_QScrollBarENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASS_Internal_QScrollBarENDCLASS_t qt_meta_stringdata_CLASS_Internal_QScrollBarENDCLASS = {
    {
        QT_MOC_LITERAL(0, 20),  // "_Internal_QScrollBar"
        QT_MOC_LITERAL(21, 17),  // "handleValueChange"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 5)   // "value"
    },
    "_Internal_QScrollBar",
    "handleValueChange",
    "",
    "value"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASS_Internal_QScrollBarENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x0a,    1 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

Q_CONSTINIT const QMetaObject _Internal_QScrollBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QScrollBar::staticMetaObject>(),
    qt_meta_stringdata_CLASS_Internal_QScrollBarENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASS_Internal_QScrollBarENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASS_Internal_QScrollBarENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<_Internal_QScrollBar, std::true_type>,
        // method 'handleValueChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void _Internal_QScrollBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<_Internal_QScrollBar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handleValueChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *_Internal_QScrollBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *_Internal_QScrollBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASS_Internal_QScrollBarENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "_Internal_QWidget"))
        return static_cast< _Internal_QWidget*>(this);
    return QScrollBar::qt_metacast(_clname);
}

int _Internal_QScrollBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
