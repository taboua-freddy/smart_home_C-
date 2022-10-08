#ifndef ALERTE_H
#define ALERTE_H

#include <QSqlQueryModel>
#include <QString>
#include <QMessageBox>

class Alerte
{
public:
    Alerte();
    Alerte(int idAlerte, QString motif,QString dateAlerte);
    bool ajouterAlerte(QString motif);
    QSqlQueryModel *afficherAlerte();
    void supprimerAlerte();
private slots:

private:
    int IdAlerte;
    QString Motif;
    QString DateAlerte;
};
#endif // ALERTE_H
