#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QTextEdit>
#include <QSyntaxHighlighter>
#include <QLabel>
#include <QComboBox>  // Changed from QFontComboBox to QComboBox
#include <QSpinBox>

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
    void changeFont(const QString &fontName);  // Changed parameter type to QString
    void changeFontSize(int size);

private:
    QTextEdit *textArea;
    SyntaxHighlighter *highlighter;
    QLabel *statusLabel;
    QComboBox *fontComboBox; 
    QSpinBox *fontSizeSpinBox;
    bool isDarkMode;
    void setupToolbar();
    void applyStyle();
};

#endif // TEXTEDITOR_H