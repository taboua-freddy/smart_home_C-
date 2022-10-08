#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlDatabase>

class Connexion
{
public:
    Connexion();
    bool ouvrirConnexion();
    void fermerConnexion();
    QSqlDatabase getBase();
private:
    QSqlDatabase db;
};

#endif // CONNEXION_H
