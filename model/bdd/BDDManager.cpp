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

    if (!sharCountBase.open()) {
        qDebug() << "Erreur: connection avec la base de donnée échouée" << sharCountBase.lastError();
    } else {
        qDebug() << "Connection réussie";
    }
}

void BDDManager::createDataBase() {

    if (creerDataBase) {
        QSqlQuery query;
        query.prepare("CREATE TABLE utilisateurs(idUser TEXT PRIMARY KEY,"
                      " mdp TEXT,"
                      " mail TEXT);");
        if (query.exec()) {
            qDebug() << "Création de la table utilisateur réussie.";
        } else {
            qDebug() << "Création de la table utilisateur échouée.";
        }

        query.prepare("CREATE TABLE groupes(idGroupe INTEGER PRIMARY KEY);");
        if (query.exec()) {
            qDebug() << "Création de la table groupe réussie.";
        } else {
            qDebug() << "Création de la table groupe échouée.";
        }

        query.prepare("CREATE TABLE gpUtilisateur(idUser TEXT,"
                      "idGroupe INTEGER, "
                      "FOREIGN KEY (idUser) REFERENCES utilisateurs(idUser), "
                      "FOREIGN KEY (idGroupe) REFERENCES Ggroupes(idGrope));");
        if (query.exec()) {
            qDebug() << "Création de la table gpUtilisateur réussie.";
        } else {
            qDebug() << "Création de la table gpUtilisateur échouée.";
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


