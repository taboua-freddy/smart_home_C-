#include "stylesheet.h"

StyleSheet::StyleSheet()
{
    f.setFileName(":/styleSheets/style1.txt");
    f.open(QFile::ReadOnly);
    QString style=QLatin1String(f.readAll());
    f.close();
    Style.push_back(style);
    f.setFileName(":/styleSheets/style2.txt");
    f.open(QFile::ReadOnly);
    style="";
    style=QLatin1String(f.readAll());
    f.close();
    Style.push_back(style);
}

QString StyleSheet::getStyleSheet(int numero)
{
    return  Style[numero];
}
