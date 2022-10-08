#ifndef VEHICULEPROPRIETAIRE_H
#define VEHICULEPROPRIETAIRE_H

#include "vehicule.h"
class VehiculeProprietaire:public Vehicule
{
public:
    VehiculeProprietaire();
    VehiculeProprietaire(QString mat,int id, int numeroPlace,QString marque);
    bool ajouterVehicule();
    bool supprimerVehicule(QString matricule,int numero);
    int modifierIdProprietaire(QString matricule,int numero, int id);
    void recupererNumeroMatriculePlace(int numero,QString mat,QString &matricule,int &numero_place);
    int numeroPlace(int numero ,QString matricule);
private:
    QString Matricule;
    int IdProprietaire;
    QString Marque;
};

#endif // VEHICULEPROPRIETAIRE_H
