/****************************************************************************
** Meta object code from reading C++ file 'paint.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "paint.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paint.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Paint_t {
    QByteArrayData data[15];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Paint_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Paint_t qt_meta_stringdata_Paint = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Paint"
QT_MOC_LITERAL(1, 6, 9), // "slotTimer"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 23), // "on_pushButton_1_clicked"
QT_MOC_LITERAL(4, 41, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(5, 65, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(6, 89, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(7, 113, 12), // "saveExamples"
QT_MOC_LITERAL(8, 126, 12), // "readExamples"
QT_MOC_LITERAL(9, 139, 13), // "clearExamples"
QT_MOC_LITERAL(10, 153, 11), // "saveWeights"
QT_MOC_LITERAL(11, 165, 11), // "dropWeights"
QT_MOC_LITERAL(12, 177, 11), // "readWeights"
QT_MOC_LITERAL(13, 189, 4), // "quit"
QT_MOC_LITERAL(14, 194, 5) // "about"

    },
    "Paint\0slotTimer\0\0on_pushButton_1_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked\0saveExamples\0"
    "readExamples\0clearExamples\0saveWeights\0"
    "dropWeights\0readWeights\0quit\0about"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Paint[] = {

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
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void Paint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Paint *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotTimer(); break;
        case 1: _t->on_pushButton_1_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_pushButton_4_clicked(); break;
        case 5: _t->saveExamples(); break;
        case 6: _t->readExamples(); break;
        case 7: _t->clearExamples(); break;
        case 8: _t->saveWeights(); break;
        case 9: _t->dropWeights(); break;
        case 10: _t->readWeights(); break;
        case 11: _t->quit(); break;
        case 12: _t->about(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Paint::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Paint.data,
    qt_meta_data_Paint,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Paint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Paint::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Paint.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Neuron"))
        return static_cast< Neuron*>(this);
    return QWidget::qt_metacast(_clname);
}

int Paint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
