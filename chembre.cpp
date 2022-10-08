#include "chembre.h"
#include "ui_chembre.h"
#include <QMessageBox>
Chembre::Chembre(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chembre)
{
    ui->setupUi(this);
    ui->pushButton_deconnexio->hide();
    ui->pushButton_quitter->hide();
}

Chembre::~Chembre()
{
    delete ui;
}
void Chembre::on_pushButton_accueil_clicked()
{
    emit clicAccueilChembre();
}

void Chembre::on_pushButton_parking_clicked()
{
    emit clicParkingChembre();
}

void Chembre::on_pushButton_securite_clicked()
{
    emit clicSecuriteChembre();
}

void Chembre::on_pushButton_jardin_clicked()
{
    emit clicJardinChembre();
}

void Chembre::on_pushButton_frigo_clicked()
{
    emit clicFrigoChembre();
}

void Chembre::on_pushButton_chembre_clicked()
{
    emit clicChembreChembre();
}

void Chembre::on_pushButton_quitter_clicked()
{
    emit clicCloseChembre();
}

void Chembre::on_pushButton_deconnexio_clicked()
{
    ui->pushButton_deconnexio->hide();
    ui->pushButton_quitter->hide();
    emit clicLoginChembre();
}

void Chembre::on_pushButton_conn_clicked()
{
    if(ui->pushButton_deconnexio->isHidden())
    {
        ui->pushButton_deconnexio->show();
        ui->pushButton_quitter->show();

    }
    else
    {
        ui->pushButton_deconnexio->hide();
        ui->pushButton_quitter->hide();
    }
}

void Chembre::on_ajouter_chambre_clicked()
{
    C.set_NUMDC(ui->lineEdit->text());
    C.set_NOMDC(ui->lineEdit_2->text());
    C.set_NRBLIT(ui->spinBox->text());
    if(ui->radioButton->isChecked()){C.set_DISPO("disponnible"); }
    if(ui->radioButton_2->isChecked()){C.set_DISPO("non disponnible");}
    C.set_LUMINO(ui->spinBox_2->text());
    C.set_TMP(ui->spinBox_3->text());
    qDebug()<<"chambre ajouter";
    C.ajouter_c();
    QSqlQueryModel *model =C.afficher_c();
   ui->tableView->setModel(model);
    QMessageBox::information(this,"Succes","Chambre ajoutée");
}

void Chembre::on_ajouter_s_clicked()
{
    S.set_NUMDS(ui->lineEdit_3->text());
    S.set_NOMDS(ui->lineEdit_4->text());
    S.set_NRBM(ui->spinBox_4->text());
    S.set_LUMINO(ui->spinBox_5->text());
    S.set_TMP(ui->spinBox_6->text());
    S.ajouter_s();
              QSqlQueryModel *model =S.afficher_s();
  ui->tableView_2->setModel(model);
    QMessageBox::information(this,"Succes","Sallon ajoutée");
}



void Chembre::on_supprimer_c_clicked()
{
    QString numdc = ui->lineEdit_5->text();
    C.supprimer_c(numdc);



        QMessageBox::information(this,"Succes","chambre supprimée");
}

void Chembre::on_supprimer_s_clicked()
{
    QString numds = ui->lineEdit_6->text();
    S.supprimer_s(numds);



        QMessageBox::information(this,"Succes","salon supprimée");

}


void Chembre::on_recherchechambre_textChanged(const QString &arg1)
{
    QString str=ui->recherchechambre->text();
      QSqlQueryModel* model=C.rechercher_chambre(str);
          ui->tableView-> setModel(model);
}


void Chembre::on_recherchesalon_textChanged(const QString &arg1)
{
    QString str=ui->recherchesalon->text();
    QSqlQueryModel* model=S.rechercher_salon(str);
        ui->tableView_2-> setModel(model);
}


void Chembre::on_comboBox_activated(const QString &arg1)
{

    QSqlQueryModel* model=C.tri_chambre();
        ui->tableView-> setModel(model);
        if(ui->comboBox->currentIndex())
        {
            QSqlQueryModel* model=C.tri_chambre_dispo();
                ui->tableView-> setModel(model);
        }
}

void Chembre::on_comboBox_2_activated(const QString &arg1)
{
    QSqlQueryModel* model=S.tri_salon();
        ui->tableView-> setModel(model);
        if(ui->comboBox_2->currentIndex())
        {
            QSqlQueryModel* model=S.tri_salon_meuble();
                ui->tableView_2-> setModel(model);
        }
}

void Chembre::on_modifier_C_clicked()
{
    C.set_NUMDC(ui->lineEdit_7->text());
       if(ui->radioButton_3->isChecked()){C.set_DISPO("disponnible"); }
       if(ui->radioButton_4->isChecked()){C.set_DISPO("non disponnible");}
       C.set_LUMINO(ui->spinBox_7->text());
       C.set_TMP(ui->spinBox_8->text());
       C.modifier_c();
       QSqlQueryModel *model =C.afficher_c();
       ui->tableView->setModel(model);
       QMessageBox::information(this,"Succes","chambre modifiée");
}

void Chembre::on_modifier_S_clicked()
{
    S.set_NUMDS(ui->lineEdit_8->text());

           S.set_LUMINO(ui->spinBox_9->text());
           S.set_TMP(ui->spinBox_10->text());
          S.modifier_s();
          QSqlQueryModel *model =S.afficher_s();
           ui->tableView->setModel(model);
           QMessageBox::information(this,"Succes","chambre modifiée");
}

void Chembre::on_pushButton_ajouter_clicked()
{
        ui->stackedWidget_2->setCurrentIndex(0);
}

void Chembre::on_pushButton_supprimer_clicked()
{
        ui->stackedWidget_2->setCurrentIndex(1);
}

void Chembre::on_pushButton_vide_clicked()
{
        ui->stackedWidget_2->setCurrentIndex(2);
}

void Chembre::on_pushButton_modifier_clicked()
{
        ui->stackedWidget_2->setCurrentIndex(3);
}
