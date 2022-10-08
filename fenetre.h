#ifndef FENETRE_H
#define FENETRE_H
#include<QString>
#include<QSqlDatabase>
#include<QSqlError>
#include<QDebug>
#include<QSqlQuery>
#include<QMessageBox>
#include<QTableWidget>
#include"QSqlQueryModel"

class Fenetre
{   private:
    QString Reference ;
    QString Etat;
public:
    Fenetre();
    Fenetre(QString,QString);
    void setEtat(QString);
    QString getEtat();
    void setReference(QString );
    QString getReference();
    bool Ajouter(QString);
    void afficher(QTableWidget *t);
};

#endif // FENETRE_H
