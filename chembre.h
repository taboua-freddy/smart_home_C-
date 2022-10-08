#ifndef CHEMBRE_H
#define CHEMBRE_H

#include <QWidget>
#include "chambre/chambre.h"
#include "chambre/salon.h"
namespace Ui {
class Chembre;
}

class Chembre : public QWidget
{
    Q_OBJECT

public:
    explicit Chembre(QWidget *parent = nullptr);
    ~Chembre();
signals:
    void clicAccueilChembre();
    void clicSecuriteChembre();
    void clicLoginChembre();
    void clicCloseChembre();
    void clicChembreChembre();
    void clicParkingChembre();
    void clicFrigoChembre();
    void clicJardinChembre();
private slots:


    void on_pushButton_accueil_clicked();

    void on_pushButton_parking_clicked();

    void on_pushButton_securite_clicked();

    void on_pushButton_jardin_clicked();

    void on_pushButton_frigo_clicked();

    void on_pushButton_chembre_clicked();

    void on_pushButton_quitter_clicked();

    void on_pushButton_deconnexio_clicked();

    void on_pushButton_conn_clicked();
    void on_ajouter_chambre_clicked();

    void on_ajouter_s_clicked();

    void on_supprimer_c_clicked();

    void on_supprimer_s_clicked();

    void on_recherchechambre_textChanged(const QString &arg1);

    void on_recherchesalon_textChanged(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_modifier_C_clicked();

    void on_modifier_S_clicked();

    void on_pushButton_vide_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

private:
    Ui::Chembre *ui;
    chambre C;
    salon S;
};

#endif // CHEMBRE_H
