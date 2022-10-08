#ifndef STYLESHEET_H
#define STYLESHEET_H

#include <QFile>
#include <QVector>
class StyleSheet
{
public:
    StyleSheet();
    QString getStyleSheet(int numero);
private:
    QFile f;
    QVector <QString> Style;
};

#endif // STYLESHEET_H
