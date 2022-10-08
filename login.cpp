#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

int Login::getId()
{
    return m.getId();
}

Login::~Login()
{
    delete ui;

}

void Login::on_pushButton_clicked()
{
    QDate date;
    if(m.verifier(ui->lineEdit->text().toInt(),ui->lineEdit_2->text()))
    {
        m.Historique(ui->lineEdit->text().toInt(),date.currentDate());
        m.setId(ui->lineEdit->text().toInt());
        ui->lineEdit_2->setText("");
        emit connexion();
        emit clicAccueil();
    }
    else
        QMessageBox::warning(this,tr("Login"),tr("Incorrect id ou mot de passe"));
}
