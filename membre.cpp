#include"membre.h"
//#include "connexion.h"
#include<QTime>
Membre::Membre()
{
    Nom="";
    Prenom="";
    MotPass="";
    Id=0;
}
Membre::Membre( int id,QString nom, QString prenom, QString mdp,QString email)
{
    Id=id;
    Nom=nom;
    Prenom=prenom;
    MotPass=mdp;
    Email=email;
}
void Membre::setNom(QString nom)
{
    Nom=nom;
}
void Membre::setPrenom(QString prenom)
{
    Prenom=prenom;
}
void Membre::setMot_de_passe(QString mdp)
{
    MotPass=mdp;
}
QString Membre ::getNom()
{
    return Nom;
}
QString Membre ::getPrenom()
{
    return Prenom;
}
QString Membre ::getMot_de_passe()
{
    return MotPass;
}
void Membre::setId(int id)
{
    Id=id;

}
int Membre::getId()
{

    return  Id;
}
bool Membre::Ajouter(int id, QString nom, QString prenom, QString mdp )
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Insert INTO Membre(Id,Nom,Prenom,MotPass) VALUES(?,?,?,?)");
    query.addBindValue(res);
    query.addBindValue(nom) ;
    query.addBindValue(prenom);
    query.addBindValue(mdp);
    if(query.exec())
    return  true;

    return  false;
}
bool Membre::verifierAdmin(int id)
{
    QSqlQuery query;
    query.prepare("select id from admin where id=:id");
    query.bindValue(":id",id);
    query.exec();
    while (query.next()) {
        if(query.value(0).toInt()==id)
            return  true;
    }

    return  false;
}
void Membre::afficher(QTableWidget *t)
{
    QSqlQuery qry;
    int i;
    int j=0;
    qry.exec("select * from Membre");
    while(qry.next()){
        j++;
    }
    t->setRowCount(j);
    t->setColumnCount(4);
    t->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    t->setHorizontalHeaderLabels(QString("Id;Nom;Prenom;MotPass").split(";"));
    i=1;
    qry.exec("select* from  Membre");
    while(qry.next())
    {
               t->setItem(i-1,0,new QTableWidgetItem(qry.value(0).toString()));
               t->setItem(i-1,1,new QTableWidgetItem(qry.value(1).toString()));
               t->setItem(i-1,2,new QTableWidgetItem(qry.value(2).toString()));
               t->setItem(i-1,3,new QTableWidgetItem(qry.value(3).toString()));
    i++;
    }

}
bool Membre::suprimer(int id)
{
    QSqlQuery query;
    QString res=QString ::number(id);
    query.prepare("Delete from Membre where Id=:id");
    query.addBindValue(res);
    return  query.exec();


}
bool Membre::Modifier(QString mdp,int id)
{
      QSqlQuery query;
      query.prepare("Update Membre set MotPass=:mdp where Id=:id");
      setMot_de_passe(mdp);
      query.bindValue(":mdp",mdp);
      query.bindValue(":id",id);
      return query.exec();
}
bool Membre::Historique(QTableWidget *t,int id,QString mdp)
{   if(verifier(id,mdp))
    {
    QSqlQuery qry;
    QDate date;
    t->setRowCount(25);
    t->setColumnCount(2);
    t->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    t->setHorizontalHeaderLabels(QString("Nom;Date").split(";"));
    int i=1;
               t->setItem(i-1,0,new QTableWidgetItem(QString::number(id)));
               t->setItem(i-1,1,new QTableWidgetItem(date.currentDate().toString()));

i++;
return true;
    }
    return  false ;
}
bool Membre::verifier(int id ,QString mdp)
{

    QSqlQuery qry;
    qry.exec("select * from Membre");
    while (qry.next())
    {
        if(id==qry.value(0) && mdp==qry.value(3).toString())
            return true;
    }
    return false;
}
bool Membre::verifier_existance(int id)
{

    QSqlQuery qry;
    qry.exec("select * from Membre");
    while (qry.next())
    {
        if(id==qry.value(0) )
            return true;
    }
    return false;
}
void Membre::rechercher(QString r,QTableWidget *t)
{
    QSqlQuery qry;
    int i;
    int j=0;
    qry.exec("select * from Membre where id like '%"+r+"%' or nom like '%"+r+"%' or prenom like '%"+r+"%' or MotPass like '%"+r+"%'");
    while(qry.next()){
        j++;
    }
    t->setRowCount(j);
    t->setColumnCount(4);
    t->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    t->setHorizontalHeaderLabels(QString("Id;Nom;Prenom;MotPass").split(";"));
    i=1;
    qry.exec("select * from Membre where id like '%"+r+"%' or nom like '%"+r+"%' or prenom like '%"+r+"%' or MotPass like '%"+r+"%'");
    while(qry.next())
    {
               t->setItem(i-1,0,new QTableWidgetItem(qry.value(0).toString()));
               t->setItem(i-1,1,new QTableWidgetItem(qry.value(1).toString()));
               t->setItem(i-1,2,new QTableWidgetItem(qry.value(2).toString()));
               t->setItem(i-1,3,new QTableWidgetItem(qry.value(3).toString()));
    i++;
    }

}
void Membre::tri(QTableWidget *t)
{
    QSqlQuery qry;
    int i;
    int j=0;
    qry.exec("select * from Membre");
    while(qry.next()){
        j++;
    }
    t->setRowCount(j);
    t->setColumnCount(4);
    t->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    t->setHorizontalHeaderLabels(QString("Id;Nom;Prenom;MotPass").split(";"));
    i=1;
    qry.exec("select* from  Membre order by Prenom ASC");
    while(qry.next())
    {
               t->setItem(i-1,0,new QTableWidgetItem(qry.value(0).toString()));
               t->setItem(i-1,1,new QTableWidgetItem(qry.value(1).toString()));
               t->setItem(i-1,2,new QTableWidgetItem(qry.value(2).toString()));
               t->setItem(i-1,3,new QTableWidgetItem(qry.value(3).toString()));
    i++;
    }

}
