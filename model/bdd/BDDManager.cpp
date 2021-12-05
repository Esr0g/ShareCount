#include "BDDManager.h"
#include <iostream>
#include "model/groupe/GroupeGestionBuget.h"

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

        query.prepare("CREATE TABLE UtilisateursParGroupesGDB(idGroupe TEXT, "
                      "idUser TEXT,"
                      "PRIMARY KEY(idGroupe, idUser),"
                      "FOREIGN KEY (idUser) REFERENCES Utilisateurs(idUser),"
                      "FOREIGN KEY (idGroupe) REFERENCES GroupesGestionBudget(idGroupe));");
        if (query.exec()) {
            qDebug() << "Création de la table UtilisateursParGroupesGDB réussie.";
        } else {
            qDebug() << "Création de la table UtilisateursParGroupesGDB échouée.";
        }

        query.prepare("CREATE TABLE Historique(noHist INTEGER, "
                      "idGroupe TEXT,"
                      "contenu TEXT NOT NULL,"
                      "dateHisto TEXT NOT NULL,"
                      "PRIMARY KEY(noHist, idGroupe),"
                      "FOREIGN KEY (idGroupe) REFERENCES GroupesGestionBudget(idGroupe));");
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

void BDDManager::insererunGroupe(const Groupe& grp, const Utilisateur& user) {
    QSqlQuery query;
    query.prepare("INSERT INTO GroupesGestionBudget(idGroupe, idUser, description, dateCreationGrp )"
                   "VALUES (:idGroupe, :idUser, :description, :dateCreationGrp);");
    query.bindValue(":idGroupe", QVariant(grp.getIdentifiant()));
    query.bindValue(":idUser", QVariant(user.getIdentifiant()));
    query.bindValue(":description", QVariant(grp.getDescription()));
    query.bindValue(":dateCreationGrp", QVariant(grp.getDateCreation()));

    if (query.exec()) {
        qDebug() << "Le groupe a bien était ajouté a la table groupe";
    } else {
        qDebug() << "Echec de l'ajout du groupe";
    }

    query.clear();
    query.prepare("INSERT INTO UtilisateursParGroupesGDB(idGroupe, idUser)"
                  "VALUES(:idGroupe, :idUser);");
    query.bindValue(":idGroupe", QVariant(grp.getIdentifiant()));
    query.bindValue(":idUser", QVariant(user.getIdentifiant()));

    if (query.exec()) {
        qDebug() << "UtilisateursParGroupesGDB mise a jour";
    } else {
        qDebug() << "UtilisateursParGroupesGDB echèc mise à jour";
    }
}

void BDDManager::initialiserGroupeUtilisateur(GestionnaireGroupes& grp, const QString& idUser) {
    QSqlQuery query;

    query.prepare("SELECT DISTINCT GGB.idGroupe, GGB.idUser, GGB.description, GGB.dateCreationGrp "
                  "FROM GroupesGestionBudget GGB, UtilisateursParGroupesGDB UPG "
                  "WHERE UPG.idUser = :id AND UPG.idGroupe = GGB.idGroupe;");
    query.bindValue(":id", QVariant(idUser));

    if (query.exec()) {
        qDebug() << "Selection du groupe réussie";
    } else {
        qDebug() << "Selection du groupe échoué";
    }

    while (query.next()) {
        QString idGroupe = query.value("idGroupe").toString();
        QString idUser = query.value("idUser").toString();
        QString description = query.value("description").toString();
        QString date = query.value("dateCreationGrp").toString();
        GroupeGestionBuget ggb(idGroupe, description);
        ggb.setDate(date);
        grp.ajouterGroupe(ggb);
    }
}

bool BDDManager::appartientAuGroupe(const QString& user, const QString& grp) {
    bool trouve = false;

    QSqlQuery query;

    query.prepare("SELECT DISTINCT idGroupe FROM UtilisateursParGroupesGDB "
                  "WHERE idUser = :idUser;");
    query.bindValue(":idUser", QVariant(user));

    if (query.exec()) {
        qDebug() << "Requête appartientAuGroupe réussie";
    } else {
        qDebug() << "Requête appartientAuGroupe échouée " << sharCountBase.lastError().text();
    }

    while (query.next() && !trouve) {
        QString idGroupe = query.value("idGroupe").toString();
        if (idGroupe == grp) {
            trouve = true;
        }
    }

    return trouve;
}

void BDDManager::ajouterParticipantAuGroupe(const QString& user, const QString& grp) {
    QSqlQuery query;
    query.prepare("INSERT INTO UtilisateursParGroupesGDB(idGroupe, idUser)"
                  "VALUES(:idGroupe, :idUser);");
    query.bindValue(":idGroupe", QVariant(grp));
    query.bindValue(":idUser", QVariant(user));

    if (query.exec()) {
        qDebug() << "UtilisateursParGroupesGDB mise a jour";
    } else {
        qDebug() << "UtilisateursParGroupesGDB échec mise à jour";
    }
}

QStringList BDDManager::initialiserParticipants(const QString& grp) {
    QSqlQuery query;

    query.prepare("SELECT DISTINCT idUser FROM UtilisateursParGroupesGDB "
                  "WHERE idGroupe = :idGroupe;");
    query.bindValue(":idGroupe", QVariant(grp));

    if (query.exec()) {
        qDebug() << "Requête initaliserParticipants réussie";
    } else {
        qDebug() << "Requête initaliserParticipants échouée";
    }

    QStringList listeUser;


    while (query.next()) {
        QString idUser = query.value("idUser").toString();
        listeUser << idUser;
    }

    return listeUser;
}
