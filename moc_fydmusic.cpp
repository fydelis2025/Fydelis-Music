/****************************************************************************
** Meta object code from reading C++ file 'fydmusic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.15)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "fydmusic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fydmusic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.15. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FydMusic_t {
    QByteArrayData data[24];
    char stringdata0[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FydMusic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FydMusic_t qt_meta_stringdata_FydMusic = {
    {
QT_MOC_LITERAL(0, 0, 8), // "FydMusic"
QT_MOC_LITERAL(1, 9, 16), // "andamentoChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 18), // "estaTocandoChanged"
QT_MOC_LITERAL(4, 46, 16), // "partituraChanged"
QT_MOC_LITERAL(5, 63, 10), // "notaTocada"
QT_MOC_LITERAL(6, 74, 6), // "indice"
QT_MOC_LITERAL(7, 81, 18), // "sequenciaTerminada"
QT_MOC_LITERAL(8, 100, 12), // "tocarProxima"
QT_MOC_LITERAL(9, 113, 13), // "adicionarNota"
QT_MOC_LITERAL(10, 127, 4), // "nome"
QT_MOC_LITERAL(11, 132, 6), // "figura"
QT_MOC_LITERAL(12, 139, 8), // "temPonto"
QT_MOC_LITERAL(13, 148, 14), // "adicionarPausa"
QT_MOC_LITERAL(14, 163, 15), // "aplicarLigadura"
QT_MOC_LITERAL(15, 179, 13), // "removerUltima"
QT_MOC_LITERAL(16, 193, 15), // "limparPartitura"
QT_MOC_LITERAL(17, 209, 14), // "tocarSequencia"
QT_MOC_LITERAL(18, 224, 5), // "parar"
QT_MOC_LITERAL(19, 230, 15), // "tocarNotaAvulsa"
QT_MOC_LITERAL(20, 246, 9), // "andamento"
QT_MOC_LITERAL(21, 256, 11), // "estaTocando"
QT_MOC_LITERAL(22, 268, 10), // "listaNotas"
QT_MOC_LITERAL(23, 279, 9) // "partitura"

    },
    "FydMusic\0andamentoChanged\0\0"
    "estaTocandoChanged\0partituraChanged\0"
    "notaTocada\0indice\0sequenciaTerminada\0"
    "tocarProxima\0adicionarNota\0nome\0figura\0"
    "temPonto\0adicionarPausa\0aplicarLigadura\0"
    "removerUltima\0limparPartitura\0"
    "tocarSequencia\0parar\0tocarNotaAvulsa\0"
    "andamento\0estaTocando\0listaNotas\0"
    "partitura"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FydMusic[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       4,  110, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    1,   87,    2, 0x06 /* Public */,
       7,    0,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   91,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       9,    3,   92,    2, 0x02 /* Public */,
      13,    1,   99,    2, 0x02 /* Public */,
      14,    0,  102,    2, 0x02 /* Public */,
      15,    0,  103,    2, 0x02 /* Public */,
      16,    0,  104,    2, 0x02 /* Public */,
      17,    0,  105,    2, 0x02 /* Public */,
      18,    0,  106,    2, 0x02 /* Public */,
      19,    1,  107,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Bool,   10,   11,   12,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,

 // properties: name, type, flags
      20, QMetaType::Int, 0x00495103,
      21, QMetaType::Bool, 0x00495001,
      22, QMetaType::QString, 0x00495001,
      23, QMetaType::QVariantList, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       2,

       0        // eod
};

void FydMusic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FydMusic *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->andamentoChanged(); break;
        case 1: _t->estaTocandoChanged(); break;
        case 2: _t->partituraChanged(); break;
        case 3: _t->notaTocada((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sequenciaTerminada(); break;
        case 5: _t->tocarProxima(); break;
        case 6: _t->adicionarNota((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 7: _t->adicionarPausa((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->aplicarLigadura(); break;
        case 9: _t->removerUltima(); break;
        case 10: _t->limparPartitura(); break;
        case 11: _t->tocarSequencia(); break;
        case 12: _t->parar(); break;
        case 13: _t->tocarNotaAvulsa((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FydMusic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FydMusic::andamentoChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FydMusic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FydMusic::estaTocandoChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FydMusic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FydMusic::partituraChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FydMusic::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FydMusic::notaTocada)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FydMusic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FydMusic::sequenciaTerminada)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<FydMusic *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->andamento(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->estaTocando(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->listaNotas(); break;
        case 3: *reinterpret_cast< QVariantList*>(_v) = _t->partitura(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<FydMusic *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAndamento(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject FydMusic::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FydMusic.data,
    qt_meta_data_FydMusic,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FydMusic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FydMusic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FydMusic.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FydMusic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
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
void FydMusic::andamentoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FydMusic::estaTocandoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FydMusic::partituraChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FydMusic::notaTocada(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FydMusic::sequenciaTerminada()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
