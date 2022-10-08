#ifndef PORTE_H
#define PORTE_H
#include<QString>
#include<QSqlDatabase>
#include<QSqlError>
#include<QDebug>
#include<QSqlQuery>
#include<QMessageBox>
#include<QTableWidget>
#include"QSqlQueryModel"
class Porte
{  private:
    QString Reference ;
    QString Etat;
public:
    Porte();
    Porte(QString,QString);
    void setEtat(QString);
    QString getEtat();
    void setReference(QString );
    QString getReference();
    bool Ajouter(QString);
    void afficher(QTableWidget *);
    bool modifier();
};

#endif // PORTE_H
