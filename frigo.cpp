#include "frigo.h"
#include "ui_frigo.h"

Frigo::Frigo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Frigo)
{
    ui->setupUi(this);
    ui->pushButton_deconnexio->hide();
    ui->pushButton_quitter->hide();
}

Frigo::~Frigo()
{
    delete ui;
}
void Frigo::on_pushButton_accueil_clicked()
{
    emit clicAccueilFrigo();
}

void Frigo::on_pushButton_parking_clicked()
{
    emit clicParkingFrigo();
}

void Frigo::on_pushButton_securite_clicked()
{
    emit clicSecuriteFrigo();
}

void Frigo::on_pushButton_jardin_clicked()
{
    emit clicJardinFrigo();
}

void Frigo::on_pushButton_frigo_clicked()
{
    emit clicFrigoFrigo();
}

void Frigo::on_pushButton_chembre_clicked()
{
    emit clicChembreFrigo();
}

void Frigo::on_pushButton_quitter_clicked()
{
    emit clicCloseFrigo();
}

void Frigo::on_pushButton_deconnexio_clicked()
{
    ui->pushButton_deconnexio->hide();
    ui->pushButton_quitter->hide();
    emit clicLoginFrigo();
}

void Frigo::on_pushButton_conn_clicked()
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
