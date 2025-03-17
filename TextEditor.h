#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QTextEdit>
#include <QSyntaxHighlighter>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QTextToSpeech>  // Added for text-to-speech

class SyntaxHighlighter;

class TextEditor : public QMainWindow {
    Q_OBJECT  

public:
    TextEditor(QWidget *parent = nullptr);
    ~TextEditor(); 

private slots:
    void openFile();
    void saveFile();
    void findText();
    void replaceText();
    void formatBold();
    void formatItalic();
    void formatUnderline();
    void undoAction();
    void redoAction();
    void convertToMarkdown();
    void toggleDarkMode();
    void updateStatusBar();
    void changeFont(const QString &fontName);
    void changeFontSize(int size);
    void insertBulletList();
    void insertNumberedList();
    void showStatistics();         // New slot for statistics dialog
    void startSpeech();            // New slot for starting text-to-speech
    void pauseSpeech();            // New slot for pausing text-to-speech
    void stopSpeech();             // New slot for stopping text-to-speech

private:
    QTextEdit *textArea;
    SyntaxHighlighter *highlighter;
    QLabel *statusLabel;
    QComboBox *fontComboBox;
    QSpinBox *fontSizeSpinBox;
    QTextToSpeech *speech;         // New member for text-to-speech
    bool isDarkMode;
    void setupToolbar();
    void applyStyle();
};

#endif // TEXTEDITOR_H