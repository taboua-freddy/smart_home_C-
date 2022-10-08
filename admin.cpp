#include "admin.h"
#include<QTableWidget>
#include <QDebug>

Admin::Admin(): Membre()
{
    Autorite="";
}
Admin::Admin(int id, QString nom, QString prenom, QString mdp, QString email, QString autorite):Membre( id,nom,prenom, mdp,email)
{
    Autorite=autorite;
}

bool Admin::Ajouter()
{
   Membre m;
  // m.Ajouter(Id,Nom,Prenom,Mot_de_passe);

    QSqlQuery query;
   QString res= QString::number(Id);
    query.prepare("Insert INTO Admin(Id,Nom,Prenom,Mot_de_passe,Autorite) VALUES(?,?,?,?,?)");
    query.addBindValue(res);
    query.addBindValue(Nom);
    query.addBindValue(Prenom);
    query.addBindValue(MotPass);
    query.addBindValue(Autorite);
    if(query.exec())
    return  true;

    return  false;

}
void Admin::afficher(QTableWidget *t)
{
    QSqlQuery qry;
    int i;
    int j=0;
    qry.exec("select * from Admin");
    while(qry.next()){
        j++;
    }
    t->setRowCount(j);
    t->setColumnCount(5);
    t->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    t->setHorizontalHeaderLabels(QString("Auorite;Id;Nom;Prenom;Mot_de_passe").split(";"));
    i=1;
    qry.exec("select* from  Admin");
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
bool Admin::suprimer(int id)
{

    QSqlQuery query;
   // QString res=QString ::number(id);
    query.prepare("Delete from Admin where Id=?");
    query.addBindValue(id);
    return  query.exec();



}
bool Admin::verifier_admin(int id ,QString mdp)
{
    QSqlQuery qry;
    qry.exec("select * from Admin");
    while (qry.next())
    {
        qDebug()<<  qry.value(4).toString();
        if(id==qry.value(1) && mdp==qry.value(4).toString())
        {
            return true;}
    }
    return false;
}
bool Admin::ajouter_membre_listAdmin(int id)
{    QSqlQuery qry,gr;
            Membre m;
             QString var=QString::number(id);
              qDebug()<<var;
    qry.exec("select * from Membre where id ='"+var+"'");
    if(qry.next())
    {
    qDebug()<<qry.value(1);
        Admin a(id,qry.value(1).toString(),qry.value(2).toString(),"email",qry.value(3).toString(),"admin");
        a.Ajouter();
        return true;
    }

    return  false;

}

