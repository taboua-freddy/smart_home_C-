#include "connexion.h"

Connexion::Connexion()
{

}
bool Connexion::ouvrirConnexion()
{
    db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("esprit18");//

    db.setUserName("system");
    db.setPassword("Freedom1");

/*    db.setDatabaseName("Source_Projet2A");
    db.setUserName("system");
    db.setPassword("Freedom1");

    db.setDatabaseName("projet_2a");
    db.setUserName("omar");
    db.setPassword("24551966");
*/
    return db.open();
}
void Connexion::fermerConnexion()
{
    db.close();
}
QSqlDatabase Connexion::getBase()
{
    return db;
}
