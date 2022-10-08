#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QTranslator>
#include "securite.h"
#include "parking.h"
#include "login.h"
#include "chembre.h"
#include "frigo.h"
#include "jardin.h"
#include "stylesheet.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QMainWindow *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void jouerMusique();
    void sonMuet();
    void ChargerThemeSombre();
    void ChargerThemeClaire();
    void chargerLangueFr();
    void chargerLangueEn();
    void on_pushButton_8_pressed();
    void on_pushButton_6_clicked();
    void jouerExclamation();
    void jouerErreur();
    void on_pushButton_7_clicked();

    void on_pushButton_jardin_clicked();
    void allerAccueil();
    void on_pushButton_frigo_clicked();
    void initialiserId();
    void on_pushButton_chambre_clicked();
signals:
    void connexionSecurite();
    void connexionParking();

public:
    Ui::MainWindow *ui;
    QMediaPlayer *exclamation;
    QMediaPlayer *erreur;
    QMediaPlayer *son;
    QTranslator *fr;
    QTranslator *en;
    Securite *securite;
    Parking *parking;
    Login  *login;
    Chembre *chembre;
    Jardin *jardin;
    Frigo *frigo;
    StyleSheet stylesheet;
};

#endif // MAINWINDOW_H
