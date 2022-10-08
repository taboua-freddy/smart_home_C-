#-------------------------------------------------
#
# Project created by QtCreator 2018-12-04T17:46:03
#
#-------------------------------------------------

QT       += core gui sql network serialport multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyHome
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    securite.cpp \
    parking.cpp \
    connexion.cpp \
    parking/alerte.cpp \
    parking/historique.cpp \
    parking/placeparking.cpp \
    parking/smtp.cpp \
    parking/vehicule.cpp \
    parking/vehiculeproprietaire.cpp \
    jardin.cpp \
    chembre.cpp \
    frigo.cpp \
    securite/admin.cpp \
    securite/fenetre.cpp \
    securite/membre.cpp \
    securite/porte.cpp \
    chambre/chambre.cpp \
    chambre/salon.cpp \
    arduino.cpp \
    parking/cartem.cpp \
    stylesheet.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    securite.h \
    parking.h \
    connexion.h \
    parking/alerte.h \
    parking/historique.h \
    parking/placeparking.h \
    parking/smtp.h \
    parking/vehicule.h \
    parking/vehiculeproprietaire.h \
    jardin.h \
    chembre.h \
    frigo.h \
    securite/admin.h \
    securite/fenetre.h \
    securite/membre.h \
    securite/porte.h \
    chambre/chambre.h \
    chambre/salon.h \
    arduino.h \
    parking/cartem.h \
    stylesheet.h

FORMS += \
        mainwindow.ui \
    login.ui \
    parking.ui \
    securite.ui \
    jardin.ui \
    chembre.ui \
    frigo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc


SUBDIRS += \
    MyHome.pro
