#include "placeparking.h"
#include "connexion.h"
#include <QSqlQuery>
#include <QDebug>
PlaceParking::PlaceParking()
{
    NumeroPlace=0;
    Etat="libre";
    Type="proprietaire";
}

PlaceParking::PlaceParking(int numero, QString etat, QString type)
{
    NumeroPlace=numero;
    Etat=etat;
    Type=type;
}

bool PlaceParking::ajouterVehiculeSurParking(int numero_place,QString type,QString etat)
{
    QSqlQuery query;
    query.prepare("update place_parking set etat=:etat,type=:type where(numero_place=:numero_place)");
    query.bindValue(":etat",etat);
    query.bindValue(":type",type);
    query.bindValue(":numero_place",numero_place);
    return query.exec();
}
/*bool PlaceParking::supprimerInviteSurParking(int numero_place,QString type,QString etat)
{
    QSqlQuery query;
    query.prepare("update place_parking set etat=:etat,type=:type where(numero_place=:numero_place)");
    query.bindValue(":etat",etat);
    query.bindValue(":type",type);
    query.bindValue(":numero_place",numero_place);
    return query.exec();
}*/
void PlaceParking::ajouterPlace(int nombre_place)
{
    int ajout=0,existe,num=1;
    QSqlQuery query;
    while (ajout<nombre_place) {
        existe=0;

        query.prepare("select numero_place from place_parking where numero_place=:numero_place");
        query.bindValue(":numero_place",num);
        query.exec();
        while (query.next()) {
            existe=1;
        }

        if(existe==0)
        {

            query.prepare("insert into place_parking (numero_place,etat,type) values (:numero_place,:etat,:type)");
            query.bindValue(":numero_place",num);
            query.bindValue(":etat","libre");
            query.bindValue(":type","invite");
            query.exec();
            ajout++;
        }
        num++;
    }

}

void PlaceParking::nbrPlaces(int* total, int* invite, int *propritaire, int *invitep, int *proprietairep)
{

    QSqlQuery query;
    query.exec("select * from place_parking");
    while (query.next()) {
        (*total)++;
    }
    query.exec("select * from place_parking where type='invite'");
    while (query.next()) {
       (*invite)++;
    }
    query.exec("select * from place_parking where type='proprietaire'");
    while (query.next()) {
        (*propritaire)++;
    }
    query.exec("select * from place_parking where (type='invite'and etat='occupe')");
    while (query.next()) {
        (*invitep)++;
    }
    query.exec("select * from place_parking where (type='proprietaire' and etat='occupe')");
    while (query.next()) {
        (*proprietairep)++;
    }

}

int PlaceParking::calculerNbrPlace()
{
    int n=0;
    QSqlQuery query;
    query.prepare("select * from place_parking");
    query.exec();
    while (query.next()) {
           n++;
    }
    return  n;
}

bool PlaceParking::verifierProprietaire(int numero, QString matricule, int idPro)
{
    QSqlQuery query;
    query.prepare("select id from vehicule_proprietaire where (numero_place=:numero_place or matricule=:matricule)");
    query.bindValue(":numero_place",numero);
    query.bindValue(":matricule",matricule);
    query.exec();
    while (query.next()) {
        if(query.value(0).toInt()==idPro)
            return true;

        qDebug()<< query.value(0).toInt();
    }
    return  false;
}

bool PlaceParking::supprimerToutesPlaceInvite()
{
    QSqlQuery query;
    return query.exec("delete from place_parking where type='invite'");
}

QSqlQueryModel *PlaceParking::emplacementVIde()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select numero_place from place_parking where (etat='libre' and type='invite') order by numero_place");
    model->setHeaderData(0,Qt::Horizontal,"Numero libre");
    model->setHeaderData(1,Qt::Horizontal,"Num_invité_present");

    return model;
}

QSqlQueryModel *PlaceParking::afficherParking()
{
    QSqlQueryModel *model1=new QSqlQueryModel();
    //model1->setQuery("select p.numero_place,p.etat,p.type,v.matricule,v.marque, v.id from place_parking p left outer join vehicule_proprietaire v on p.numero_place=v.numero_place order by p.numero_place ");
    model1->setQuery("select p.numero_place,p.etat,p.type,v.matricule,v.marque, v.id,m.nom from place_parking p left outer join vehicule_proprietaire v on p.numero_place=v.numero_place left outer join membre m on v.id=m.id order by p.numero_place ");

    model1->setHeaderData(0,Qt::Horizontal,"Numero_Place");
    model1->setHeaderData(1,Qt::Horizontal,"Etat");
    model1->setHeaderData(2,Qt::Horizontal,"Type");
    model1->setHeaderData(3,Qt::Horizontal,"Matricule");

    return model1;
}

bool PlaceParking::supprimerPlace(int numero_place,QString etat)
{
    QSqlQuery query;
    QString typ;
    query.prepare("select type,numero_place from place_parking where numero_place=:numero_place");
    query.bindValue(":numero_place",numero_place);
    query.exec();
    while (query.next()) {
        if(query.value(1).toInt()==numero_place)
        {
            typ=query.value(0).toString();
        }

    }
    if(typ=="proprietaire")
    {
        return false;
    }
    else
    {
        query.prepare("update place_parking set etat=:etat where(numero_place=:numero_place)");
        query.bindValue(":etat",etat);
        query.bindValue(":numero_place",numero_place);
        return query.exec();
    }

}

bool PlaceParking::supprimerPlaceLibre()
{
    QSqlQuery query;
    return query.exec("delete from place_parking where (type='invite' and etat='libre')");
}


QSqlQueryModel* PlaceParking::rechercheRapide(QString valeur)
{
    QSqlQueryModel *model2=new QSqlQueryModel();
    model2->setQuery("select p.numero_place,p.etat,p.type,v.matricule,v.marque, v.id,m.nom "
                     "from place_parking p left outer join vehicule_proprietaire v on p.numero_place=v.numero_place "
                     "left outer join membre m on v.id=m.id "
                     "where  (p.type like '%"+valeur+"%' or p.etat like '%"+valeur+"%' or p.numero_place like '%"+valeur+"%'"
                     "or v.matricule like '%"+valeur+"%' or v.marque like '%"+valeur+"%' or v.id like '%"+valeur+"%'"
                      " or m.nom like '%"+valeur+"%' ) order by p.numero_place");
    model2->setHeaderData(0,Qt::Horizontal,"Numero_Place");
    model2->setHeaderData(1,Qt::Horizontal,"Etat");
    model2->setHeaderData(2,Qt::Horizontal,"Type");

    return model2;
}

bool PlaceParking::modifierEtatParking(int numero_place)
{
     QSqlQuery query;
     QString Nvetat;
     query.prepare("select etat from place_parking where (type='proprietaire' and numero_place=:numero) ");
     query.bindValue(":numero",numero_place);
     query.exec();
     while (query.next()) {

         if(query.value(0).toString()=="libre")
         {
                Nvetat="occupe";
         }
         else if(query.value(0).toString()=="occupe")
         {
                Nvetat="libre";
         }
     }
     query.prepare("update place_parking set etat=:etat where(numero_place=:numero_place and type='proprietaire' )");
     query.bindValue(":etat",Nvetat);
     query.bindValue(":numero_place",numero_place);
     return query.exec();
}

bool PlaceParking::modifierEtatParkingCapteur(int numero_place,QString Nvetat)
{
     QSqlQuery query;
     query.prepare("update place_parking set etat=:etat where(numero_place=:numero_place and type='proprietaire' )");
     query.bindValue(":etat",Nvetat);
     query.bindValue(":numero_place",numero_place);
     return query.exec();
}

int PlaceParking::recupererEtat(int numero)
{
    QSqlQuery query;
    query.prepare("select etat from place_parking where (type='proprietaire' and numero_place=:numero) ");
    query.bindValue(":numero",numero);
    query.exec();
    while (query.next()) {

        if(query.value(0).toString()=="libre")
        {
            return 0;
        }
        else if(query.value(0).toString()=="occupe")
        {
            return 1;
        }
    }
}

void PlaceParking::getInfoMembre(int id, QString& email, QString &nom)
{
    QSqlQuery query;
    query.prepare("select nom,email from membre where id=:id ");
    query.bindValue(":id",id);
    query.exec();
    while (query.next()) {
        nom=query.value(0).toString();
        email=query.value(1).toString();
    }
}

