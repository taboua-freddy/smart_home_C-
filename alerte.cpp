#include "alerte.h"
#include <QDateTime>
#include <QSqlQuery>
Alerte::Alerte()
{
    IdAlerte=0;
    Motif="";
    Motif="";
}

Alerte::Alerte(int idAlerte, QString motif, QString dateAlerte)
{
    IdAlerte=idAlerte;
    Motif=motif;
    DateAlerte=dateAlerte;
}

bool Alerte::ajouterAlerte(QString motif)
{
    int ajout=0,existe,num=100;
    QSqlQuery query;

    DateAlerte=QDateTime::currentDateTime().toString("dd/MM/yy");

    while (!ajout) {
        existe=0;

        query.prepare("select id_alerte from alerte where id_alerte=:id");
        query.bindValue(":id",num);
        query.exec();
        while (query.next()) {
            existe=1;
        }

        if(existe==0)
        {
            query.prepare("insert into alerte (id_alerte,date_alerte,motif) values (:id_alerte,TO_DATE(:date_alerte,'DD/MM/YY'),:motif)");
            query.bindValue(":id_alerte",num);
            query.bindValue(":date_alerte",DateAlerte);
            query.bindValue(":motif",motif);
            return query.exec();
        }
        num++;
    }
}

QSqlQueryModel *Alerte::afficherAlerte()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select id_alerte,TO_CHAR(date_alerte,'DD/MM/YYYY'),motif from alerte order by date_alerte desc");
    model->setHeaderData(0,Qt::Horizontal,"ID_ALERTE");
    model->setHeaderData(1,Qt::Horizontal,"DATE");
    model->setHeaderData(3,Qt::Horizontal,"MOTIF");

    return  model;
}

void Alerte::supprimerAlerte()
{
    QSqlQuery query;
    query.exec("delete from alerte");
}


