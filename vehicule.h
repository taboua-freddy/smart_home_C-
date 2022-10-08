#ifndef VEHICULE_H
#define VEHICULE_H

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include "connexion.h"
class Vehicule
{
public:
    Vehicule();
    Vehicule(int numero);
    int ajouterVehicule();
    bool supprimerVehicule(int numero);
    bool supprimerInvite();
    int getNumeroPlace();
protected:
    int NumeroPlace;
};

#endif // VEHICULE_H
