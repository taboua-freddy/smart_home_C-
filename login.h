#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "securite/membre.h"
#include <QMessageBox>
#include "securite/membre.h"


namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    int getId();
    ~Login();

private slots:
    void on_pushButton_clicked();

signals:
    void clicAccueil();
    void connexion();
private:
    Ui::Login *ui;
    Membre m;
};

#endif // LOGIN_H
