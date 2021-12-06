#include "BDDManager.h"
#include <iostream>
#include <QDateTime>

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
                      "valeurBase REAL NOT NULL,"
                      "nomDep TEXT NOT NULL,"
                      "BoolDepRembourse INTEGER DEFAULT 0," // Ceci représente un booléen
                      "valeurRembourse REAL DEFAULT 0,"
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
                      "valeurBase REAL NOT NULL,"
                      "BoolDetteRembourse INTEGER DEFAULT 0," // Ceci représente un booléen
                      "valeurRembourse REAL DEFAULT 0,"
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
        QString action;
        action.append(user.getIdentifiant());
        action.append(" a crée le groupe.");
        updateHistorique(grp.getIdentifiant(), action );
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
    grp.clear();

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
        Groupe ggb(idGroupe, description);
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
        QString action;
        action.append(user);
        action.append(" ajouté au groupe.");
        updateHistorique(grp, action );
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

void BDDManager::insererUneDepense(const Depense& dep, const Groupe& grp) {
    QSqlQuery query;

    query.prepare("INSERT INTO Depenses(idUser, idGroupe, noDep, valeurBase, nomDep, dateDep)"
                  "VALUES (:idUser, :idGroupe, :noDep, :valeurBase, :nomDep, :dateDep);");
    query.bindValue(":idUser", QVariant(dep.getCreateur()));
    query.bindValue(":idGroupe", QVariant(grp.getIdentifiant()));
    query.bindValue(":noDep", QVariant(dep.getNumDepense()));
    query.bindValue(":valeurBase", QVariant(dep.getVealeurBase()));
    query.bindValue(":nomDep", QVariant(dep.getNom()));
    query.bindValue(":dateDep", QVariant(dep.getdate()));

    if (query.exec()) {
        qDebug() << "Requête inserUneDepense réussie";
        QString action;
        action.append(dep.getCreateur());
        action.append(" a crée un dépense.");
        updateHistorique(grp.getIdentifiant(), action );
    } else {
        qDebug() << "Requête insererUneDepense échouée" << query.lastError().text();
    }
}

void BDDManager::initialiserDepensesGroupe(Groupe& grp) {
    QSqlQuery query;

    query.prepare("SELECT * FROM Depenses "
                  "WHERE idGroupe = ? ;");
    query.addBindValue(QVariant(grp.getIdentifiant()));

    if (query.exec()) {
        qDebug() << "Selection pour les dépenses du groupe réussie";
    } else {
        qDebug() << "Selection pour les dépenses du groupe échouée " << query.lastError().text();
    }

    grp.clearDepenses();

    while (query.next()) {
        QString idUser = query.value("idUser").toString();
        int noDep = query.value("noDep").toInt();
        double valeurBase = query.value("valeurBase").toDouble();
        bool boolDepRembourse = query.value("boolDepRembourse").toBool();
        double valeurRembourse = query.value("valeurRembourse").toDouble();
        QString dateDep = query.value("dateDep").toString();
        QString nomDep = query.value("nomDep").toString();

        //std::cout << std::to_string(valeurBase) << std::endl;
        Depense dep(noDep, idUser, valeurBase, nomDep, dateDep, valeurRembourse, boolDepRembourse);
        grp.ajouterUneDepense(dep);
    }
}

void BDDManager::updateHistorique(const QString& grp, const QString& action) {
    QSqlQuery query;
    QDateTime date;

    query.prepare("INSERT INTO Historique(idGroupe, contenu, dateHisto) "
                  "VALUES(:idGroupe, :contenu, :dateHisto);");
    query.bindValue(":idGroupe", QVariant(grp));
    query.bindValue(":contenu", QVariant(action));
    query.bindValue(":dateHisto", QVariant(date.currentDateTime().toString("dd/MM/yyyy hh:mm:ss")));

    if (query.exec()) {
        qDebug() << "Historique mise à jour";
    } else {
        qDebug() << "Echec de la mise à jour de l'historique" << query.lastError().text();
    }
}
