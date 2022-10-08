#ifndef MEMBRE_H
#define MEMBRE_H
#include<QString>
#include<QSqlDatabase>
#include<QSqlError>
#include <QVariant>
#include <QSqlQuery>
#include <QTableWidget>
class Membre
{
public:
    Membre();
    Membre(int id,QString nom,QString prenom,QString motpass, QString email);
    bool verifierAdmin(int id);

    void setNom( QString nom);
    void setPrenom( QString prenom);
    void setMot_de_passe( QString mdp);
    void setId(int id);
    int getId();
    QString getNom();
    QString getPrenom();
    QString getMot_de_passe();
    bool Ajouter (int id,QString nom, QString prenom, QString mdp);
    void afficher(QTableWidget *);
    bool suprimer(int id);
    bool Modifier(QString mdp,int id);
    bool Historique(QTableWidget *t,int id,QString mdp);
    bool verifier(int id,QString mdp );
    bool verifier_existance(int id);
    void rechercher(QString,QTableWidget *t);
    void tri(QTableWidget *);
protected:
    int Id;
    QString Nom,Prenom;
    QString MotPass;
    QString Email;
};

#endif // MEMBRE_H
