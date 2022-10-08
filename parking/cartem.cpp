#include "cartem.h"

CarteM::CarteM()
{
    Id=0;
    IdCarte="";
}

bool CarteM::AjouterCarte(int id, QString idcarte)
{
    QSqlQuery query;
    query.prepare("insert into carte_m(id,id_carte) values(:id,:id_carte)");
    query.bindValue(":id",id);
    query.bindValue(":id_carte",idcarte);
    return  query.exec();
}

bool CarteM::VerifierCarte(QString idcarte)
{
     QSqlQuery query;
     query.prepare("select id_carte from carte_m where id_carte=:id_carte");
     query.bindValue(":id_carte",idcarte);
     query.exec();
     while (query.next()) {
         return true;
     }
     return  false;
}
bool CarteM::supprimer(QString idcarte)
{
     QSqlQuery query;
     query.prepare("delete from carte_m where id_carte=:idcarte");
     query.bindValue(":idcarte",idcarte);
     return  query.exec();
}

QSqlQueryModel *CarteM::afficherCarte()
{
    QSqlQueryModel *model=new QSqlQueryModel ;
    model->setQuery("select id,id_carte from carte_m order by id");
    model->setHeaderData(0,Qt::Horizontal,"ID_RESIDENT");
    model->setHeaderData(1,Qt::Horizontal,"ID_CARTE_MAGNETIQUE");

    return  model;
}

int CarteM::getIdResident(QString idcarte)
{
    QSqlQuery query;
    query.prepare("select id from carte_m where id_carte=:id");
    query.bindValue(":id",idcarte);
    query.exec();
    while (query.next()) {
        return  query.value(0).toInt();
    }
}
