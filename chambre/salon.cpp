#include "salon.h"

salon::salon()
{

}


salon::salon(QString nomds,QString numds,QString nbrm,QString luminosit,QString temperatur)
{
    this->numds=numds;
    this->nomds=nomds;
    this->nbrm=nbrm;
    this->luminosit=luminosit;
    this->temperatur=temperatur;
}
QSqlQuery *salon::getQ() const
{
    return q;
}

void salon::setQ(QSqlQuery *value)
{
    q = value;
}


/***Fonction ajouter***/
bool salon::ajouter_s()
{
    q=new QSqlQuery();
    q->prepare("INSERT INTO SALLON (IDS,NMS,NBRM,LUMIN,TMPE) values(?,?,?,?,?)");
    q->addBindValue(numds);
    q->addBindValue(nomds);
    q->addBindValue(nbrm);
    q->addBindValue(luminosit);
    q->addBindValue(temperatur);
    q->exec();
    qDebug () << q->last();
    return true;
}

/***Fonction modifier les coordonéé d'une chambre donnée par son id ***/
bool salon::modifier_s()
{
    QSqlQuery q,qq;


  q.prepare("select * from SALLON where IDS='"+numds+"'");
    q.exec();
    if(q.next()==false)
    {
        return 1;
    }

    qq.prepare("UPDATE SALLON SET LUMIN='"+luminosit+"',TMPE='"+temperatur+"' WHERE IDS=? ") ;

    qq.addBindValue(numds);
    qq.addBindValue(nomds);
    qq.addBindValue(nbrm);

    qq.addBindValue(luminosit);
    qq.addBindValue(temperatur);
    qq.exec();

    return 0;




}
/***Fonction supprimer les coordonéé d'une chambre donnée par son id ***/
bool salon::supprimer_s(QString numds)
{
    QSqlQuery qq;



    qq.prepare("delete from SALLON WHERE IDS =:numds");
    qq.addBindValue(numds);

    qq.exec();
    return  true;
}
/***Fonction afficher***/
QSqlQueryModel* salon::afficher_s()
 {
    model =new QSqlQueryModel();
    q  = new QSqlQuery();
    q->prepare("SELECT * FROM SALLON");
    q->exec();
    model->setQuery(*q);
    return model ;
}

/***fonction tier selon l'id**/
 QSqlQueryModel* salon::tri_salon()
{
   model =new QSqlQueryModel();
  q  = new QSqlQuery();
  q->prepare("SELECT * FROM SALLON order by IDS");
  q->exec();
  model->setQuery(*q);
  return model ;
}
 /***Fonction trier selon la disonnibilité***/
 QSqlQueryModel* salon::tri_salon_meuble()
{
   model =new QSqlQueryModel();
  q  = new QSqlQuery();
  q->prepare("SELECT * FROM SALLON order by NBRM  ");
  q->exec();
  model->setQuery(*q);
  return model ;
}
/***Fonction recherche avancé***/
 QSqlQueryModel* salon::rechercher_salon(const QString &str)
 {

          QSqlQueryModel * model=new QSqlQueryModel() ;
          QSqlQuery q;
  q.prepare("SELECT * FROM SALLON where (IDS LIKE '"+str+"%' OR NMS LIKE '"+str+"%' OR NBRM LIKE'"+str+"%' OR LUMIN LIKE '"+str+"%' OR TMPE LIKE '"+str+"%')")  ;
     q.exec() ;
     model->setQuery(q);
     return model;

 }


