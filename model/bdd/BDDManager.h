#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QFile>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QSqlError>
#include <map>

#include "model/utilisateur/Utilisateur.h"
#include "model/gestionnaireutilisateurs/Gestionnaireutilisateur.h"

#define DB_PATH "../ShareCount/sql/ShareCountDataBase.db"

/**
 * @brief The DbManager class qui permet de gérer les entrées et les sorties
 * avec la base de donnée
 */
class BDDManager : public QObject
{

    Q_OBJECT

public:
    /**
     * @brief DbManager Constrcteur par défaut
     * @param path de la base de donnée
     */
    explicit BDDManager(const QString& path = DB_PATH);

    /**
     * @brief createDataBase permet de créer et d'initialiser la base de donnée
     * si le fichier ShareCountDataBase.db n'existe pas
     */
    void createDataBase();

    /**
     * @brief insererUtilisateur permet d'ajouter un utilisateur à la base de donnée
     * @param user
     */
    void insererUtilisateur(const Utilisateur& user) const;

    /**
     * @brief initialiserListeUtilisateur permet de récupérer tous les utilisateurs dans la base de donnée
     * au lancement de k'application
     * @param sc
     */
    void initialiserListeUtilisateur(GestionnaireUtilisateur& users);

    /**
     * @brief insererunGroupe permet d'inserer un groupe dans la table GroupesGestionBudget
     * et de mettre à jour la table UtilisateursParGroupesGDB
     * @param grp
     * @param user
     */
    void insererunGroupe(const Groupe& grp, const Utilisateur& user);

    /**
     * @brief initialiserGroupeUtilisateur permet d'initialiser les groupes de l'utilisateur
     * @param grp
     * @param idUser
     */
    void initialiserGroupeUtilisateur(GestionnaireGroupes& grp, const QString& idUser);

    /**
     * @brief appartientAuGroupe retourne vrai si user appartient a un groupe grp
     * @param user
     * @param grp
     * @return
     */
    bool appartientAuGroupe(const QString& user, const QString& grp);

    /**
     * @brief ajouterParticipantAuGroupe ajoute le participant "user" au groupe "grp";
     * @param user
     * @param grp
     */
    void ajouterParticipantAuGroupe(const QString& user, const QString& grp);

    /**
     * @brief initialiserParticipants permet d'initialiser les participants au groupe grp
     * pour l'afficher
     * @param grp
     */
    QStringList initialiserParticipants(const QString& grp);

    /**
     * @brief insererUneDepense permet d'insérer une dépense pour le groupe "grp"
     * dans la table Depenses
     * @param dep
     * @param grp
     */
    void insererUneDepense(const Depense& dep, const Groupe& grp);

    /**
     * @brief initialiserDepensesGroupe permet d'initialiser toutes les dépenses du groupe
     * @param grp
     */
    void initialiserDepensesGroupe(Groupe& grp);


private:
    QSqlDatabase sharCountBase;
    bool creerDataBase;
};

#endif // DBMANAGER_H
