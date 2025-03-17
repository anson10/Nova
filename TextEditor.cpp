#include "TextEditor.h"
#include "SyntaxHighlighter.h"
#include <QApplication>
#include <QMenuBar>
#include <QToolBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QInputDialog>
#include <QAction>
#include <QStatusBar>
#include <QStyleFactory>
#include <QStyle>
#include <QComboBox>
#include <QSpinBox>
#include <QTextListFormat>
#include <QTextList>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextToSpeech>
#include <cmath> 

TextEditor::TextEditor(QWidget *parent)
    : QMainWindow(parent), isDarkMode(false)
{
    textArea = new QTextEdit(this);
    highlighter = new SyntaxHighlighter(textArea->document());
    setCentralWidget(textArea);
    
    // Initialize text-to-speech
    speech = new QTextToSpeech(this);
    
    // Create menu bar
    QMenu *fileMenu = menuBar()->addMenu("File");
    
    QAction *openAction = new QAction(QIcon::fromTheme("document-open"), "Open", this);
    openAction->setShortcut(QKeySequence::Open);
    connect(openAction, &QAction::triggered, this, &TextEditor::openFile);
    fileMenu->addAction(openAction);
    
    QAction *saveAction = new QAction(QIcon::fromTheme("document-save"), "Save", this);
    saveAction->setShortcut(QKeySequence::Save);
    connect(saveAction, &QAction::triggered, this, &TextEditor::saveFile);
    fileMenu->addAction(saveAction);
    
    QMenu *editMenu = menuBar()->addMenu("Edit");
    
    QAction *findAction = new QAction(QIcon::fromTheme("edit-find"), "Find", this);
    findAction->setShortcut(QKeySequence::Find);
    connect(findAction, &QAction::triggered, this, &TextEditor::findText);
    editMenu->addAction(findAction);
    
    QAction *replaceAction = new QAction(QIcon::fromTheme("edit-find-replace"), "Replace", this);
    replaceAction->setShortcut(QKeySequence("Ctrl+R"));
    connect(replaceAction, &QAction::triggered, this, &TextEditor::replaceText);
    editMenu->addAction(replaceAction);
    
    QAction *undoAction = new QAction(QIcon::fromTheme("edit-undo"), "Undo", this);
    undoAction->setShortcut(QKeySequence::Undo);
    connect(undoAction, &QAction::triggered, this, &TextEditor::undoAction);
    editMenu->addAction(undoAction);
    
    QAction *redoAction = new QAction(QIcon::fromTheme("edit-redo"), "Redo", this);
    redoAction->setShortcut(QKeySequence::Redo);
    connect(redoAction, &QAction::triggered, this, &TextEditor::redoAction);
    editMenu->addAction(redoAction);
    
    QMenu *formatMenu = menuBar()->addMenu("Format");
    
    QAction *boldAction = new QAction(QIcon::fromTheme("format-text-bold"), "Bold", this);
    boldAction->setShortcut(QKeySequence::Bold);
    connect(boldAction, &QAction::triggered, this, &TextEditor::formatBold);
    formatMenu->addAction(boldAction);
    
    QAction *italicAction = new QAction(QIcon::fromTheme("format-text-italic"), "Italic", this);
    italicAction->setShortcut(QKeySequence::Italic);
    connect(italicAction, &QAction::triggered, this, &TextEditor::formatItalic);
    formatMenu->addAction(italicAction);
    
    QAction *underlineAction = new QAction(QIcon::fromTheme("format-text-underline"), "Underline", this);
    underlineAction->setShortcut(QKeySequence::Underline);
    connect(underlineAction, &QAction::triggered, this, &TextEditor::formatUnderline);
    formatMenu->addAction(underlineAction);
    
    QAction *bulletListAction = new QAction(QIcon::fromTheme("format-list-unordered"), "Bullet List", this);
    bulletListAction->setShortcut(Qt::CTRL | Qt::Key_L);
    connect(bulletListAction, &QAction::triggered, this, &TextEditor::insertBulletList);
    formatMenu->addAction(bulletListAction);
    
    QAction *numberedListAction = new QAction(QIcon::fromTheme("format-list-ordered"), "Numbered List", this);
    numberedListAction->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_L);
    connect(numberedListAction, &QAction::triggered, this, &TextEditor::insertNumberedList);
    formatMenu->addAction(numberedListAction);
    
    QAction *markdownAction = new QAction("Convert to Markdown", this);
    markdownAction->setShortcut(Qt::CTRL | Qt::Key_M);
    connect(markdownAction, &QAction::triggered, this, &TextEditor::convertToMarkdown);
    formatMenu->addAction(markdownAction);
    
    // View menu for dark mode and new features
    QMenu *viewMenu = menuBar()->addMenu("View");
    QAction *darkModeAction = new QAction("Dark Mode", this);
    darkModeAction->setCheckable(true);
    darkModeAction->setShortcut(Qt::CTRL | Qt::Key_D);
    connect(darkModeAction, &QAction::triggered, this, &TextEditor::toggleDarkMode);
    viewMenu->addAction(darkModeAction);
    
    QAction *statisticsAction = new QAction("Show Statistics", this);
    statisticsAction->setShortcut(Qt::CTRL | Qt::Key_T);
    connect(statisticsAction, &QAction::triggered, this, &TextEditor::showStatistics);
    viewMenu->addAction(statisticsAction);
    
    QMenu *toolsMenu = menuBar()->addMenu("Tools");
    QAction *startSpeechAction = new QAction(QIcon::fromTheme("media-playback-start"), "Read Aloud", this);
    startSpeechAction->setShortcut(Qt::CTRL | Qt::Key_R);
    connect(startSpeechAction, &QAction::triggered, this, &TextEditor::startSpeech);
    toolsMenu->addAction(startSpeechAction);
    
    QAction *pauseSpeechAction = new QAction(QIcon::fromTheme("media-playback-pause"), "Pause Reading", this);
    pauseSpeechAction->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_R);
    connect(pauseSpeechAction, &QAction::triggered, this, &TextEditor::pauseSpeech);
    toolsMenu->addAction(pauseSpeechAction);
    
    QAction *stopSpeechAction = new QAction(QIcon::fromTheme("media-playback-stop"), "Stop Reading", this);
    stopSpeechAction->setShortcut(Qt::CTRL | Qt::ALT | Qt::Key_R);
    connect(stopSpeechAction, &QAction::triggered, this, &TextEditor::stopSpeech);
    toolsMenu->addAction(stopSpeechAction);
    
    // Setup toolbar with font and size controls
    setupToolbar();
    
    // Setup status bar
    statusLabel = new QLabel("Words: 0 | Lines: 0 | Col: 0", this);
    statusBar()->addWidget(statusLabel);
    connect(textArea, &QTextEdit::textChanged, this, &TextEditor::updateStatusBar);
    connect(textArea, &QTextEdit::cursorPositionChanged, this, &TextEditor::updateStatusBar);
    
    setWindowTitle("Text Editor");
    resize(800, 600);
    applyStyle();
    updateStatusBar();
}

TextEditor::~TextEditor() {
    delete highlighter;
    delete textArea;
    delete fontComboBox;
    delete fontSizeSpinBox;
    delete speech;
}

void TextEditor::setupToolbar() {
    QToolBar *toolbar = addToolBar("Main Toolbar");
    toolbar->addAction(QIcon::fromTheme("document-open"), "Open", this, &TextEditor::openFile);
    toolbar->addAction(QIcon::fromTheme("document-save"), "Save", this, &TextEditor::saveFile);
    toolbar->addSeparator();
    toolbar->addAction(QIcon::fromTheme("edit-undo"), "Undo", this, &TextEditor::undoAction);
    toolbar->addAction(QIcon::fromTheme("edit-redo"), "Redo", this, &TextEditor::redoAction);
    toolbar->addSeparator();
    toolbar->addAction(QIcon::fromTheme("format-text-bold"), "Bold", this, &TextEditor::formatBold);
    toolbar->addAction(QIcon::fromTheme("format-text-italic"), "Italic", this, &TextEditor::formatItalic);
    toolbar->addAction(QIcon::fromTheme("format-text-underline"), "Underline", this, &TextEditor::formatUnderline);
    toolbar->addAction(QIcon::fromTheme("format-list-unordered"), "Bullet List", this, &TextEditor::insertBulletList);
    toolbar->addAction(QIcon::fromTheme("format-list-ordered"), "Numbered List", this, &TextEditor::insertNumberedList);
    toolbar->addSeparator();
    
    // Add font selection with a predefined list
    fontComboBox = new QComboBox(toolbar);
    QStringList fonts = {
        "Arial", "Times New Roman", "Courier New", "Helvetica", "Verdana",
        "Georgia", "Trebuchet MS", "Comic Sans MS", "Impact", "Monospace",
        "Roboto", "Open Sans", "Lato", "Montserrat", "Poppins"
    };
    fontComboBox->addItems(fonts);
    fontComboBox->setCurrentText("Arial");  // Default font
    connect(fontComboBox, &QComboBox::currentTextChanged, this, &TextEditor::changeFont);
    toolbar->addWidget(fontComboBox);
    
    // Add font size selection
    fontSizeSpinBox = new QSpinBox(toolbar);
    fontSizeSpinBox->setRange(6, 72);  // Font size range from 6 to 72
    fontSizeSpinBox->setValue(12);     // Default size
    connect(fontSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &TextEditor::changeFontSize);
    toolbar->addWidget(fontSizeSpinBox);
    
    // Add text-to-speech controls to toolbar
    toolbar->addSeparator();
    toolbar->addAction(QIcon::fromTheme("media-playback-start"), "Read Aloud", this, &TextEditor::startSpeech);
    toolbar->addAction(QIcon::fromTheme("media-playback-pause"), "Pause Reading", this, &TextEditor::pauseSpeech);
    toolbar->addAction(QIcon::fromTheme("media-playback-stop"), "Stop Reading", this, &TextEditor::stopSpeech);
}

void TextEditor::applyStyle() {
    if (isDarkMode) {
        qApp->setStyle(QStyleFactory::create("Fusion"));
        QPalette darkPalette;
        darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::WindowText, Qt::white);
        darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
        darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        darkPalette.setColor(QPalette::Text, Qt::white);
        darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ButtonText, Qt::white);
        darkPalette.setColor(QPalette::BrightText, Qt::red);
        darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::HighlightedText, Qt::black);
        qApp->setPalette(darkPalette);
        textArea->setStyleSheet("QTextEdit { background-color: #19232D; color: white; border: 1px solid #32414B; }");
    } else {
        qApp->setStyle(QStyleFactory::create("Fusion"));
        qApp->setPalette(QApplication::style()->standardPalette());
        textArea->setStyleSheet("QTextEdit { background-color: white; color: black; border: 1px solid #D3D3D3; }");
    }
}

void TextEditor::toggleDarkMode() {
    isDarkMode = !isDarkMode;
    applyStyle();
}

void TextEditor::updateStatusBar() {
    QString text = textArea->toPlainText();
    int wordCount = text.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts).count();
    int lineCount = text.count("\n") + 1;
    QTextCursor cursor = textArea->textCursor();
    int column = cursor.columnNumber();
    statusLabel->setText(QString("Words: %1 | Lines: %2 | Col: %3").arg(wordCount).arg(lineCount).arg(column));
}

void TextEditor::changeFont(const QString &fontName) {
    QTextCharFormat fmt = textArea->currentCharFormat();
    fmt.setFont(QFont(fontName));
    textArea->setCurrentCharFormat(fmt);
    textArea->setFocus();
}

void TextEditor::changeFontSize(int size) {
    QTextCharFormat fmt = textArea->currentCharFormat();
    fmt.setFontPointSize(size);
    textArea->setCurrentCharFormat(fmt);
    textArea->setFocus();
}

void TextEditor::insertBulletList() {
    QTextCursor cursor = textArea->textCursor();
    QTextListFormat listFormat;
    listFormat.setStyle(QTextListFormat::ListDisc);
    cursor.createList(listFormat);
    textArea->setTextCursor(cursor);
    textArea->setFocus();
}

void TextEditor::insertNumberedList() {
    QTextCursor cursor = textArea->textCursor();
    QTextListFormat listFormat;
    listFormat.setStyle(QTextListFormat::ListDecimal);
    cursor.createList(listFormat);
    textArea->setTextCursor(cursor);
    textArea->setFocus();
}

void TextEditor::showStatistics() {
    QString text = textArea->toPlainText();
    int wordCount = text.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts).count();
    int charCountWithSpaces = text.length();
    int charCountNoSpaces = text.count(QRegularExpression("[^\\s]"));
    int paragraphCount = text.split(QRegularExpression("\\n\\s*\\n"), Qt::SkipEmptyParts).count();
    double wordsPerMinute = 200.0;  // Average reading speed
    int readingTime = static_cast<int>(std::ceil(wordCount / wordsPerMinute));

    QDialog *statsDialog = new QDialog(this);
    statsDialog->setWindowTitle("Text Statistics");
    QVBoxLayout *layout = new QVBoxLayout(statsDialog);
    
    layout->addWidget(new QLabel(QString("Word Count: %1").arg(wordCount)));
    layout->addWidget(new QLabel(QString("Characters (with spaces): %1").arg(charCountWithSpaces)));
    layout->addWidget(new QLabel(QString("Characters (no spaces): %1").arg(charCountNoSpaces)));
    layout->addWidget(new QLabel(QString("Paragraphs: %1").arg(paragraphCount)));
    layout->addWidget(new QLabel(QString("Estimated Reading Time: %1 minute(s)").arg(readingTime)));
    
    QPushButton *closeButton = new QPushButton("Close", statsDialog);
    connect(closeButton, &QPushButton::clicked, statsDialog, &QDialog::accept);
    layout->addWidget(closeButton);
    
    statsDialog->setLayout(layout);
    statsDialog->exec();
    delete statsDialog;
}

void TextEditor::startSpeech() {
    QString text = textArea->toPlainText();
    if (!text.isEmpty()) {
        speech->say(text);
    }
}

void TextEditor::pauseSpeech() {
    if (speech->state() == QTextToSpeech::Speaking) {
        speech->pause();
    }
}

void TextEditor::stopSpeech() {
    speech->stop();
}

void TextEditor::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            textArea->setText(file.readAll());
            file.close();
        }
    }
}

void TextEditor::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save File");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << textArea->toPlainText();
            file.close();
        }
    }
}

void TextEditor::findText() {
    QString searchText = QInputDialog::getText(this, "Find", "Enter text to find:");
    if (!searchText.isEmpty()) {
        bool found = textArea->find(searchText);
        if (!found) {
            QMessageBox::information(this, "Find", "Text not found");
        }
    }
}

void TextEditor::replaceText() {
    QString searchText = QInputDialog::getText(this, "Replace", "Enter text to find:");
    if (!searchText.isEmpty()) {
        QString replaceText = QInputDialog::getText(this, "Replace", "Enter replacement text:");
        if (!replaceText.isEmpty()) {
            QString text = textArea->toPlainText();
            text.replace(searchText, replaceText);
            textArea->setPlainText(text);
        }
    }
}

void TextEditor::formatBold() {
    QTextCharFormat fmt;
    fmt.setFontWeight(textArea->fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);
    textArea->textCursor().mergeCharFormat(fmt);
}

void TextEditor::formatItalic() {
    QTextCharFormat fmt;
    fmt.setFontItalic(!textArea->fontItalic());
    textArea->textCursor().mergeCharFormat(fmt);
}

void TextEditor::formatUnderline() {
    QTextCharFormat fmt;
    fmt.setFontUnderline(!textArea->fontUnderline());
    textArea->textCursor().mergeCharFormat(fmt);
}

void TextEditor::undoAction() {
    textArea->undo();
}

void TextEditor::redoAction() {
    textArea->redo();
}

void TextEditor::convertToMarkdown() {
    // Implement Markdown conversion
}