/****************************************************************************
** Meta object code from reading C++ file 'XColorSquare.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../colorRect/XColorSquare.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'XColorSquare.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_XColorSquare_t {
    QByteArrayData data[18];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XColorSquare_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XColorSquare_t qt_meta_stringdata_XColorSquare = {
    {
QT_MOC_LITERAL(0, 0, 12), // "XColorSquare"
QT_MOC_LITERAL(1, 13, 12), // "colorChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "colorSelected"
QT_MOC_LITERAL(4, 41, 8), // "setColor"
QT_MOC_LITERAL(5, 50, 1), // "c"
QT_MOC_LITERAL(6, 52, 6), // "setHue"
QT_MOC_LITERAL(7, 59, 1), // "h"
QT_MOC_LITERAL(8, 61, 13), // "setSaturation"
QT_MOC_LITERAL(9, 75, 1), // "s"
QT_MOC_LITERAL(10, 77, 8), // "setValue"
QT_MOC_LITERAL(11, 86, 1), // "v"
QT_MOC_LITERAL(12, 88, 15), // "setCheckedColor"
QT_MOC_LITERAL(13, 104, 7), // "checked"
QT_MOC_LITERAL(14, 112, 5), // "color"
QT_MOC_LITERAL(15, 118, 3), // "hue"
QT_MOC_LITERAL(16, 122, 10), // "saturation"
QT_MOC_LITERAL(17, 133, 5) // "value"

    },
    "XColorSquare\0colorChanged\0\0colorSelected\0"
    "setColor\0c\0setHue\0h\0setSaturation\0s\0"
    "setValue\0v\0setCheckedColor\0checked\0"
    "color\0hue\0saturation\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XColorSquare[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       4,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   55,    2, 0x0a /* Public */,
       6,    1,   58,    2, 0x0a /* Public */,
       8,    1,   61,    2, 0x0a /* Public */,
      10,    1,   64,    2, 0x0a /* Public */,
      12,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QColor,    5,
    QMetaType::Void, QMetaType::QReal,    7,
    QMetaType::Void, QMetaType::QReal,    9,
    QMetaType::Void, QMetaType::QReal,   11,
    QMetaType::Void, QMetaType::Char,   13,

 // properties: name, type, flags
      14, QMetaType::QColor, 0x00485103,
      15, QMetaType::QReal, 0x00094103,
      16, QMetaType::QReal, 0x00094103,
      17, QMetaType::QReal, 0x00094103,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,

       0        // eod
};

void XColorSquare::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<XColorSquare *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->colorChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->colorSelected((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->setColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 3: _t->setHue((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 4: _t->setSaturation((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 5: _t->setValue((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 6: _t->setCheckedColor((*reinterpret_cast< char(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (XColorSquare::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XColorSquare::colorChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (XColorSquare::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XColorSquare::colorSelected)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<XColorSquare *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->color(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->hue(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = _t->saturation(); break;
        case 3: *reinterpret_cast< qreal*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<XColorSquare *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: _t->setHue(*reinterpret_cast< qreal*>(_v)); break;
        case 2: _t->setSaturation(*reinterpret_cast< qreal*>(_v)); break;
        case 3: _t->setValue(*reinterpret_cast< qreal*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject XColorSquare::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_XColorSquare.data,
    qt_meta_data_XColorSquare,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *XColorSquare::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XColorSquare::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_XColorSquare.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int XColorSquare::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void XColorSquare::colorChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XColorSquare::colorSelected(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
