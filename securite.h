#ifndef SECURITE_H
#define SECURITE_H

#include <QWidget>
#include "securite/membre.h"
#include "securite/admin.h"
#include "securite/porte.h"
#include "securite/fenetre.h"
#include "arduino.h"
#include "smtp.h"
namespace Ui {
class Securite;
}

class Securite : public QWidget
{
    Q_OBJECT

public:
    explicit Securite(QWidget *parent = nullptr);
    ~Securite();
    void setId(int id);

private slots:
    void sendMail();
        //void mailSent(QString status);
        void mail();   // slot permettant la mise à jour du label état de la lampe 1,
           // ce slot est lancé à chaque réception d'un message de Arduino
    void espaceMembre();

    void verifier();

    void on_pushButton_41_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_jardin_clicked();

    void on_pushButton_frigo_clicked();

    void on_pushButton_chambre_clicked();

    void on_pushButton_historique_clicked();

    void on_pushButton_membre_clicked();

    void on_pushButton_admin_clicked();

    void on_pushButton_porte_clicked();

    void on_pushButton_setting_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_36_clicked();

    void on_lineEdit_12_textChanged(const QString &arg1);

    void on_pushButton_mail_clicked();

    void on_pushButton_mail_2_clicked();

    void on_pushButton_setting_2_clicked();

    void on_pushButton_active_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

signals :
    void clicAccueilSecurite();
    void clicParkingSecurite();
    void clicLoginSecurite();
    void clicCloseSecurite();
    void clicChembreSecurite();
    void clicSecuriteSecurite();
    void clicFrigoSecurite();
    void clicJardinSecurite();
private:
    Ui::Securite *ui;
    Membre m;
    Membre me;
    Admin a;
    QByteArray data; // variable contenant les données reçues
    Arduino Ar; // objet temporaire
    //Membre *membre;
};

#endif // SECURITE_H
