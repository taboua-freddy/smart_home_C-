#include"membre.h"
//#include "connexion.h"
#include<QTime>
#include<QSqlQueryModel>
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
bool Membre::Ajouter(QString nom, QString prenom, QString mdp, QString email )
{
    QSqlQuery query;
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Membre");
    int num=model->rowCount()+1;
    int res=0;
    res=num+1000;
    query.prepare("Insert INTO Membre(Id,Nom,Prenom,MotPass,Email) VALUES(?,?,?,?,?)");
    query.addBindValue(res);
    query.addBindValue(nom) ;
    query.addBindValue(prenom);
    query.addBindValue(mdp);
    query.addBindValue(email);
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
    t->setColumnCount(5);
    t->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    t->setHorizontalHeaderLabels(QString("Id;Nom;Prenom;MotPass;Email").split(";"));
    i=1;
    qry.exec("select* from  Membre");
    while(qry.next())
    {
               t->setItem(i-1,0,new QTableWidgetItem(qry.value(0).toString()));
               t->setItem(i-1,1,new QTableWidgetItem(qry.value(1).toString()));
               t->setItem(i-1,2,new QTableWidgetItem(qry.value(2).toString()));
               t->setItem(i-1,3,new QTableWidgetItem(qry.value(3).toString()));
               t->setItem(i-1,4,new QTableWidgetItem(qry.value(4).toString()));

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
bool Membre::Historique(int id,QDate date)
{
    QSqlQuery qry;
        qry.prepare("Insert INTO historique_login(Nom,Datte) VALUES(?,?)");
        qry.addBindValue(id);
        qry.addBindValue(date);
        if(qry.exec())
        return  true;

    return  false ;
}
void Membre::afficher_historique(QTableWidget *t)
{
    QSqlQuery qry;

        int i;
        int j=0;
        qry.exec("select * from Historique_login");
        while(qry.next()){
            j++;
        }
        t->setRowCount(j);
        t->setColumnCount(2);
        t->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        t->setHorizontalHeaderLabels(QString("Nom;Date               ").split(";"));
        i=1;
        qry.exec("select* from  Historique_login");
        while(qry.next())
        {
                   t->setItem(i-1,0,new QTableWidgetItem(qry.value(0).toString()));
                   t->setItem(i-1,1,new QTableWidgetItem(qry.value(1).toString()));


        i++;}

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
    qry.exec("select * from Membre where id like '%"+r+"%' or nom like '%"+r+"%' or prenom like '%"+r+"%' or MotPass like '%"+r+"%'or Email like '%"+r+"%'");
    while(qry.next()){
        j++;
    }
    t->setRowCount(j);
    t->setColumnCount(5);
    t->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    t->setHorizontalHeaderLabels(QString("Id;Nom;Prenom;MotPass").split(";"));
    i=1;
    qry.exec("select * from Membre where id like '%"+r+"%' or nom like '%"+r+"%' or prenom like '%"+r+"%' or MotPass like '%"+r+"%'or Email like '%"+r+"%'");
    while(qry.next())
    {
               t->setItem(i-1,0,new QTableWidgetItem(qry.value(0).toString()));
               t->setItem(i-1,1,new QTableWidgetItem(qry.value(1).toString()));
               t->setItem(i-1,2,new QTableWidgetItem(qry.value(2).toString()));
               t->setItem(i-1,3,new QTableWidgetItem(qry.value(3).toString()));
               t->setItem(i-1,4,new QTableWidgetItem(qry.value(4).toString()));

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
    t->setColumnCount(5);
    t->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    t->setHorizontalHeaderLabels(QString("Id;Nom;Prenom;MotPass;Email").split(";"));
    i=1;
    qry.exec("select* from  Membre order by Id ASC");
    while(qry.next())
    {
               t->setItem(i-1,0,new QTableWidgetItem(qry.value(0).toString()));
               t->setItem(i-1,1,new QTableWidgetItem(qry.value(1).toString()));
               t->setItem(i-1,2,new QTableWidgetItem(qry.value(2).toString()));
               t->setItem(i-1,3,new QTableWidgetItem(qry.value(3).toString()));
               t->setItem(i-1,4,new QTableWidgetItem(qry.value(4).toString()));


    i++;
    }

}
