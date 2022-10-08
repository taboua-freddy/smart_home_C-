#include "fenetre.h"

Fenetre::Fenetre()
{
     Reference="p";
     Etat="";
}
Fenetre::Fenetre(QString ref,QString etat)
{
    Reference=ref;
    Etat=etat;
}
void Fenetre::setEtat(QString etat)
{Etat=etat;}
QString Fenetre::getEtat()
{return Etat;}
void Fenetre::setReference(QString ref)
{Reference=ref;}
QString Fenetre::getReference()
{return Reference;}

bool Fenetre::Ajouter(QString etat)

{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Fenetre");
    int num=model->rowCount()+1;
    QString Reference="p"+QString::number(num);
    QSqlQuery query;
    qDebug()<<Reference;
    query.prepare("Insert INTO Fenetre(Reference,Etat) VALUES(?,?)");
    query.addBindValue(Reference);
    query.addBindValue(etat);
    if(query.exec()){

    return  true;}

    return  false;
}
void Fenetre::afficher(QTableWidget *t)
{
    QSqlQuery qry;
    int i;
    int j=0;
    qry.exec("select * from Fenetre");
    while(qry.next()){
        j++;
    }
    t->setRowCount(j);
    t->setColumnCount(2);
    t->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    t->setHorizontalHeaderLabels(QString("Etat;Reference").split(";"));
    i=1;
    qry.exec("select* from  Fenetre");
    while(qry.next())
    {
               t->setItem(i-1,0,new QTableWidgetItem(qry.value(0).toString()));
               t->setItem(i-1,1,new QTableWidgetItem(qry.value(1).toString()));

    i++;
    }

}
