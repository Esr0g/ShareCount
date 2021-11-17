QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Connecte.cpp \
    Connexion.cpp \
    Creationcompte.cpp \
    screen/fenetreprincipale/FenetrePrincipale.cpp \
    model/gestionnaireutilisateurs/Gestionnaireutilisateurs.cpp \
    Mainwindow.cpp \
    vues/pagecreationcompte/PageCreationCompte.cpp \
    vues/pageaccueil/PageAccueil.cpp \
    model/sharecount/Sharecount.cpp \
    model/utilisateur/Utilisateur.cpp \
    main.cpp

HEADERS += \
    Connecte.h \
    Connexion.h \
    Creationcompte.h \
    screen/fenetreprincipale/FenetrePrincipale.h \
    model/gestionnaireutilisateurs/Gestionnaireutilisateurs.h \
    Mainwindow.h \
    vues/pagecreationcompte/PageCreationCompte.h \
    vues/pageaccueil/PageAccueil.h \
    model/sharecount/Sharecount.h \
    model/utilisateur/Utilisateur.h

FORMS += \
    Connecte.ui \
    Connexion.ui \
    Creationcompte.ui \
    screen/fenetreprincipale/FenetrePrincipale.ui \
    Mainwindow.ui \
    vues/pagecreationcompte/PageCreationCompte.ui \
    vues/pageaccueil/PageAccueil.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
