#ifndef FRIGO_H
#define FRIGO_H

#include <QWidget>

namespace Ui {
class Frigo;
}

class Frigo : public QWidget
{
    Q_OBJECT
public:
    explicit Frigo(QWidget *parent = nullptr);
    ~Frigo();
signals:
    void clicAccueilFrigo();
    void clicSecuriteFrigo();
    void clicLoginFrigo();
    void clicCloseFrigo();
    void clicChembreFrigo();
    void clicParkingFrigo();
    void clicFrigoFrigo();
    void clicJardinFrigo();
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

private:
    Ui::Frigo *ui;
};

#endif // FRIGO_H
