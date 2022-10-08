#include "historique.h"

Historique::Historique()
{
    IdHist=0;
    DateHist="";
    HeureHist="";
    Id=0;
    Action="";
}

bool Historique::ajouterHistorique(int id, QString action)
{
    int ajout=0,existe,num=100;
    QSqlQuery query;

    DateHist=QDateTime::currentDateTime().toString("dd/MM/yy");
    HeureHist=QDateTime::currentDateTime().toString("hh:mm:ss");

    while (!ajout) {
        existe=0;

        query.prepare("select id_hist from historique where id_hist=:id_hist");
        query.bindValue(":id_hist",num);
        query.exec();
        while (query.next()) {
            existe=1;
        }

        if(existe==0)
        {
            query.prepare("insert into historique (id_hist,date_hist,heure_hist,id,action) values (:id_hist,TO_DATE(:date_hist,'DD/MM/YY'),:heure_hist,:id,:action)");
            query.bindValue(":id_hist",num);
            query.bindValue(":date_hist",DateHist);
            query.bindValue(":heure_hist",HeureHist);
            query.bindValue(":id",id);
            query.bindValue(":action",action);
            return query.exec();
            ajout++;
        }
        num++;
    }
}

QSqlQueryModel *Historique::afficherHistorique()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select h.id_hist,TO_CHAR(h.date_hist,'DD/MM/YYYY'),h.heure_hist,h.action,m.nom from historique h left outer join "
                    "membre m on h.id=m.id order by h.date_hist desc,h.heure_hist desc");
    model->setHeaderData(0,Qt::Horizontal,"ID_HIST");
    model->setHeaderData(1,Qt::Horizontal,"DATE");
    model->setHeaderData(2,Qt::Horizontal,"HEURE");
    model->setHeaderData(3,Qt::Horizontal,"ACTION");
    model->setHeaderData(4,Qt::Horizontal,"ACTEUR");

    return  model;
}

bool Historique::supprimerAllHistorique()
{
    QSqlQuery query;
    return query.exec("delete from historique");
}

bool Historique::supprimerIntervalleHistorique(QString debut, QString fin)
{
    QSqlQuery query;
    query.prepare("delete from historique where date_hist between TO_DATE(:debut,'DD/MM/YY') and TO_DATE(:fin,'DD/MM/YY')");
    query.bindValue(":debut",debut);
    query.bindValue(":fin",fin);
    return  query.exec();
}

QSqlQueryModel *Historique::rechercheRapide(QString valeur)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select h.id_hist,TO_CHAR(h.date_hist,'DD/MM/YYYY'),h.heure_hist,h.action,m.nom from historique h left outer join "
                    "membre m on h.id=m.id where (h.id_hist like '%"+valeur+"%' or TO_CHAR(h.date_hist,'DD/MM/YYYY') like '%"+valeur+"%'"
                    " or h.heure_hist like '%"+valeur+"%' or m.nom like '%"+valeur+"%' or h.action like '%"+valeur+"%' ) "
                    "order by h.date_hist desc,h.heure_hist desc");
    model->setHeaderData(0,Qt::Horizontal,"ID_HIST");
    model->setHeaderData(1,Qt::Horizontal,"DATE");
    model->setHeaderData(2,Qt::Horizontal,"HEURE");
    model->setHeaderData(3,Qt::Horizontal,"ACTION");
    model->setHeaderData(4,Qt::Horizontal,"ACTEUR");

    return  model;
}
