#ifndef ADMIN_H
#define ADMIN_H
#include"membre.h"
#include<QTableWidget>

class Admin:public Membre
{private:
    QString Autorite;
public:
    Admin();
    Admin(int id,QString nom, QString prenom, QString mdp,QString email,QString autorite);
    void setAutorite(QString );
    QString getAutorite();
    bool Ajouter();
    void afficher(QTableWidget *);
    bool suprimer(int id);
    bool verifier_admin(int id ,QString mdp);
    bool ajouter_membre_listAdmin(int id);
};

#endif // ADMIN_H
