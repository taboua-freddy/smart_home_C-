#ifndef CHAMBRE_H
#define CHAMBRE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSql>
#include <QDebug>
#include <QDate>
#include <QVector>
#include <QTableView>
//#include "notification.h"
class chambre
{
public:
    QSqlQuery *q;

    chambre();

    chambre(QString nomdc,QString numdc,QString nbrlit,QString disponnibilite,QString luminosite,QString temperature);
    QSqlQueryModel *model;

    void set_NOMDC(QString ndc){nomdc=ndc;}
    void set_NUMDC(QString nmc){numdc=nmc;}
    void set_NRBLIT(QString nbr){nbrlit=nbr;}
    void set_DISPO(QString dispo){disponnibilite=dispo;}
    void set_LUMINO(QString lum){luminosite=lum;}
    void set_TMP(QString temp){temperature=temp;}
    QString get_NOMDC(){return nomdc;}
    QString get_NUMDC(){return numdc;}
    QString get_NBRLIT(){return nbrlit;}
    QString get_DISPO(){return disponnibilite;}
    QString get_LUMINO(){return  luminosite;}
    QString get_TMP(){return temperature;}

    void ajouter_c();
    void modifier_c();
    void supprimer_c(QString numdc);
    QSqlQueryModel* afficher_c();
    QSqlQueryModel* tri_chambre();
    QSqlQueryModel* tri_chambre_dispo();
    QSqlQueryModel* rechercher_chambre(const QString &str);
private:
QString nomdc,numdc,nbrlit,disponnibilite,luminosite,temperature;

QSqlQuery *getQ() const;
 void setQ(QSqlQuery *value);
 //notification *n;
};

#endif // CHAMBRE_H
