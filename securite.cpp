#include "securite.h"
#include "ui_securite.h"


Securite::Securite(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Securite)
{setWindowIcon(QIcon(QPixmap("C:/Users/omar jmai/Documents/New folder/Mon_Module/img_securite/home5---Copie-ConvertImage-ConvertImage.png")));
    setWindowTitle("MyHome");
    int ret=Ar.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< Ar.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<Ar.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(Ar.getserial(),SIGNAL(readyRead()),this,SLOT(mail())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).
    ui->setupUi(this);
    ui->pushButton_38->hide();
    ui->pushButton_40->hide();
    ui->stackedWidget_2->setCurrentIndex(1);
    connect(ui->send_2, SIGNAL(clicked()),this, SLOT(sendMail()));
}
void Securite::mail()
{

    if( Ar.read_from_arduino()=="1"){
            Smtp* smtp = new Smtp("jmaiomar184@gmail.com","24551966","smtp.gmail.com", 465);
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
            smtp->sendMail("jmaiomar184@gmail.com", "omar.jmai@esprit.tn" , "Alerte de votre maison","Movement detected ");}

}
void Securite::sendMail()
{
    Smtp* smtp = new Smtp(ui->lineEdit_mail_2->text(), ui->lineEdit_mdp_2->text(),"smtp.gmail.com",465);
    //connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->lineEdit_mail_2->text(), ui->lineEdit_mail2_2->text() ,"cc",ui->msg_2->toPlainText());
}
Securite::~Securite()
{
    delete ui;
}

void Securite::setId(int id)
{
    me.setId(id);
}

void Securite::espaceMembre()
{
    ui->stackedWidget_2->setCurrentIndex(4);
}

void Securite::verifier()
{
    qDebug()<<me.getId();
    if(me.verifierAdmin(me.getId()))
    {
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->pushButton_setting->show();
        ui->pushButton_porte->show();
        ui->pushButton_membre->show();
        ui->pushButton_historique->show();
        ui->pushButton_admin->show();
        ui->pushButton_mail->show();

    }
    else
    {
         espaceMembre();
         ui->pushButton_mail_2->show();
         ui->pushButton_setting_2->show();
         ui->pushButton_setting->hide();
         ui->pushButton_porte->hide();
         ui->pushButton_membre->hide();
         ui->pushButton_historique->hide();
         ui->pushButton_admin->hide();
         ui->pushButton_mail->hide();

    }

}

void Securite::on_pushButton_41_clicked()
{
    if(ui->pushButton_38->isHidden())
    {
        ui->pushButton_38->show();
        ui->pushButton_40->show();
    }
    else
    {
        ui->pushButton_38->hide();
        ui->pushButton_40->hide();
    }
}

void Securite::on_pushButton_40_clicked()
{
    ui->pushButton_38->hide();
    ui->pushButton_40->hide();
    emit clicLoginSecurite();
}

void Securite::on_pushButton_38_clicked()
{
    emit clicCloseSecurite();
}

void Securite::on_pushButton_34_clicked()
{
    emit clicAccueilSecurite();
}

void Securite::on_pushButton_30_clicked()
{
    emit clicParkingSecurite();
}

void Securite::on_pushButton_jardin_clicked()
{
    emit clicJardinSecurite();
}

void Securite::on_pushButton_frigo_clicked()
{
    emit clicSecuriteSecurite();

}

void Securite::on_pushButton_chambre_clicked()
{
    emit clicChembreSecurite();
}

void Securite::on_pushButton_historique_clicked()
{
    m.afficher_historique(ui->tableWidget_4);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void Securite::on_pushButton_membre_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(5);
}

void Securite::on_pushButton_admin_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(6);
}

void Securite::on_pushButton_porte_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void Securite::on_pushButton_setting_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}


void Securite::on_pushButton_8_clicked()
{
   QString nom =ui->lineEdit_7->text();
   QString prenom=ui->lineEdit_8->text();
   QString mdp =ui->lineEdit_9->text();
   QString email=ui->lineEdit->text();
   if(nom.size()>10)
       QMessageBox::warning(this,"w","invalid Nom");
     else if (prenom.size()>10)
           QMessageBox::warning(this,"error","invalid Prenom");
   else if (mdp.size()>10)
         QMessageBox::warning(this,"error","invalid Mot de passe");


    else{
       m.Ajouter(nom,prenom,mdp,email);
       ui->lineEdit->setText("");
       ui->lineEdit_7->setText("");
       ui->lineEdit_8->setText("");
       ui->lineEdit_9->setText("");
   }
}

void Securite::on_pushButton_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}


void Securite::on_pushButton_22_clicked()
{
    int  id=ui->lineEdit_3->text().toInt();
    qDebug()<<id;
   a.ajouter_membre_listAdmin(id);
   ui->lineEdit_3->setText("");
}

void Securite::on_pushButton_15_clicked()
{
    QString nom =ui->lineEdit_14->text();
    QString prenom=ui->lineEdit_15->text();
    QString mdp =ui->lineEdit_16->text();
    QString email=ui->lineEdit_20->text();
    if(nom.size()>10)
           QMessageBox::warning(this,"w","invalid Nom");
         else if (prenom.size()>10 )
               QMessageBox::warning(this,"error","invalid Prenom");
         else if (mdp.size()>10)
             QMessageBox::warning(this,"error","invalid Mot de passe");

       else{
m.Ajouter(nom,prenom,mdp,"email");
a.Ajouter(nom,prenom,mdp,email,"Admin");
/*if(a.Ajouter())
    //QMessageBox::warning(this,"Identifiant","votre Identifiant est " +a.getId());*/
    }
}
////
 ////

void Securite::on_pushButton_17_clicked()
{
    a.afficher(ui->tableWidget_2);
}

void Securite::on_pushButton_18_clicked()
{
    int  id=ui->lineEdit_18->text().toInt();
       if(m.verifier_existance(id)){
        a.suprimer(id);
        m.suprimer(id);}
   else
   QMessageBox::warning(this,"error","identifiant deja existe");

}

void Securite::on_pushButton_13_clicked()
{
    int id=ui->lineEdit_4->text().toInt();
    QString mdp=ui->lineEdit_5->text();

    if(m.verifier_existance(id))
    {
        m.Modifier(mdp,id);
    }
    else
        QMessageBox::warning(this,"Login","identifiant n'existe pas");

    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
}

void Securite::on_pushButton_29_clicked()
{
    QString etat=ui->lineEdit_17->text();
    Fenetre f;
    f.Ajouter(etat);
}

void Securite::on_pushButton_28_clicked()
{
    QString etat=ui->lineEdit_17->text();
    Porte p;
    p.Ajouter(etat);
}

void Securite::on_pushButton_33_clicked()
{
    Fenetre f;
      f.afficher(ui->tableWidget_5);

}

void Securite::on_pushButton_32_clicked()
{
    Porte p;
       p.afficher(ui->tableWidget_5);
}



void Securite::on_lineEdit_12_textChanged(const QString &arg1)
{
        m.rechercher(arg1,ui->tableWidget);
}



void Securite::on_pushButton_36_clicked()
{
    m.tri(ui->tableWidget);
}

void Securite::on_pushButton_37_clicked()
{
     m.afficher(ui->tableWidget);
}

void Securite::on_pushButton_mail_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(8);
}

void Securite::on_pushButton_mail_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(8);

}

void Securite::on_pushButton_setting_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void Securite::on_pushButton_active_clicked()
{
    Ar.write_to_arduino("2");
}

void Securite::on_pushButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void Securite::on_lineEdit_2_textChanged(const QString &arg1)
{
    m.rechercher(arg1,ui->tableWidget_2);

}

void Securite::on_pushButton_3_clicked()
{
      m.tri(ui->tableWidget_2);
}
