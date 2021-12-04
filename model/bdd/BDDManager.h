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

    void insererunGroupe(Groupe& grp);


private:
    QSqlDatabase sharCountBase;
    bool creerDataBase;
};

#endif // DBMANAGER_H
