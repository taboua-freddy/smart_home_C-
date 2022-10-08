#include "porte.h"

Porte::Porte()
{
     Reference="p";
     Etat="";
}
Porte::Porte(QString ref,QString etat)
{
    Reference=ref;
    Etat=etat;
}
void Porte::setEtat(QString etat)
{Etat=etat;}
QString Porte::getEtat()
{return Etat;}
void Porte::setReference(QString ref)
{Reference=ref;}
QString Porte::getReference()
{return Reference;}

bool Porte::Ajouter(QString etat)

{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Porte");
    int num=model->rowCount()+1;
    QString Reference="p"+QString::number(num);
    QSqlQuery query;
    qDebug()<<Reference;
    query.prepare("Insert INTO Porte(Reference,Etat) VALUES(?,?)");
    query.addBindValue(Reference);
    query.addBindValue(etat);
    if(query.exec()){

    return  true;}

    return  false;
}
void Porte::afficher(QTableWidget *t)
{
    QSqlQuery qry;
    int i;
    int j=0;
    qry.exec("select * from Porte");
    while(qry.next()){
        j++;
    }
    t->setRowCount(j);
    t->setColumnCount(2);
    t->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    t->setHorizontalHeaderLabels(QString("Etat;Reference").split(";"));
    i=1;
    qry.exec("select* from  Porte");
    while(qry.next())
    {
               t->setItem(i-1,0,new QTableWidgetItem(qry.value(0).toString()));
               t->setItem(i-1,1,new QTableWidgetItem(qry.value(1).toString()));

    i++;
    }

}
bool Porte::modifier()
{   QString etat="ouvure";
    QString et="fermer";
      QSqlQuery query;
      while(query.next()){
      query.prepare("Update  Porte set Etat=:etat where Etat=:et ");
      query.bindValue(":etat",etat);
      return query.exec();}
}

