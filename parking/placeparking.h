#ifndef PLACEPARKING_H
#define PLACEPARKING_H

#include <QString>
#include <QSqlQueryModel>
class PlaceParking
{
public:
    PlaceParking();
    PlaceParking(int numero,QString etat,QString type);
    void ajouterPlace(int nombre_place);
    bool ajouterVehiculeSurParking(int numero_place,QString type,QString etat); //et suppression
    void nbrPlaces(int* total, int* invite, int *propritaire, int *invitep,int *proprietairep);
    int calculerNbrPlace();
    bool verifierProprietaire(int numero, QString matricule, int idPro);
    bool supprimerToutesPlaceInvite();
    QSqlQueryModel * emplacementVIde();
    QSqlQueryModel * afficherParking();
    QString getEtat(){return Etat;}
    QString getType(){return Type;}
    int getNumero(){return NumeroPlace;}
    bool supprimerPlace(int numero_place, QString etat);
    bool supprimerPlaceLibre();
    QSqlQueryModel * rechercheRapide(QString valeur);
    bool garerVehicule(QString matricule);
    bool envoyerAlerte();
    bool modifierEtatParking(int numero_place);
    int recupererEtat(int numero);
    void getInfoMembre(int id, QString &email, QString &nom);
    bool modifierEtatParkingCapteur(int numero_place, QString Nvetat);
private:
    int NumeroPlace;
    QString Etat; //true pour occupe et false pour libre
    QString Type; //invite ou proprietaire

};

#endif // PLACEPARKING_H
