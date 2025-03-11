#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegularExpression>

class SyntaxHighlighter : public QSyntaxHighlighter {
    Q_OBJECT

public:
    explicit SyntaxHighlighter(QTextDocument *parent = nullptr);
    ~SyntaxHighlighter();  
protected:
    void highlightBlock(const QString &text) override;
};

#endif // SYNTAXHIGHLIGHTER_H
