#include "BDDManager.h"
#include <QFile>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QSqlError>

BDDManager::BDDManager(const QString& path) : creerDataBase(false)
{
    sharCountBase = QSqlDatabase::addDatabase("QSQLITE");
    sharCountBase.setDatabaseName(path);
    sharCountBase.open();

    if (!sharCountBase.open()) {
        qDebug() << "Erreur: connection avec la base de donnée échouée";
    } else {
        qDebug() << "Connection réussie" ;
    }
}

void BDDManager::createDataBase() {

    if (creerDataBase) {
        QSqlQuery query;
        query.prepare("CREATE TABLE Utilisateurs(idUser TEXT PRIMARY KEY,"
                      " mdp TEXT NOT NULL,"
                      " mail TEXT NULL);");
        if (query.exec()) {
            qDebug() << "Création de la table Utilisateurs réussie.";
        } else {
            qDebug() << "Création de la table Utilisateurs échouée.";
        }

        query.prepare("CREATE TABLE GroupesGestionBudget(idGroupe TEXT, "
                      "idUser TEXT,"
                      "description TEXT NULL,"
                      "dateCreationGrp TEXT NOT NULL,"
                      "PRIMARY KEY(idGroupe, idUser),"
                      "FOREIGN KEY (idUser) REFERENCES Utilisateurs(idUser));");
        if (query.exec()) {
            qDebug() << "Création de la table GroupesGestionBudget réussie.";
        } else {
            qDebug() << "Création de la table GroupesGestionBudget échouée.";
        }

        query.prepare("CREATE TABLE UtilisateursParGroupes(idGroupe TEXT, "
                      "idUser TEXT,"
                      "PRIMARY KEY(idGroupe, idUser),"
                      "FOREIGN KEY (idUser) REFERENCES Utilisateurs(idUser),"
                      "FOREIGN KEY (idGroupe) REFERENCES Utilisateurs(idGroupe));");
        if (query.exec()) {
            qDebug() << "Création de la table UtilisateursParGroupes réussie.";
        } else {
            qDebug() << "Création de la table UtilisateursParGroupes échouée.";
        }

        query.prepare("CREATE TABLE Historique(noHist INTEGER, "
                      "idGroupe TEXT,"
                      "contenu TEXT NOT NULL,"
                      "dateHisto TEXT,"
                      "PRIMARY KEY(noHist, idGroupe),"
                      "FOREIGN KEY (idGroupe) REFERENCES Utilisateurs(idGroupe));");
        if (query.exec()) {
            qDebug() << "Création de la table Historique réussie.";
        } else {
            qDebug() << "Création de la table Historique échouée.";
        }

        query.prepare("CREATE TABLE Depenses(idUser TEXT,"
                      "idGroupe TEXT,"
                      "noDep INTEGER,"
                      "valeurBase INTEGER NOT NULL,"
                      "BoolDepRembourse INTEGER DEFAULT 0," // Ceci représente un booléen
                      "valeurRembourse INTEGER DEFAULT 0,"
                      "dateDep TEXT NOT NULL,"
                      "PRIMARY KEY (idUser, idGroupe, noDep),"
                      "FOREIGN KEY (idUser) REFERENCES Utilisateurs(idUser), "
                      "FOREIGN KEY (idGroupe) REFERENCES GroupesGestionBudget(idGroupe));");
        if (query.exec()) {
            qDebug() << "Création de la table Depenses réussie.";
        } else {
            qDebug() << "Création de la table Depenses échouée.";
        }

        query.prepare("CREATE TABLE Dettes(idUser TEXT,"
                      "noDep INTEGER,"
                      "valeurBase INTEGER NOT NULL,"
                      "BoolDetteRembourse INTEGER DEFAULT 0," // Ceci représente un booléen
                      "valeurRembourse INTEGER DEFAULT 0,"
                      "dateDette TEXT NOT NULL,"
                      "PRIMARY KEY (idUser, noDep),"
                      "FOREIGN KEY (idUser) REFERENCES Utilisateurs(idUser), "
                      "FOREIGN KEY (noDep) REFERENCES Depenses(noDep));");
        if (query.exec()) {
            qDebug() << "Création de la table Dettes réussie.";
        } else {
            qDebug() << "Création de la table Dettes échouée.";
        }
    }
}

void BDDManager::insererUtilisateur(const Utilisateur& user) const {
    QSqlQuery query;
    query.prepare("INSERT INTO utilisateurs(idUser, mdp, mail)"
                   "VALUES (:idUser, :mdp, :mail);");
    query.bindValue(":idUser", QVariant(user.getIdentifiant()));
    query.bindValue(":mdp", QVariant(user.getMotDePasse()));
    query.bindValue(":mail", QVariant(user.getMail()));

    if (query.exec()) {
        qDebug() << "L'utilisateur a bien était ajouté a a table utilisateur";
    } else {
        qDebug() << "Echec de l'ajout de l'utilisateur";
    }
}

void BDDManager::initialiserListeUtilisateur(GestionnaireUtilisateur& users) {
    QSqlQuery query;

    query.prepare("Select * from utilisateurs;");

    if (query.exec()) {
        qDebug() << "Selection pour initialisation de la liste des utilisateurs réussie";
    } else {
        qDebug() << "Selection pour initialisation de la liste des utilisateurs échouée";
    }

    while (query.next()) {
        QString id = query.value("idUser").toString();
        QString mdp = query.value("mdp").toString();
        QString mail = query.value("mail").toString();
        Utilisateur u;
        u.setIdentifiant(id);
        u.setMotDePasse(mdp);
        u.setMail(mail);
        users.ajouterUtilisateur(u);
    }
}


