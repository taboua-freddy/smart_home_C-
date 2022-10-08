#include "chambre.h"
#include "QMessageBox"
chambre::chambre()
{

}

chambre::chambre(QString nomdc,QString numdc,QString nbrlit,QString disponnibilite,QString luminosite,QString temperature)
{
    this->numdc=numdc;
    this->nomdc=nomdc;
    this->nbrlit=nbrlit;
    this->disponnibilite=disponnibilite;
    this->luminosite=luminosite;
    this->temperature=temperature;
}
QSqlQuery *chambre::getQ() const
{
    return q;
}

void chambre::setQ(QSqlQuery *value)
{
    q = value;
}


/***Fonction ajouter***/
void chambre::ajouter_c()
{
    q=new QSqlQuery();
    q->prepare("INSERT INTO CHAMBRE (NUMDC,NOMDC,NBRLIT,DISPO,LUMI,TMP) values(?,?,?,?,?,?)");
    q->addBindValue(numdc);
    q->addBindValue(nomdc);
    q->addBindValue(nbrlit);
    q->addBindValue(disponnibilite);
    q->addBindValue(luminosite);
    q->addBindValue(temperature);
    q->exec();
    qDebug () << q->last();





}

/***Fonction modifier les coordonéé d'une chambre donnée par son id ***/
void chambre::modifier_c()
{
    QSqlQuery q,qq;


  q.prepare("select * from CHAMBRE where NUMDC='"+numdc+"'");
    q.exec();
    if(q.next()==false)
    {

    }

    qq.prepare("UPDATE CHAMBRE SET DISPO='"+disponnibilite+"',LUMI='"+luminosite+"',TMP='"+temperature+"' WHERE NUMDC=? ") ;

    qq.addBindValue(numdc);

    qq.addBindValue(disponnibilite);
    qq.addBindValue(luminosite);
    qq.addBindValue(temperature);
    qq.exec();






}
/***Fonction supprimer les coordonéé d'une chambre donnée par son id ***/
void chambre::supprimer_c(QString numdc)
{
    QSqlQuery qq;



    qq.prepare("delete from CHAMBRE WHERE NUMDC =:numdc");
    qq.addBindValue(numdc);

    qq.exec();

}
/***Fonction afficher***/
QSqlQueryModel* chambre::afficher_c()
 {
    model =new QSqlQueryModel();
    q  = new QSqlQuery();
    q->prepare("SELECT * FROM CHAMBRE");
    q->exec();
    model->setQuery(*q);
    return model ;
}

/***fonction tier selon l'id**/
 QSqlQueryModel* chambre::tri_chambre()
{
   model =new QSqlQueryModel();
  q  = new QSqlQuery();
  q->prepare("SELECT * FROM CHAMBRE order by NUMDC");
  q->exec();
  model->setQuery(*q);
  return model ;
}
 /***Fonction trier selon la disonnibilité***/
 QSqlQueryModel* chambre::tri_chambre_dispo()
{
   model =new QSqlQueryModel();
  q  = new QSqlQuery();
  q->prepare("SELECT * FROM CHAMBRE order by DISPO asc ");
  q->exec();
  model->setQuery(*q);
  return model ;
}
/***Fonction recherche avancé***/
 QSqlQueryModel* chambre::rechercher_chambre(const QString &str)
 {

          QSqlQueryModel * model=new QSqlQueryModel() ;
          QSqlQuery q;
  q.prepare("SELECT * FROM CHAMBRE where (NUMDC LIKE '"+str+"%' OR NOMDC LIKE '"+str+"%' OR DISPO LIKE '"+str+"%' OR LUMI LIKE '"+str+"%' OR TMP LIKE '"+str+"%')")  ;
     q.exec() ;
     model->setQuery(q);
     return model;

 }


