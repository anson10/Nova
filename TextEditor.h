#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QTextEdit>
#include <QSyntaxHighlighter>
#include <QLabel>
#include <QFontComboBox>
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
    void changeFont(const QFont &font);
    void changeFontSize(int size);

private:
    QTextEdit *textArea;
    SyntaxHighlighter *highlighter;
    QLabel *statusLabel;
    QFontComboBox *fontComboBox;
    QSpinBox *fontSizeSpinBox;
    bool isDarkMode;
    void setupToolbar();
    void applyStyle();
};

#endif // TEXTEDITOR_H