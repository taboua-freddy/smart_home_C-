#include "vehiculeproprietaire.h"
#include <QSqlQueryModel>
#include <QDebug>

VehiculeProprietaire::VehiculeProprietaire():Vehicule()
{
    Matricule="";
    IdProprietaire=0;
    Marque="";
}

VehiculeProprietaire::VehiculeProprietaire(QString mat, int id, int numeroPlace, QString marque):Vehicule(numeroPlace)
{
    Matricule=mat;
    IdProprietaire=id;
    Marque=marque;
}

bool VehiculeProprietaire::ajouterVehicule()
{
    int n=0;
    QSqlQuery query;
    query.exec("select matricule from vehicule_proprietaire where matricule="+Matricule+"");
    while (query.next()) {
        n++;
    }

    if(n==0)
    {
        query.prepare("insert into vehicule_proprietaire (matricule,id,marque,numero_place) values (:matricule,:id,:marque,:numero_place)");
        query.bindValue(":matricule",Matricule);
        query.bindValue(":id",IdProprietaire);
        query.bindValue(":marque",Marque);
        query.bindValue(":numero_place",NumeroPlace);

        return query.exec();
    }
    else
        return 2;
}

bool VehiculeProprietaire::supprimerVehicule(QString matricule, int numero)
{
    QSqlQuery query;

    query.prepare("delete from vehicule_proprietaire where (matricule=:matricule or numero_place=:numero_place)");
    query.bindValue(":numero_place",numero);
    query.bindValue(":matricule",matricule);
    return query.exec();

}

int VehiculeProprietaire::modifierIdProprietaire(QString matricule, int numero, int id)
{

    QSqlQuery query;
    query.prepare("update vehicule_proprietaire set id=:id where (numero_place=:numero or matricule=:matricule)");
    query.bindValue(":id",id);
    query.bindValue(":matricule",matricule);
    query.bindValue(":numero",numero);
    return query.exec();

}

void VehiculeProprietaire::recupererNumeroMatriculePlace(int numero, QString mat, QString &matricule, int &numero_place)
{
    QSqlQuery query;
    query.prepare("select matricule,numero_place from vehicule_proprietaire where numero_place=:numero or matricule=:matricule");
    query.bindValue(":numero",numero);
    query.bindValue(":matricule",mat);
    query.exec();
    while (query.next()) {
            matricule=query.value(0).toString();
            numero_place=query.value(1).toInt();
    }

}

int VehiculeProprietaire::numeroPlace(int numero, QString matricule)
{
    int num;
    QSqlQuery query2;
    query2.prepare("select numero_place from vehicule_proprietaire where (matricule=:matricule or numero_place=:numero_place) ");
    query2.bindValue(":numero_place",numero);
    query2.bindValue(":matricule",matricule);
    query2.exec();
    while (query2.next()) {
         num=query2.value(0).toInt();
    }
    return num;
}
