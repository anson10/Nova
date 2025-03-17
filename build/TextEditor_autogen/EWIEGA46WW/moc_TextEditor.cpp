/****************************************************************************
** Meta object code from reading C++ file 'TextEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../TextEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TextEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TextEditor_t {
    QByteArrayData data[24];
    char stringdata0[288];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextEditor_t qt_meta_stringdata_TextEditor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TextEditor"
QT_MOC_LITERAL(1, 11, 8), // "openFile"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "saveFile"
QT_MOC_LITERAL(4, 30, 8), // "findText"
QT_MOC_LITERAL(5, 39, 11), // "replaceText"
QT_MOC_LITERAL(6, 51, 10), // "formatBold"
QT_MOC_LITERAL(7, 62, 12), // "formatItalic"
QT_MOC_LITERAL(8, 75, 15), // "formatUnderline"
QT_MOC_LITERAL(9, 91, 10), // "undoAction"
QT_MOC_LITERAL(10, 102, 10), // "redoAction"
QT_MOC_LITERAL(11, 113, 17), // "convertToMarkdown"
QT_MOC_LITERAL(12, 131, 14), // "toggleDarkMode"
QT_MOC_LITERAL(13, 146, 15), // "updateStatusBar"
QT_MOC_LITERAL(14, 162, 10), // "changeFont"
QT_MOC_LITERAL(15, 173, 8), // "fontName"
QT_MOC_LITERAL(16, 182, 14), // "changeFontSize"
QT_MOC_LITERAL(17, 197, 4), // "size"
QT_MOC_LITERAL(18, 202, 16), // "insertBulletList"
QT_MOC_LITERAL(19, 219, 18), // "insertNumberedList"
QT_MOC_LITERAL(20, 238, 14), // "showStatistics"
QT_MOC_LITERAL(21, 253, 11), // "startSpeech"
QT_MOC_LITERAL(22, 265, 11), // "pauseSpeech"
QT_MOC_LITERAL(23, 277, 10) // "stopSpeech"

    },
    "TextEditor\0openFile\0\0saveFile\0findText\0"
    "replaceText\0formatBold\0formatItalic\0"
    "formatUnderline\0undoAction\0redoAction\0"
    "convertToMarkdown\0toggleDarkMode\0"
    "updateStatusBar\0changeFont\0fontName\0"
    "changeFontSize\0size\0insertBulletList\0"
    "insertNumberedList\0showStatistics\0"
    "startSpeech\0pauseSpeech\0stopSpeech"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x08 /* Private */,
       3,    0,  115,    2, 0x08 /* Private */,
       4,    0,  116,    2, 0x08 /* Private */,
       5,    0,  117,    2, 0x08 /* Private */,
       6,    0,  118,    2, 0x08 /* Private */,
       7,    0,  119,    2, 0x08 /* Private */,
       8,    0,  120,    2, 0x08 /* Private */,
       9,    0,  121,    2, 0x08 /* Private */,
      10,    0,  122,    2, 0x08 /* Private */,
      11,    0,  123,    2, 0x08 /* Private */,
      12,    0,  124,    2, 0x08 /* Private */,
      13,    0,  125,    2, 0x08 /* Private */,
      14,    1,  126,    2, 0x08 /* Private */,
      16,    1,  129,    2, 0x08 /* Private */,
      18,    0,  132,    2, 0x08 /* Private */,
      19,    0,  133,    2, 0x08 /* Private */,
      20,    0,  134,    2, 0x08 /* Private */,
      21,    0,  135,    2, 0x08 /* Private */,
      22,    0,  136,    2, 0x08 /* Private */,
      23,    0,  137,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TextEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TextEditor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openFile(); break;
        case 1: _t->saveFile(); break;
        case 2: _t->findText(); break;
        case 3: _t->replaceText(); break;
        case 4: _t->formatBold(); break;
        case 5: _t->formatItalic(); break;
        case 6: _t->formatUnderline(); break;
        case 7: _t->undoAction(); break;
        case 8: _t->redoAction(); break;
        case 9: _t->convertToMarkdown(); break;
        case 10: _t->toggleDarkMode(); break;
        case 11: _t->updateStatusBar(); break;
        case 12: _t->changeFont((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->changeFontSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->insertBulletList(); break;
        case 15: _t->insertNumberedList(); break;
        case 16: _t->showStatistics(); break;
        case 17: _t->startSpeech(); break;
        case 18: _t->pauseSpeech(); break;
        case 19: _t->stopSpeech(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TextEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_TextEditor.data,
    qt_meta_data_TextEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TextEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TextEditor.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TextEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
