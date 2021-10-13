/****************************************************************************
** Meta object code from reading C++ file 'QtnRibbonCustomizeDialogPrivate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ribbon/src/ribbon/QtnRibbonCustomizeDialogPrivate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtnRibbonCustomizeDialogPrivate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Qtitan__RibbonCustomizeDialogPrivate_t {
    QByteArrayData data[4];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__RibbonCustomizeDialogPrivate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__RibbonCustomizeDialogPrivate_t qt_meta_stringdata_Qtitan__RibbonCustomizeDialogPrivate = {
    {
QT_MOC_LITERAL(0, 0, 36), // "Qtitan::RibbonCustomizeDialog..."
QT_MOC_LITERAL(1, 37, 12), // "switchToPage"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 10) // "currentRow"

    },
    "Qtitan::RibbonCustomizeDialogPrivate\0"
    "switchToPage\0\0currentRow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__RibbonCustomizeDialogPrivate[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void Qtitan::RibbonCustomizeDialogPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RibbonCustomizeDialogPrivate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->switchToPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Qtitan::RibbonCustomizeDialogPrivate::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Qtitan__RibbonCustomizeDialogPrivate.data,
    qt_meta_data_Qtitan__RibbonCustomizeDialogPrivate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Qtitan::RibbonCustomizeDialogPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::RibbonCustomizeDialogPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__RibbonCustomizeDialogPrivate.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Qtitan::RibbonCustomizeDialogPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_Qtitan__RibbonQuickAccessBarCustomizePagePrivate_t {
    QByteArrayData data[12];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__RibbonQuickAccessBarCustomizePagePrivate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__RibbonQuickAccessBarCustomizePagePrivate_t qt_meta_stringdata_Qtitan__RibbonQuickAccessBarCustomizePagePrivate = {
    {
QT_MOC_LITERAL(0, 0, 48), // "Qtitan::RibbonQuickAccessBarC..."
QT_MOC_LITERAL(1, 49, 22), // "setCurrentCategoryText"
QT_MOC_LITERAL(2, 72, 0), // ""
QT_MOC_LITERAL(3, 73, 21), // "currentCommandChanged"
QT_MOC_LITERAL(4, 95, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 112, 7), // "current"
QT_MOC_LITERAL(6, 120, 23), // "currentQTCommandChanged"
QT_MOC_LITERAL(7, 144, 10), // "addClicked"
QT_MOC_LITERAL(8, 155, 13), // "removeClicked"
QT_MOC_LITERAL(9, 169, 12), // "resetClicked"
QT_MOC_LITERAL(10, 182, 9), // "upClicked"
QT_MOC_LITERAL(11, 192, 11) // "downClicked"

    },
    "Qtitan::RibbonQuickAccessBarCustomizePagePrivate\0"
    "setCurrentCategoryText\0\0currentCommandChanged\0"
    "QListWidgetItem*\0current\0"
    "currentQTCommandChanged\0addClicked\0"
    "removeClicked\0resetClicked\0upClicked\0"
    "downClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__RibbonQuickAccessBarCustomizePagePrivate[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       3,    1,   57,    2, 0x0a /* Public */,
       6,    1,   60,    2, 0x0a /* Public */,
       7,    0,   63,    2, 0x0a /* Public */,
       8,    0,   64,    2, 0x0a /* Public */,
       9,    0,   65,    2, 0x0a /* Public */,
      10,    0,   66,    2, 0x0a /* Public */,
      11,    0,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Qtitan::RibbonQuickAccessBarCustomizePagePrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RibbonQuickAccessBarCustomizePagePrivate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setCurrentCategoryText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->currentCommandChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->currentQTCommandChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->addClicked(); break;
        case 4: _t->removeClicked(); break;
        case 5: _t->resetClicked(); break;
        case 6: _t->upClicked(); break;
        case 7: _t->downClicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Qtitan::RibbonQuickAccessBarCustomizePagePrivate::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Qtitan__RibbonQuickAccessBarCustomizePagePrivate.data,
    qt_meta_data_Qtitan__RibbonQuickAccessBarCustomizePagePrivate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Qtitan::RibbonQuickAccessBarCustomizePagePrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::RibbonQuickAccessBarCustomizePagePrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__RibbonQuickAccessBarCustomizePagePrivate.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Qtitan::RibbonQuickAccessBarCustomizePagePrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
struct qt_meta_stringdata_Qtitan__RibbonBarCustomizePagePrivate_t {
    QByteArrayData data[17];
    char stringdata0[267];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtitan__RibbonBarCustomizePagePrivate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtitan__RibbonBarCustomizePagePrivate_t qt_meta_stringdata_Qtitan__RibbonBarCustomizePagePrivate = {
    {
QT_MOC_LITERAL(0, 0, 37), // "Qtitan::RibbonBarCustomizePag..."
QT_MOC_LITERAL(1, 38, 10), // "addClicked"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 13), // "newTabClicked"
QT_MOC_LITERAL(4, 64, 15), // "newGroupClicked"
QT_MOC_LITERAL(5, 80, 13), // "removeClicked"
QT_MOC_LITERAL(6, 94, 12), // "resetClicked"
QT_MOC_LITERAL(7, 107, 9), // "upClicked"
QT_MOC_LITERAL(8, 117, 11), // "downClicked"
QT_MOC_LITERAL(9, 129, 13), // "renameClicked"
QT_MOC_LITERAL(10, 143, 22), // "setCurrentCategoryText"
QT_MOC_LITERAL(11, 166, 18), // "setCurrentTabsText"
QT_MOC_LITERAL(12, 185, 20), // "currentSourceChanged"
QT_MOC_LITERAL(13, 206, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(14, 223, 8), // "itemPage"
QT_MOC_LITERAL(15, 232, 18), // "currentPageChanged"
QT_MOC_LITERAL(16, 251, 15) // "itemPageChanged"

    },
    "Qtitan::RibbonBarCustomizePagePrivate\0"
    "addClicked\0\0newTabClicked\0newGroupClicked\0"
    "removeClicked\0resetClicked\0upClicked\0"
    "downClicked\0renameClicked\0"
    "setCurrentCategoryText\0setCurrentTabsText\0"
    "currentSourceChanged\0QTreeWidgetItem*\0"
    "itemPage\0currentPageChanged\0itemPageChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtitan__RibbonBarCustomizePagePrivate[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x0a /* Public */,
       4,    0,   81,    2, 0x0a /* Public */,
       5,    0,   82,    2, 0x0a /* Public */,
       6,    0,   83,    2, 0x0a /* Public */,
       7,    0,   84,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    1,   87,    2, 0x0a /* Public */,
      11,    1,   90,    2, 0x0a /* Public */,
      12,    1,   93,    2, 0x0a /* Public */,
      15,    1,   96,    2, 0x0a /* Public */,
      16,    2,   99,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,    2,

       0        // eod
};

void Qtitan::RibbonBarCustomizePagePrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RibbonBarCustomizePagePrivate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addClicked(); break;
        case 1: _t->newTabClicked(); break;
        case 2: _t->newGroupClicked(); break;
        case 3: _t->removeClicked(); break;
        case 4: _t->resetClicked(); break;
        case 5: _t->upClicked(); break;
        case 6: _t->downClicked(); break;
        case 7: _t->renameClicked(); break;
        case 8: _t->setCurrentCategoryText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->setCurrentTabsText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->currentSourceChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->currentPageChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 12: _t->itemPageChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Qtitan::RibbonBarCustomizePagePrivate::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Qtitan__RibbonBarCustomizePagePrivate.data,
    qt_meta_data_Qtitan__RibbonBarCustomizePagePrivate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Qtitan::RibbonBarCustomizePagePrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtitan::RibbonBarCustomizePagePrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtitan__RibbonBarCustomizePagePrivate.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Qtitan::RibbonBarCustomizePagePrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
