/****************************************************************************
** Meta object code from reading C++ file 'janela.hpp'
**
** Created: Mon 23. Jul 18:03:28 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "janela.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'janela.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MadaoWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      31,   13,   12,   12, 0x08,
      77,   13,   12,   12, 0x08,
     119,   12,   12,   12, 0x08,
     136,   12,   12,   12, 0x08,
     148,   12,   12,   12, 0x08,
     159,   12,   12,   12, 0x08,
     171,   12,   12,   12, 0x08,
     187,   12,   12,   12, 0x08,
     198,   12,   12,   12, 0x08,
     220,  209,   12,   12, 0x08,
     249,  242,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MadaoWindow[] = {
    "MadaoWindow\0\0newState,oldState\0"
    "metaStateChanged(Phonon::State,Phonon::State)\0"
    "stateChanged(Phonon::State,Phonon::State)\0"
    "playPauseMusic()\0stopMusic()\0setMusic()\0"
    "nextMusic()\0previousMusic()\0addFiles()\0"
    "autoNext()\0row,column\0tableClicked(int,int)\0"
    "source\0sourceChanged(Phonon::MediaSource)\0"
};

void MadaoWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MadaoWindow *_t = static_cast<MadaoWindow *>(_o);
        switch (_id) {
        case 0: _t->metaStateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 1: _t->stateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 2: _t->playPauseMusic(); break;
        case 3: _t->stopMusic(); break;
        case 4: _t->setMusic(); break;
        case 5: _t->nextMusic(); break;
        case 6: _t->previousMusic(); break;
        case 7: _t->addFiles(); break;
        case 8: _t->autoNext(); break;
        case 9: _t->tableClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->sourceChanged((*reinterpret_cast< const Phonon::MediaSource(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MadaoWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MadaoWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MadaoWindow,
      qt_meta_data_MadaoWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MadaoWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MadaoWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MadaoWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MadaoWindow))
        return static_cast<void*>(const_cast< MadaoWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MadaoWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
