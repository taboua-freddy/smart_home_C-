#include "jardin.h"
#include "ui_jardin.h"

Jardin::Jardin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Jardin)
{
    ui->setupUi(this);
    ui->pushButton_deconnexio->hide();
    ui->pushButton_quitter->hide();
}

Jardin::~Jardin()
{
    delete ui;
}

void Jardin::on_pushButton_accueil_clicked()
{
    emit clicAccueilJardin();
}

void Jardin::on_pushButton_parking_clicked()
{
    emit clicParkingJardin();
}

void Jardin::on_pushButton_securite_clicked()
{
    emit clicSecuriteJardin();
}

void Jardin::on_pushButton_jardin_clicked()
{
    emit clicJardinJardin();
}

void Jardin::on_pushButton_frigo_clicked()
{
    emit clicFrigoJardin();
}

void Jardin::on_pushButton_chambre_clicked()
{
    emit clicChembreJardin();
}

void Jardin::on_pushButton_quitter_clicked()
{
    emit clicCloseJardin();
}

void Jardin::on_pushButton_deconnexio_clicked()
{
    ui->pushButton_deconnexio->hide();
    ui->pushButton_quitter->hide();
    emit clicLoginJardin();
}

void Jardin::on_pushButton_conn_clicked()
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
