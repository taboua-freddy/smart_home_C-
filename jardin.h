#ifndef JARDIN_H
#define JARDIN_H

#include <QWidget>

namespace Ui {
class Jardin;
}

class Jardin : public QWidget
{
    Q_OBJECT

public:
    explicit Jardin(QWidget *parent = nullptr);
    ~Jardin();
signals:
    void clicAccueilJardin();
    void clicSecuriteJardin();
    void clicLoginJardin();
    void clicCloseJardin();
    void clicChembreJardin();
    void clicParkingJardin();
    void clicFrigoJardin();
    void clicJardinJardin();
private slots:


    void on_pushButton_accueil_clicked();

    void on_pushButton_parking_clicked();

    void on_pushButton_securite_clicked();

    void on_pushButton_jardin_clicked();

    void on_pushButton_frigo_clicked();

    void on_pushButton_chambre_clicked();

    void on_pushButton_quitter_clicked();

    void on_pushButton_deconnexio_clicked();

    void on_pushButton_conn_clicked();

private:
    Ui::Jardin *ui;
};

#endif // JARDIN_H
