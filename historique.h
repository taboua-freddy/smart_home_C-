#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QDateTime>
#include <QSqlQueryModel>

class Historique
{
public:
    Historique();
    bool ajouterHistorique(int id,QString action);
    QSqlQueryModel *afficherHistorique();
    bool supprimerAllHistorique();
    bool supprimerIntervalleHistorique(QString debut,QString fin);
    QSqlQueryModel * rechercheRapide(QString valeur);
private:
    int IdHist;
    QString DateHist;
    QString HeureHist;
    int Id;
    QString Action;
};

#endif // HISTORIQUE_H
