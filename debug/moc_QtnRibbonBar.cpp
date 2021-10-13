/****************************************************************************
** Meta object code from reading C++ file 'QtnRibbonBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ribbon/src/ribbon/QtnRibbonBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtnRibbonBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Qtitan__RibbonBar_t {
    QByteArrayData data[25];
    char stringdata0[366];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__RibbonBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__RibbonBar_t qt_meta_stringdata_Qtitan__RibbonBar = {
    {
QT_MOC_LITERAL(0, 0, 17), // "Qtitan::RibbonBar"
QT_MOC_LITERAL(1, 18, 19), // "minimizationChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 9), // "minimized"
QT_MOC_LITERAL(4, 49, 23), // "currentPageIndexChanged"
QT_MOC_LITERAL(5, 73, 5), // "index"
QT_MOC_LITERAL(6, 79, 18), // "currentPageChanged"
QT_MOC_LITERAL(7, 98, 11), // "RibbonPage*"
QT_MOC_LITERAL(8, 110, 4), // "page"
QT_MOC_LITERAL(9, 115, 13), // "keyTipsShowed"
QT_MOC_LITERAL(10, 129, 6), // "showed"
QT_MOC_LITERAL(11, 136, 21), // "showRibbonContextMenu"
QT_MOC_LITERAL(12, 158, 6), // "QMenu*"
QT_MOC_LITERAL(13, 165, 4), // "menu"
QT_MOC_LITERAL(14, 170, 18), // "QContextMenuEvent*"
QT_MOC_LITERAL(15, 189, 5), // "event"
QT_MOC_LITERAL(16, 195, 19), // "setCurrentPageIndex"
QT_MOC_LITERAL(17, 215, 19), // "showCustomizeDialog"
QT_MOC_LITERAL(18, 235, 22), // "quickAccessBarPosition"
QT_MOC_LITERAL(19, 258, 22), // "QuickAccessBarPosition"
QT_MOC_LITERAL(20, 281, 16), // "currentPageIndex"
QT_MOC_LITERAL(21, 298, 17), // "frameThemeEnabled"
QT_MOC_LITERAL(22, 316, 18), // "titleGroupsVisible"
QT_MOC_LITERAL(23, 335, 13), // "QATopPosition"
QT_MOC_LITERAL(24, 349, 16) // "QABottomPosition"

    },
    "Qtitan::RibbonBar\0minimizationChanged\0"
    "\0minimized\0currentPageIndexChanged\0"
    "index\0currentPageChanged\0RibbonPage*\0"
    "page\0keyTipsShowed\0showed\0"
    "showRibbonContextMenu\0QMenu*\0menu\0"
    "QContextMenuEvent*\0event\0setCurrentPageIndex\0"
    "showCustomizeDialog\0quickAccessBarPosition\0"
    "QuickAccessBarPosition\0currentPageIndex\0"
    "frameThemeEnabled\0titleGroupsVisible\0"
    "QATopPosition\0QABottomPosition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__RibbonBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       5,   70, // properties
       1,   90, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,
       9,    1,   58,    2, 0x06 /* Public */,
      11,    2,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    1,   66,    2, 0x0a /* Public */,
      17,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14,   13,   15,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

 // properties: name, type, flags
      18, 0x80000000 | 19, 0x0009510b,
      20, QMetaType::Int, 0x00495103,
      21, QMetaType::Bool, 0x00095103,
       3, QMetaType::Bool, 0x00495103,
      22, QMetaType::Bool, 0x00095103,

 // properties: notify_signal_id
       0,
       1,
       0,
       0,
       0,

 // enums: name, alias, flags, count, data
      19,   19, 0x0,    2,   95,

 // enum data: key, value
      23, uint(Qtitan::RibbonBar::QATopPosition),
      24, uint(Qtitan::RibbonBar::QABottomPosition),

       0        // eod
};

void Qtitan::RibbonBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RibbonBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->minimizationChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->currentPageIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->currentPageChanged((*reinterpret_cast< RibbonPage*(*)>(_a[1]))); break;
        case 3: _t->keyTipsShowed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->showRibbonContextMenu((*reinterpret_cast< QMenu*(*)>(_a[1])),(*reinterpret_cast< QContextMenuEvent*(*)>(_a[2]))); break;
        case 5: _t->setCurrentPageIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->showCustomizeDialog(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMenu* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RibbonBar::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RibbonBar::minimizationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RibbonBar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RibbonBar::currentPageIndexChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RibbonBar::*)(RibbonPage * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RibbonBar::currentPageChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (RibbonBar::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RibbonBar::keyTipsShowed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (RibbonBar::*)(QMenu * , QContextMenuEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RibbonBar::showRibbonContextMenu)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<RibbonBar *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QuickAccessBarPosition*>(_v) = _t->quickAccessBarPosition(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->currentPageIndex(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isFrameThemeEnabled(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->isMinimized(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->isTitleGroupsVisible(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<RibbonBar *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setQuickAccessBarPosition(*reinterpret_cast< QuickAccessBarPosition*>(_v)); break;
        case 1: _t->setCurrentPageIndex(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setFrameThemeEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setMinimized(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setTitleGroupsVisible(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Qtitan::RibbonBar::staticMetaObject = { {
    &QMenuBar::staticMetaObject,
    qt_meta_stringdata_Qtitan__RibbonBar.data,
    qt_meta_data_Qtitan__RibbonBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Qtitan::RibbonBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::RibbonBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__RibbonBar.stringdata0))
        return static_cast<void*>(this);
    return QMenuBar::qt_metacast(_clname);
}

int Qtitan::RibbonBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenuBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Qtitan::RibbonBar::minimizationChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Qtitan::RibbonBar::currentPageIndexChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Qtitan::RibbonBar::currentPageChanged(RibbonPage * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Qtitan::RibbonBar::keyTipsShowed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Qtitan::RibbonBar::showRibbonContextMenu(QMenu * _t1, QContextMenuEvent * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
