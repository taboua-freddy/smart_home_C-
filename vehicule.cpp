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
    query.exec("select numero_place from vehicule where (numero_place="+numero+")");
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

int Vehicule::getNumeroPlace()
{
    return  NumeroPlace;
}
