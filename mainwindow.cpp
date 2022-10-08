#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();

    /* initialisation des sons*/
    son = new QMediaPlayer;
    exclamation = new QMediaPlayer;
    erreur = new QMediaPlayer;

    exclamation->setMedia(QMediaContent(QUrl("qrc:/sons/Windows Exclamation.wav")));
    erreur->setMedia(QMediaContent(QUrl("qrc:/sons/Windows Critical Stop.wav")));
    son->setMedia(QMediaContent(QUrl("qrc:/sons/clic.mp3")));

    /* initialisation de la barre de titre et icones*/
    qApp->setStyleSheet(stylesheet.getStyleSheet(0));
    setWindowIcon(QIcon(QPixmap(":/img_parking/New folder/home5---Copie-ConvertImage-ConvertImage.png")));
    setWindowTitle("MyHome");
    setFixedSize(QSize(1100,700));

    fr = new QTranslator;
    en = new QTranslator;
    fr->load(":/pack/french.qm");
    en->load(":/pack/english.qm");
    qApp->installTranslator(fr);

    /* initialisation des fenetres*/
    login = new Login;
    parking =  new Parking;
    securite = new Securite;
    chembre = new Chembre;
    frigo = new Frigo;
    jardin = new Jardin;

    ui->stackedWidget->addWidget(login);
    ui->stackedWidget->addWidget(parking);
    ui->stackedWidget->addWidget(securite);
    ui->stackedWidget->addWidget(jardin);
    ui->stackedWidget->addWidget(frigo);
    ui->stackedWidget->addWidget(chembre);

    ui->stackedWidget->setCurrentIndex(1);

    connect(login,SIGNAL(clicAccueil()),this,SLOT(allerAccueil()));

    connect(parking,SIGNAL(clicAccueil()),this,SLOT(allerAccueil()));
    connect(parking,SIGNAL(clicSecurite()),this,SLOT(on_pushButton_2_clicked()));
    connect(parking,SIGNAL(clicLoginParking()),this,SLOT(on_pushButton_6_clicked()));
    connect(parking,SIGNAL(clicCloseParking()),this,SLOT(on_pushButton_7_clicked()));
    connect(parking,SIGNAL(clicJardinParking()),this,SLOT(on_pushButton_jardin_clicked()));
    connect(parking,SIGNAL(clicChembreParking()),this,SLOT(on_pushButton_chambre_clicked()));
    connect(parking,SIGNAL(clicFrigoParking()),this,SLOT(on_pushButton_frigo_clicked()));
    connect(parking,SIGNAL(clicParkingParking()),this,SLOT(on_pushButton_3_clicked()));
    /* gestion des paramètres et son */
    connect(parking,SIGNAL(sonMuet()),this,SLOT(sonMuet()));
    connect(parking,SIGNAL(sonNonMuet()),this,SLOT(sonMuet()));
    connect(parking,SIGNAL(jouer()),this,SLOT(jouerMusique()));
    connect(parking,SIGNAL(jouerExcla()),this,SLOT(jouerExclamation()));
    connect(parking,SIGNAL(jouerEr()),this,SLOT(jouerErreur()));
    connect(parking,SIGNAL(langueFrancaise()),this,SLOT(chargerLangueFr()));
    connect(parking,SIGNAL(langueAnglaise()),this,SLOT(chargerLangueEn()));
    connect(parking,SIGNAL(themeSombre()),this,SLOT(ChargerThemeSombre()));
    connect(parking,SIGNAL(themeClaire()),this,SLOT(ChargerThemeClaire()));


    connect(frigo,SIGNAL(clicLoginFrigo()),this,SLOT(on_pushButton_6_clicked()));
    connect(frigo,SIGNAL(clicAccueilFrigo()),this,SLOT(allerAccueil()));
    connect(frigo,SIGNAL(clicSecuriteFrigo()),this,SLOT(on_pushButton_2_clicked()));
    connect(frigo,SIGNAL(clicCloseFrigo()),this,SLOT(on_pushButton_7_clicked()));
    connect(frigo,SIGNAL(clicJardinFrigo()),this,SLOT(on_pushButton_jardin_clicked()));
    connect(frigo,SIGNAL(clicChembreFrigo()),this,SLOT(on_pushButton_chambre_clicked()));
    connect(frigo,SIGNAL(clicFrigoFrigo()),this,SLOT(on_pushButton_frigo_clicked()));
    connect(frigo,SIGNAL(clicParkingFrigo()),this,SLOT(on_pushButton_3_clicked()));

    connect(jardin,SIGNAL(clicLoginJardin()),this,SLOT(on_pushButton_6_clicked()));
    connect(jardin,SIGNAL(clicAccueilJardin()),this,SLOT(allerAccueil()));
    connect(jardin,SIGNAL(clicSecuriteJardin()),this,SLOT(on_pushButton_2_clicked()));
    connect(jardin,SIGNAL(clicCloseJardin()),this,SLOT(on_pushButton_7_clicked()));
    connect(jardin,SIGNAL(clicJardinJardin()),this,SLOT(on_pushButton_jardin_clicked()));
    connect(jardin,SIGNAL(clicChembreJardin()),this,SLOT(on_pushButton_chambre_clicked()));
    connect(jardin,SIGNAL(clicFrigoJardin()),this,SLOT(on_pushButton_frigo_clicked()));
    connect(jardin,SIGNAL(clicParkingJardin()),this,SLOT(on_pushButton_3_clicked()));

    connect(chembre,SIGNAL(clicLoginChembre()),this,SLOT(on_pushButton_6_clicked()));
    connect(chembre,SIGNAL(clicAccueilChembre()),this,SLOT(allerAccueil()));
    connect(chembre,SIGNAL(clicSecuriteChembre()),this,SLOT(on_pushButton_2_clicked()));
    connect(chembre,SIGNAL(clicCloseChembre()),this,SLOT(on_pushButton_7_clicked()));
    connect(chembre,SIGNAL(clicJardinChembre()),this,SLOT(on_pushButton_jardin_clicked()));
    connect(chembre,SIGNAL(clicChembreChembre()),this,SLOT(on_pushButton_chambre_clicked()));
    connect(chembre,SIGNAL(clicFrigoChembre()),this,SLOT(on_pushButton_frigo_clicked()));
    connect(chembre,SIGNAL(clicParkingChembre()),this,SLOT(on_pushButton_3_clicked()));

    connect(securite,SIGNAL(clicLoginSecurite()),this,SLOT(on_pushButton_6_clicked()));
    connect(securite,SIGNAL(clicAccueilSecurite()),this,SLOT(allerAccueil()));
    connect(securite,SIGNAL(clicSecuriteSecurite()),this,SLOT(on_pushButton_2_clicked()));
    connect(securite,SIGNAL(clicCloseSecurite()),this,SLOT(on_pushButton_7_clicked()));
    connect(securite,SIGNAL(clicJardinSecurite()),this,SLOT(on_pushButton_jardin_clicked()));
    connect(securite,SIGNAL(clicChembreSecurite()),this,SLOT(on_pushButton_chambre_clicked()));
    connect(securite,SIGNAL(clicFrigoSecurite()),this,SLOT(on_pushButton_frigo_clicked()));
    connect(securite,SIGNAL(clicParkingSecurite()),this,SLOT(on_pushButton_3_clicked()));

    connect(this,SIGNAL(connexionSecurite()),securite,SLOT(verifier()));
    connect(this,SIGNAL(connexionParking()),parking,SLOT(verifier()));
    connect(login,SIGNAL(connexion()),this,SLOT(initialiserId()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete securite;
    delete parking;
    delete jardin;
    delete login;
    delete exclamation;
    delete erreur;
    delete son;
    delete chembre;
    delete frigo;
    delete fr;
    delete en;
}
void MainWindow::initialiserId()
{
    securite->setId(login->getId());
    parking->setId(login->getId());
    son->setMuted(false);
    exclamation->setMuted(false);
    erreur->setMuted(false);
    qApp->installTranslator(fr);
    qApp->setStyleSheet(stylesheet.getStyleSheet(0));
}
void MainWindow::on_pushButton_2_clicked() // aller a la securite
{
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    son->play();
    qDebug()<<login->getId();
    emit connexionSecurite(); //pour l ouverture de la session admin ou resident
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_3_clicked() // aller au parking
{
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    son->play();
    emit connexionParking();//pour l ouverture de la session admin ou resident
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::jouerMusique()
{
    son->play();
}

void MainWindow::sonMuet()
{
    if(son->isMuted())
    {
        son->setMuted(false);
        exclamation->setMuted(false);
        erreur->setMuted(false);
    }
    else
    {
        son->setMuted(true);
        exclamation->setMuted(true);
        erreur->setMuted(true);
    }

}

void MainWindow::ChargerThemeSombre()
{
    qApp->setStyleSheet(stylesheet.getStyleSheet(1));
}

void MainWindow::ChargerThemeClaire()
{
    qApp->setStyleSheet(stylesheet.getStyleSheet(0));
}

void MainWindow::chargerLangueFr()
{
    this->close();
    qApp->installTranslator(fr);
    MainWindow *m=new MainWindow;
    m->show();
}

void MainWindow::chargerLangueEn()
{
    this->close();
    qApp->installTranslator(en);
    MainWindow *m=new MainWindow;
    m->show();
}

void MainWindow::on_pushButton_8_pressed() // bouton de deconnexion
{
    jouerMusique();
    if(ui->pushButton_6->isHidden())
    {
        ui->pushButton_6->show();
        ui->pushButton_7->show();

    }
    else
    {
        ui->pushButton_6->hide();
        ui->pushButton_7->hide();
    }
}

void MainWindow::on_pushButton_6_clicked() // aller au login
{
    jouerMusique();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::jouerExclamation()
{
    exclamation->play();
}

void MainWindow::jouerErreur()
{
    erreur->play();
}

void MainWindow::on_pushButton_7_clicked() // bouton fermer
{
    this->close();
}

void MainWindow::on_pushButton_jardin_clicked()
{
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    jouerMusique();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::allerAccueil()
{
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    jouerMusique();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_frigo_clicked()
{
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    jouerMusique();
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_chambre_clicked()
{
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    jouerMusique();
    ui->stackedWidget->setCurrentIndex(6);
}
