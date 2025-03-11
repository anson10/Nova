#include "SyntaxHighlighter.h"
#include <QTextCharFormat>
#include <QRegularExpression>

SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent) {}

SyntaxHighlighter::~SyntaxHighlighter() {}

void SyntaxHighlighter::highlightBlock(const QString &text) {
    QTextCharFormat keywordFormat;
    keywordFormat.setForeground(Qt::blue);
    keywordFormat.setFontWeight(QFont::Bold);

    QStringList keywords = {"int", "float", "return", "if", "else", "while", "for", "void", "double"};
    
    for (const QString &keyword : keywords) {
        QRegularExpression pattern("\\b" + keyword + "\\b");
        QRegularExpressionMatchIterator matchIterator = pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), keywordFormat);
        }
    }
}
