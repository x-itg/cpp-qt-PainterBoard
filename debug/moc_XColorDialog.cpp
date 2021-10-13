/****************************************************************************
** Meta object code from reading C++ file 'XColorDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../colorRect/XColorDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'XColorDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_XColorDialog_t {
    QByteArrayData data[12];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XColorDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XColorDialog_t qt_meta_stringdata_XColorDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "XColorDialog"
QT_MOC_LITERAL(1, 13, 12), // "colorChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "checkedChanged"
QT_MOC_LITERAL(4, 42, 13), // "colorSelected"
QT_MOC_LITERAL(5, 56, 13), // "UpdateWidgets"
QT_MOC_LITERAL(6, 70, 6), // "SetHSV"
QT_MOC_LITERAL(7, 77, 6), // "SetRGB"
QT_MOC_LITERAL(8, 84, 8), // "SetColor"
QT_MOC_LITERAL(9, 93, 5), // "color"
QT_MOC_LITERAL(10, 99, 17), // "SetVerticalSlider"
QT_MOC_LITERAL(11, 117, 15) // "ClickedOkButton"

    },
    "XColorDialog\0colorChanged\0\0checkedChanged\0"
    "colorSelected\0UpdateWidgets\0SetHSV\0"
    "SetRGB\0SetColor\0color\0SetVerticalSlider\0"
    "ClickedOkButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XColorDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   68,    2, 0x0a /* Public */,
       6,    0,   69,    2, 0x0a /* Public */,
       7,    0,   70,    2, 0x0a /* Public */,
       8,    1,   71,    2, 0x0a /* Public */,
      10,    0,   74,    2, 0x0a /* Public */,
      11,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::Char,    2,
    QMetaType::Void, QMetaType::QColor,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void XColorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<XColorDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->colorChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->checkedChanged((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 2: _t->colorSelected((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 3: _t->UpdateWidgets(); break;
        case 4: _t->SetHSV(); break;
        case 5: _t->SetRGB(); break;
        case 6: _t->SetColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 7: _t->SetVerticalSlider(); break;
        case 8: _t->ClickedOkButton(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (XColorDialog::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XColorDialog::colorChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (XColorDialog::*)(char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XColorDialog::checkedChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (XColorDialog::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XColorDialog::colorSelected)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject XColorDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_XColorDialog.data,
    qt_meta_data_XColorDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *XColorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XColorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_XColorDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int XColorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void XColorDialog::colorChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XColorDialog::checkedChanged(char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void XColorDialog::colorSelected(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
