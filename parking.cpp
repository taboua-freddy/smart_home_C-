#include "parking.h"
#include "ui_parking.h"
#include "mainwindow.h"
#include "login.h"
#include <QDebug>
#include <QVector>
#define MAX_PLACE 50

Parking::Parking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Parking)
{
    ui->setupUi(this);
    cacherLesBoutonOption();
    ui->stackedWidget->hide(); // cacher l ajout des cartes
    ui->lineEdit_idCarte->setReadOnly(1);
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->checkBox->setChecked(true);
    d="";
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(scannerCarte()));
     //connect(this,SIGNAL(lecture()),this SLOT());
}

void Parking::setId(int id)
{
    m.setId(id);
    ui->checkBox->setChecked(true);
    ui->radioButton_2->setChecked(true);
    qDebug()<< m.getId();
}

Parking::~Parking()
{
    delete ui;
}

void Parking::verifier()
{
    if(m.verifierAdmin(m.getId()))
    {
        ui->pushButton_carte->show();
        ui->pushButton_historique->show();
    }
    else
    {
        ui->pushButton_historique->hide();
        ui->pushButton_carte->hide();
    }
}
void Parking::sendMail()
{
    QString email="",nom="";
    p.getInfoMembre(m.getId(),email,nom);
    Smtp* smtp = new Smtp("tabouaf@gmail.com","Tabouapiter","smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    smtp->sendMail("tabouaf@gmail.com",email, "MyHome ALERTE","\n\n Mr."+nom+" votre voiture a été déplacée");
}

void Parking::mailSent(QString status)
{
    if(status == "Message sent")
    {
        QMessageBox::information(this, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
        emit jouerExcla();
    }
}

void Parking::updateComboBox()
{

    Vehicule v;
    if(m.verifierAdmin(m.getId())) // s il est admin il a le droit d ajouter a un autre id
    {
        ui->comboBox_id->setModel(v.getId());
    }
    else
    {
        ui->comboBox_id->removeItem(0);
        ui->comboBox_id->addItem(QString::number(m.getId()));
    }
    ui->comboBox_nouveauNum->setModel(p.emplacementVIde());
    ui->comboBox_numeroPlace->setModel(p.emplacementVIde());
}

void Parking::on_pushButton_ajouter_clicked() // lorsque tu clique sur ajouter vehicule
{
    emit jouer();
    cacherLesBoutonOption();
    updateComboBox();
    ui->stackedWidget_2->setCurrentIndex(0);// ajout d un vehicule

}

void Parking::on_pushButton_supprimer_clicked() // supprimer vehicule
{
    emit jouer();
    cacherLesBoutonOption();
    ui->stackedWidget_2->setCurrentIndex(1);

}

void Parking::on_pushButton_vide_clicked() // emplacement vide
{
    emit jouer();
    cacherLesBoutonOption();
    ui->stackedWidget_2->setCurrentIndex(3);
    updateAffichage();

}

void Parking::on_pushButton_modifier_clicked() // modifier numero de place
{
   emit jouer();
   updateComboBox();
   ui->stackedWidget_2->setCurrentIndex(2);

}

void Parking::on_ajouter_clicked()
{
    emit jouer();
    cacherLesBoutonOption();
    QString matricule=ui->lineEdit_23->text();
    QString marque=ui->lineEdit->text();
    int numero=ui->comboBox_numeroPlace->currentText().toInt();
    int id=ui->comboBox_id->currentText().toInt();
    if(ui->comboBox_id->currentText()=="")
    {
        ui->label_34->setText("***");
        emit jouerEr();
    }
    else if(ui->lineEdit_23->text()=="")
    {
        ui->label_14->setText("***");
        ui->label_34->setText("");
        emit jouerEr();
    }
    else if(ui->comboBox_numeroPlace->currentText()=="")
    {
        emit jouerEr();
        ui->label_3->setText(tr("***"));
        ui->label_34->setText("");
        ui->label_14->setText("");
    }
    else
    {
        Vehicule ve(numero);
        if(ve.ajouterVehicule()) //on ajoute d abord un vehicule simple
        {
            VehiculeProprietaire v(matricule,id,numero,marque);
            int test =v.ajouterVehicule(); //puis un vehicule proprietaire
            if(test==1)
            {
                PlaceParking p;
                if(p.ajouterVehiculeSurParking(numero,"proprietaire","libre"))  //puis on l ajoute sur le parking
                {
                    emit jouerExcla();
                    h.ajouterHistorique(m.getId(),tr("a ajoute un nouveau vehicule a l'id ")+ui->comboBox_numeroPlace->currentText()+ tr(" sur la place ")+ui->comboBox_numeroPlace->currentText()+"");
                    QMessageBox::information(this,tr("ajout d un vehicule"),QObject::tr("ajouté avec succès"));
                }

            }
            else if(test==2)
            {
                emit jouerEr();
                QMessageBox::critical(this,tr("erreur fatal"),QObject::tr("ce matricule exite déjà ou la place est prise"));
            }
            else if(test==0)
            {
                emit jouerEr();
                QMessageBox::critical(this,tr("erreur fatal"),QObject::tr("cette id ne correspond a aucun membre**"));
            }
        }
        else
        {
            emit jouerEr();
            QMessageBox::critical(this,tr("erreur fatal"),QObject::tr("ce numero de place est reservé ou existe déjà"));
        }
        ui->label_34->setText("");
        ui->label_14->setText("");
        ui->label_3->setText("");
        ui->lineEdit_23->setText("");ui->lineEdit->setText("");
    }
    updateComboBox();
}

void Parking::on_supprimer_clicked()
{
    emit jouer();
    cacherLesBoutonOption();
    QString mat=ui->lineEdit_25->text();
    int num;
    int numero=ui->lineEdit_25->text().toInt();
    if(mat=="")
    {
        emit jouerEr();
        ui->label_50->setText("***");
    }
    else
    {
        if(p.verifierProprietaire(numero,mat,m.getId())||m.verifierAdmin(m.getId())) //si il est admin au proprietaire il peut modifier
        {
            VehiculeProprietaire v;
            Vehicule ve;

            num=v.numeroPlace(numero,mat);

            int n=0;QString matri="";
            v.recupererNumeroMatriculePlace(numero,mat,matri,n); //un recuper le numero et le matricule correspondant

            if(v.supprimerVehicule(mat,numero)) //on supprime d abord le vehicule proprietaire
            {
                if(ve.supprimerVehicule(num)) // puis on supprime le vehicule simple
                {
                    PlaceParking p;
                    if(p.ajouterVehiculeSurParking(numero,"invite","libre"))  // mise à jour sur le parking puis que la place n'est pas suppriméé
                    {
                        emit jouerExcla();
                        h.ajouterHistorique(m.getId(),tr("a supprime le vehicule de matricule ")+matri+tr(" de la place ")+QString::number(n)+"");
                        QMessageBox::information(this,tr("confirmation"),tr("supprimé"));
                    }
                    ui->lineEdit_25->setText("");
                }
            }
            else
            {
                emit jouerEr();
                QMessageBox::critical(this,tr("erreur"),tr("le matricule ou le numero saisi n'éxite pas"));
            }
        }
        else
        {
            emit jouerEr();
            QMessageBox::critical(this,tr("erreur"),tr("vous devez etre admin pour modifier ce vehicule"));
        }
        ui->label_50->setText("");
    }
}

void Parking::on_modifier_clicked()
{
    emit jouer();
    cacherLesBoutonOption();
    QString mat=ui->lineEdit_28->text();
    int numero=ui->lineEdit_28->text().toInt();
    int nouveauNum=ui->comboBox_nouveauNum->currentText().toInt();
    if(mat=="")
    {
        emit jouerEr();
        ui->label_48->setText(tr("***"));
    }
    else if (ui->comboBox_nouveauNum->currentText()=="")
    {
        emit jouerEr();
         ui->label_47->setText("***");
         ui->label_48->setText("");
    }
    else
    {
        if(m.verifierAdmin(m.getId())||p.verifierProprietaire(numero,mat,m.getId())) // on vérifie s'il est admin ou propritaire du vehicule
        {
            VehiculeProprietaire v;
            Vehicule v2;
            int num=0,id=0;QString ma="",marque="",etat="";
            v.recupererNumeroMatriculePlace(numero,mat,ma,num);
            v.recupererInfo(num,marque,id,etat);
            if(v.supprimerVehicule(ma,num))
            {
                v2.supprimerVehicule(num);
                p.ajouterVehiculeSurParking(num,"invite","libre");
                p.ajouterVehiculeSurParking(nouveauNum,"proprietaire",etat);
                Vehicule ve(nouveauNum);
                VehiculeProprietaire v1(ma,id,nouveauNum,marque);
                ve.ajouterVehicule();
                v1.ajouterVehicule();
                h.ajouterHistorique(m.getId(),tr("a changer son nunmero de place de ")+QString::number(numero)+tr(" vers ")+QString::number(nouveauNum)+"");
                emit jouerExcla();
                QMessageBox::information(this,tr("confirmation de modification"),tr("modifie avec succes"));
            }
            else
            {
                emit jouerEr();
                QMessageBox::critical(this,tr("erreur"),tr("cette id ne correspond à aucun membre ou \n le numero ou le matricule saisi est incorrect"));
            }
        }
        else
        {
                emit jouerEr();
             QMessageBox::critical(this,tr("erreur fatal"),QObject::tr("vous devez etre admin pour modifier ce vehicule"));
        }

        ui->label_47->setText("");
        ui->label_48->setText("");
        ui->lineEdit_28->setText("");
    }

}

void Parking::on_ajouter_places_clicked() //ajouter des places dans le parking
{
    emit jouer();
    cacherLesBoutonOption();
    int nombre_places=ui->lineEdit_2->text().toInt();
    int placeRestante;
    QString message;
        if(ui->lineEdit_2->text()!="")
        {
            placeRestante=MAX_PLACE - p.calculerNbrPlace();
            if(placeRestante>=nombre_places)  // on verifie le reste de places
            {
                PlaceParking p;
                p.ajouterPlace(nombre_places); // on ajoute le nombre de place demandé
                updateAffichage();
                emit jouerExcla();
            }
            else
            {
                emit jouerEr();
                QMessageBox::critical(this,"erreur fatal","limite de "+QString::number(MAX_PLACE)+" places dépasséé\n vous pouvez encore ajouter "+QString::number(placeRestante)+"");
            }

        }
    ui->lineEdit_2->setText("");

}

void Parking::updateAffichage() // tout ce qui conserne l' affichage dans le parking
{
    ui->tableView->setModel(p.emplacementVIde());
    ui->tableView_2->setModel(p.afficherParking());

    int total=0,invite=0,proprietaire=0,invitep=0,proprietairep=0;
    p.nbrPlaces(&total,&invite,&proprietaire,&invitep,&proprietairep);
    QString t=QString::number(total);QString i=QString::number(invite);QString p=QString::number(proprietaire),ip=QString::number(invitep),pp=QString::number(proprietairep);
    ui->label_19->setText("places totals: "+t);
    ui->label_20->setText("places invités: "+i);
    ui->label_22->setText("places invités présents: "+ip);
    ui->label_21->setText("places proprietaires: "+p);
    ui->label_28->setText("proprietaires présents: "+pp);
}

void Parking::on_affecter_invite_clicked() //retirer un invite du parking
{
    emit jouer();
    cacherLesBoutonOption();
    int numero=ui->lineEdit_4->text().toInt();
    if(ui->lineEdit_4->text()!="")
    {
        Vehicule v;
        if(v.supprimerVehicule(numero))  //on supprime d' abord le vehicule
        {
            if(p.supprimerPlace(numero,"libre")) // puis une mise à jour du parking puisque la place n'est pas supprimée
            {
                 updateAffichage();
                 h.ajouterHistorique(m.getId(),"a supprime un invite du numero de place "+QString::number(numero)+"");
                 emit jouerExcla();
                 QMessageBox::information(this,tr("confirmation"),tr("supprimé"));
                 ui->label_17->setText("");
            }
            else
            {
                emit jouerEr();
                 QMessageBox::critical(this,tr("erreur"),tr("numero ne correspond pas ou appartient a un membre"));
            }
        }
        else
        {
            emit jouerEr();
            QMessageBox::critical(this,tr("erreur"),tr("numero ne correspond pas ou appartient à un membre"));
        }
    }
    else
    {
        emit jouerEr();
        ui->label_17->setText("***");
    }
    ui->lineEdit_4->setText("");

}

void Parking::on_pushButton_liberer_vis_clicked()//supprimer toutes les places libres
{
    emit jouer();
    cacherLesBoutonOption();
    Vehicule v;
    if(p.supprimerPlaceLibre())
    {
        emit jouerExcla();
        QMessageBox::information(this,tr("confirmation"),"supprimé");
    }
    else
    {
        emit jouerEr();
        QMessageBox::critical(this,tr("erreur"),tr("numero ne correspond pas ou appartient a un membre"));
    }
    updateAffichage();

}
void Parking::on_lineEdit_3_textEdited(const QString &arg1)// line edit pour la rechercher rapide dans les emplacements
{
    cacherLesBoutonOption();
    QString valeur=ui->lineEdit_3->text();
    if(arg1=="")
    {
        updateAffichage();
    }
    else
        ui->tableView_2->setModel(p.rechercheRapide(valeur));
}

void Parking::on_tableView_activated(const QModelIndex &index) //affecter une place en cliquant dessus
{
    int val= ui->tableView->model()->data(index).toInt();
    qDebug() << val;
    PlaceParking p;
    if(p.ajouterVehiculeSurParking(val,"invite","occupe"))
    {
         Vehicule v(val);
         v.ajouterVehicule(); // pourqu'il n'y ait pas conflit de numero en ajoutant un propriataire par la suite
         h.ajouterHistorique(m.getId(),tr("a affecte un invite sur le numéro de place ")+ui->tableView->model()->data(index).toString()+"");
         QMessageBox::information(this,tr("confirmation"),tr("place reservée pour un invité"));
         updateAffichage();
         emit jouerExcla();
    }
}

void Parking::on_pushButton_historique_clicked()  //lorsqu'on clique sur bouton historique
{
    emit jouer();
    cacherLesBoutonOption();
    ui->lineEdit_5->setReadOnly(1);
    ui->lineEdit_6->setReadOnly(1);
    ui->stackedWidget_2->setCurrentIndex(4);
    ui->tableView_4->setModel(h.afficherHistorique());
    ui->tableView_4->resizeColumnsToContents();

}

void Parking::on_pushButton_ouvrir_clicked() //lorsqu'on clique sur le bouton ouvrir
{
    emit jouer();
    if(h.ajouterHistorique(m.getId(),tr("ouverture du parking")))
    {
         A.write_to_arduino("1");
         emit jouerExcla();
         QMessageBox::information(this,tr("confirmation"),tr("parking ouvert"));
    }
    else
    {
        emit jouerEr();
        QMessageBox::critical(this,tr("erreur"),tr("une erreur s'est produite lors de l ouverture"));
    }


}

void Parking::on_calendarWidget_activated(const QDate &date) // recupérer la date pour la mettre dans le lineedite
{
    emit jouer();
    if(ui->lineEdit_5->text()!=""&&ui->lineEdit_6->text()!="")
    {
        ui->lineEdit_5->setText("");
         ui->lineEdit_6->setText("");
    }
    if(ui->lineEdit_5->text()=="")
    {
        ui->lineEdit_5->setText(date.toString("dd/MM/yy"));
    }
    else if(ui->lineEdit_6->text()=="")
    {
        ui->lineEdit_6->setText(date.toString("dd/MM/yy"));
    }

}

void Parking::on_supprimer_Hist_clicked() //bouton supprimer historique sur une periode
{
    emit jouer();
    cacherLesBoutonOption();
    QString debut=ui->lineEdit_5->text(),fin=ui->lineEdit_6->text();

    if(m.verifierAdmin(m.getId()))  //seul un admin peut supprimer
    {
        if(debut=="")
        {
            ui->label_25->setText("***");
        }
        else if(fin=="")
        {
            ui->label_25->setText("");
            ui->label_26->setText("***");
        }
        else
        {
            h.supprimerIntervalleHistorique(debut,fin);
            ui->label_25->setText("");
            ui->label_26->setText("");
        }

    }
    else
    {
        emit jouerEr();
        QMessageBox::critical(this,tr("erreur"),tr("vous n'etez pas un administrateur"));
    }
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    updateAffichageHistorique();

}

void Parking::on_supprimer_all_hist_clicked() //bouton supprimer historique toutes les historiques
{
    emit jouer();
    cacherLesBoutonOption();
    if(m.verifierAdmin(m.getId())) //seul un admin peut supprimer
    {
        h.supprimerAllHistorique();
    }
    else
    {
        emit jouerEr();
        QMessageBox::critical(this,tr("erreur"),tr("vous n'etez pas un administrateur"));
    }
    updateAffichageHistorique();

}

void Parking::updateAffichageHistorique()
{
    ui->tableView_4->setModel(h.afficherHistorique());
    ui->tableView_4->resizeColumnsToContents();
}

void Parking::on_supprimer_all_guest_clicked() // supprimer tous les visiteurs du parking
{
    emit jouer();
    cacherLesBoutonOption();
    Vehicule v;
    if(v.supprimerInvite())
    {
        if(p.supprimerToutesPlaceInvite())
        {
            emit jouerExcla();
            h.ajouterHistorique(m.getId(),tr("a supprime tous les invites du parking"));
            QMessageBox::information(this,tr("confirmation"),tr("supprimé"));
        }
        else
        {
            emit jouerEr();
            QMessageBox::critical(this,tr("erreur"),tr("erreur1"));
        }
    }
    else
    {
        emit jouerEr();
        QMessageBox::critical(this,tr("erreur"),tr("erreur2"));
    }


    updateAffichage();
}

void Parking::on_lineEdit_7_textEdited(const QString &arg1) //recherche rapide dans historique
{
    cacherLesBoutonOption();
    QString valeur=ui->lineEdit_7->text();
    if(arg1=="")
    {
        updateAffichageHistorique();
    }
    else
        ui->tableView_4->setModel(h.rechercheRapide(valeur));
}

void Parking::on_modifEtat_clicked()
{
    emit jouer();
    cacherLesBoutonOption();
    int numero=ui->lineEdit_8->text().toInt();
    QString motif(tr("votre voiture a ete deplacee"));
    if(ui->lineEdit_8->text()!="")
    {
        if(p.modifierEtatParking(numero))
        {
            updateAffichage();
            if(!p.recupererEtat(numero))
            {
               sendMail();
            }
        }

    }
}

void Parking::on_Button_efface_clicked()
{
    emit jouer();
    cacherLesBoutonOption();
    a.supprimerAlerte();
    ui->tableView_5->setModel(a.afficherAlerte());
}

void Parking::on_pushButton_15_clicked()
{
    emit jouer();
    ui->stackedWidget_3->hide();
    if(ui->pushButton_11->isHidden())
    {
        ui->pushButton_11->show();
        ui->pushButton_18->show();

    }
    else
    {
        ui->pushButton_11->hide();
        ui->pushButton_18->hide();
    }
}

void Parking::on_pushButton_18_clicked()
{
    emit jouer();
    cacherLesBoutonOption();
    emit clicLoginParking();
}

void Parking::on_pushButton_11_clicked()
{
    emit jouer();
    cacherLesBoutonOption();
    emit clicCloseParking();
}

void Parking::on_pushButton_19_clicked()
{
    emit jouer();
    cacherLesBoutonOption();
    emit clicAccueil();
}

void Parking::on_pushButton_17_clicked()
{
    emit jouer();
    cacherLesBoutonOption();
    emit clicSecurite();
}

void Parking::on_pushButton_jardin_clicked()
{
    emit jouer();
    cacherLesBoutonOption();
    emit clicJardinParking();
}

void Parking::on_pushButton_frigo_clicked()
{
    emit jouer();
    cacherLesBoutonOption();
    emit clicFrigoParking();
}

void Parking::on_pushButton_chambre_clicked()
{
    emit jouer();
    cacherLesBoutonOption();
    emit clicChembreParking();
}

void Parking::scannerCarte()
{
    while(A.getserial()->canReadLine())
    {
        bool corect=0;
        do
        {
            data=A.getserial()->readLine();
            if(data.contains('.'))
            {
                d+=data;
                d.remove(QRegExp("[\\n\\t\\r.]"));
                corect=1;
            }
            else
            {
                 d+=data;
            }
        }while(!corect);
        IdCarte=d;
        /*QString b=A.read_from_arduino();
        if(b==QString::number(1))
        {
            if(p.modifierEtatParkingCapteur(1,"libre")&& mail!=1)
            {
                updateAffichage();
                //sendMail();
                mail=1;
            }
        }
        else if(b==QString::number(2))
        {
            p.modifierEtatParkingCapteur(1,"occupe");
            updateAffichage();
            mail=0;
        }*/
        /*if(d!=QString::number(1)&&d!=QString::number(2))
        {*/
            ui->lineEdit_idCarte->setText(IdCarte);
            if(c.VerifierCarte(d))
            {
                A.write_to_arduino("1");
                h.ajouterHistorique(c.getIdResident(IdCarte),tr("ouverture du parking"));
                updateAffichageHistorique();
            }
            else {
                A.write_to_arduino("2");
            }
       // }
        d="";
        data="";
    }

}

void Parking::on_scanner_clicked()
{
    if(ui->stackedWidget->isHidden())
    {
        ui->lineEdit_idCarte->setText(IdCarte);
        ui->stackedWidget->show();
    }
    else
        ui->stackedWidget->hide();
}

void Parking::on_arreter_scanne_clicked()
{
    cacherLesBoutonOption();
    ui->stackedWidget->hide();
}

void Parking::on_pushButton_clicked()
{
    emit jouer();
    cacherLesBoutonOption();
    int id=ui->comboBox_id_res_carte->currentText().toInt();
    if(ui->lineEdit_idCarte->text()=="")
    {
        emit jouerEr();
    }
    else if(c.AjouterCarte(id,ui->lineEdit_idCarte->text()))
    {
        emit jouerExcla();
        QMessageBox::information(this,tr("confirmation"),tr("ajouté"));
        ui->tableView_5->setModel(c.afficherCarte());
        ui->tableView_5->resizeColumnToContents(1);
        ui->lineEdit_idCarte->setText("");
    }
    else
    {
        emit jouerEr();
        QMessageBox::critical(this,tr("erreur"),tr("l id ne correspond a aucun membre"));
    }
}

void Parking::on_suppimer_carte_clicked()
{
    emit jouer();
    cacherLesBoutonOption();
    c.supprimer(ui->lineEdit_cartesupp->text());
    ui->tableView_5->setModel(c.afficherCarte());
    ui->tableView_5->resizeColumnToContents(1);
}

void Parking::on_pushButton_carte_clicked()
{
    Vehicule v;
    emit jouer();
    cacherLesBoutonOption();
    ui->comboBox_id_res_carte->setModel(v.getId());
    ui->lineEdit_cartesupp->setReadOnly(1);
    ui->stackedWidget_2->setCurrentIndex(5);
    ui->tableView_5->setModel(c.afficherCarte());
    ui->tableView_5->resizeColumnToContents(1);
}

void Parking::on_tableView_5_doubleClicked(const QModelIndex &index)
{
    if(index.column()==1)
        ui->lineEdit_cartesupp->setText(ui->tableView_5->model()->data(index).toString());
}

void Parking::cacherLesBoutonOption()
{
    ui->stackedWidget_3->hide();
    ui->pushButton_11->hide();
    ui->pushButton_18->hide();
}


void Parking::on_setting_clicked()
{
    emit jouer();
    ui->pushButton_11->hide();
    ui->pushButton_18->hide();

    if(ui->stackedWidget_3->isHidden())
    {
        ui->stackedWidget_3->show();
    }
    else
    {
        ui->stackedWidget_3->hide();
    }
}

void Parking::on_radioButton_clicked()
{
    emit jouer();
    emit themeSombre();
}

void Parking::on_radioButton_2_clicked()
{
    emit jouer();
    emit themeClaire();
}

void Parking::on_checkBox_stateChanged(int arg1)
{
    emit jouer();
    if(arg1)
        emit sonNonMuet();
    else
        emit sonMuet();
}

void Parking::on_radioButton_3_clicked()
{
    emit jouer();
    emit langueFrancaise();
}

void Parking::on_radioButton_4_clicked()
{
    emit jouer();
    emit langueAnglaise();
}
