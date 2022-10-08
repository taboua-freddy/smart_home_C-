#ifndef PARKING_H
#define PARKING_H

#include <QMainWindow>
#include "parking/smtp.h"
#include "parking/vehicule.h"
#include "parking/placeparking.h"
#include "parking/vehiculeproprietaire.h"
#include "parking/historique.h"
#include "parking/alerte.h"
#include "securite.h"
#include "arduino.h"
#include "parking/cartem.h"

namespace Ui {
class Parking;
}

class Parking : public QWidget
{
    Q_OBJECT

public:
    explicit Parking(QWidget *parent = nullptr);
    void setId(int id);
    ~Parking();
private slots:
    void verifier();
    void sendMail();
    void mailSent(QString);

    void updateComboBox();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_vide_clicked();

    void on_pushButton_modifier_clicked();

    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_ajouter_places_clicked();

    void updateAffichage();

    void on_affecter_invite_clicked();

    void on_pushButton_liberer_vis_clicked();

    void on_lineEdit_3_textEdited(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_historique_clicked();

    void on_pushButton_ouvrir_clicked();

    void on_calendarWidget_activated(const QDate &date);

    void on_supprimer_Hist_clicked();

    void on_supprimer_all_hist_clicked();

    void updateAffichageHistorique();

    void on_supprimer_all_guest_clicked();

    void on_lineEdit_7_textEdited(const QString &arg1);

    void on_modifEtat_clicked();

    void on_Button_efface_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_jardin_clicked();

    void on_pushButton_frigo_clicked();

    void on_pushButton_chambre_clicked();

    void scannerCarte();
    void on_scanner_clicked();

    void on_arreter_scanne_clicked();

    void on_pushButton_clicked();

    void on_suppimer_carte_clicked();

    void on_pushButton_carte_clicked();

    void on_tableView_5_doubleClicked(const QModelIndex &index);

    void cacherLesBoutonOption();
    void on_setting_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

signals:
    void clicAccueil();
    void clicSecurite();
    void clicLoginParking();
    void clicCloseParking();
    void clicChembreParking();
    void clicParkingParking();
    void clicFrigoParking();
    void clicJardinParking();
    void espaceResident();
    void themeSombre();
    void themeClaire();
    void sonMuet();
    void sonNonMuet();
    void langueFrancaise();
    void langueAnglaise();
    void jouer();
    void jouerExcla();
    void jouerEr();
signals:
    void lecture();
private:
    Ui::Parking *ui;
    PlaceParking p;
    Historique h;
    Membre m;
    Alerte a;
    CarteM c;

    QByteArray data; // variable contenant les données reçues
    QString d;
    int mail;
    QString IdCarte;
    Arduino A; // objet temporaire
};

#endif // PARKING_H
