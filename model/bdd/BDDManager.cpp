#include "BDDManager.h"
#include <iostream>
#include <QDateTime>

/**
 * @brief The DbManager class qui permet de gérer les entrées et les sorties
 * avec la base de donnée
 */

/**
 * @brief DbManager Constrcteur par défaut
 * @param path de la base de donnée
 */
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

/**
 * @brief createDataBase permet de créer et d'initialiser la base de donnée
 * si le fichier ShareCountDataBase.db n'existe pas
 */
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

/**
 * @brief insererUtilisateur permet d'ajouter un utilisateur à la base de donnée
 * @param user
 */
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

/**
 * @brief initialiserListeUtilisateur permet de récupérer tous les utilisateurs dans la base de donnée
 * au lancement de k'application
 * @param sc
 */
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

/**
 * @brief insererunGroupe permet d'inserer un groupe dans la table GroupesGestionBudget
 * et de mettre à jour la table UtilisateursParGroupesGDB
 * @param grp
 * @param user
 */
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

/**
 * @brief initialiserGroupeUtilisateur permet d'initialiser les groupes de l'utilisateur
 * @param grp
 * @param idUser
 */
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

/**
 * @brief appartientAuGroupe retourne vrai si user appartient a un groupe grp
 * @param user
 * @param grp
 * @return
 */
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

/**
 * @brief ajouterParticipantAuGroupe ajoute le participant "user" au groupe "grp";
 * @param user
 * @param grp
 */
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

/**
 * @brief initialiserParticipants permet d'initialiser les participants au groupe grp
 * pour l'afficher
 * @param grp
 */
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

/**
 * @brief insererUneDepense permet d'insérer une dépense pour le groupe "grp"
 * dans la table Depenses
 * @param dep
 * @param grp
 */
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

/**
 * @brief initialiserDepensesGroupe permet d'initialiser toutes les dépenses du groupe
 * @param grp
 */
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

/**
 * @brief updateHistorique a chaque fois qu'une action est fête celle-ci
 * est enregistré dans la table historique.
 * @param grp
 * @param action
 */
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
