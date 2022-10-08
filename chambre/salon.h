#ifndef SALON_H
#define SALON_H

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
class salon
{
public:
    QSqlQuery *q;

        salon();

        salon(QString nomds,QString numds,QString nbrm,QString luminosit,QString temperatur);
        QSqlQueryModel *model;

        void set_NOMDS(QString nds){nomds=nds;}
        void set_NUMDS(QString nms){numds=nms;}
        void set_NRBM(QString nbr){nbrm=nbr;}
        void set_LUMINO(QString lum){luminosit=lum;}
        void set_TMP(QString temp){temperatur=temp;}
        QString get_NOMDS(){return nomds;}
        QString get_NUMDS(){return numds;}
        QString get_NBRM(){return nbrm;}

        QString get_LUMINO(){return  luminosit;}
        QString get_TMP(){return temperatur;}

        bool ajouter_s();
        bool modifier_s();
        bool supprimer_s(QString numds);
        QSqlQueryModel* afficher_s();
        QSqlQueryModel* tri_salon();
        QSqlQueryModel* tri_salon_meuble();
        QSqlQueryModel* rechercher_salon(const QString &str);
    private:
    QString nomds,numds,nbrm,luminosit,temperatur;

    QSqlQuery *getQ() const;
     void setQ(QSqlQuery *value);
};

#endif // SALON_H
