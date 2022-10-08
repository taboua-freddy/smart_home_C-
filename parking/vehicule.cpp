#include "vehicule.h"
#include <QMessageBox>
Vehicule::Vehicule()
{
    NumeroPlace=0;
}
Vehicule::Vehicule(int numero)
{
    NumeroPlace=numero;

}
int Vehicule::ajouterVehicule()
{

    int n=0;
    QSqlQuery query;
    QString numero;
    numero=QString::number(NumeroPlace);
    query.prepare("select numero_place from vehicule where numero_place=:numero_place");
    query.bindValue(":numero_place",numero);
    query.exec();
    while (query.next()) {
        n++;
    }
    if(n==0)
    {
        query.prepare("insert into vehicule (numero_place) values (:numero_place)");
        query.bindValue(":numero_place",numero);
        return query.exec();
    }

    return false;
}

bool Vehicule::supprimerVehicule(int numero)
{
    QSqlQuery query;
    query.prepare("delete from vehicule where numero_place=:numero");
    query.bindValue(":numero",numero);
    return query.exec();
}

bool Vehicule::supprimerInvite()
{
    QSqlQuery query,query2;
        query.prepare("select numero_place from place_parking where type='invite'");
        query.exec();
        while (query.next()) {
            query2.prepare("delete from vehicule where numero_place=:numero");
            query2.bindValue(":numero",query.value(0).toInt());
            query2.exec();
        }
}
QSqlQueryModel* Vehicule::getId()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select id from membre order by id");

    return model;
}

QSqlQueryModel *Vehicule::afficherNumeroPlaceProp(int id, bool prop)
{
    QSqlQueryModel *model = new QSqlQueryModel;
    if(prop)
        model->setQuery("select numero_place from vehicule_proprietaire where id="+QString::number(id)+" order by numero_place");
    else
        model->setQuery("select numero_place from vehicule_proprietaire order by numero_place");
    return  model;
}
int Vehicule::getNumeroPlace()
{
    return  NumeroPlace;
}
