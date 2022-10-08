#include "mainwindow.h"
#include <QApplication>
#include "login.h"
#include "parking.h"
#include "securite.h"
#include "connexion.h"
#include "QTimer"
#include "QSplashScreen"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /*QSplashScreen *spl= new QSplashScreen;
    Connexion c;
    spl->setPixmap(QPixmap(":/img_parking/New folder/home5-ConvertImage.png"));
    spl->show();
    QTimer::singleShot(3000,spl,SLOT(close()));
    if(c.ouvrirConnexion())
        QTimer::singleShot(2500,&w,SLOT(show()));*/

    Connexion c;
    if(c.ouvrirConnexion())
    w.show();

    return a.exec();
}
