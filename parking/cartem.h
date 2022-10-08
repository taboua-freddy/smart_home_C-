#ifndef CARTEM_H
#define CARTEM_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class CarteM
{
public:
    CarteM();
    bool AjouterCarte(int id,QString idcarte);
    bool VerifierCarte(QString idcarte);
    bool supprimer(QString idcarte);
    QSqlQueryModel * afficherCarte();
    int getIdResident(QString idcarte);
private:
    int Id;
    QString IdCarte;

};

#endif // CARTEM_H
