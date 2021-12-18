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

class BDDManager : public QObject
{

    Q_OBJECT

public:
    explicit BDDManager(const QString& path = DB_PATH);

    void createDataBase();

    void insererUtilisateur(const Utilisateur& user) const;

    void initialiserListeUtilisateur(GestionnaireUtilisateur& users);

    void insererunGroupe(const Groupe& grp, const Utilisateur& user);

    void initialiserGroupeUtilisateur(GestionnaireGroupes& grp, const QString& idUser);

    bool appartientAuGroupe(const QString& user, const QString& grp);

    void ajouterParticipantAuGroupe(const QString& user, const QString& grp);

    QStringList initialiserParticipants(const QString& grp);

    void insererUneDepense(const Depense& dep, const Groupe& grp);

    void initialiserDepensesGroupe(Groupe& grp);

    void updateHistorique(const QString& grp, const QString& action);


private:
    QSqlDatabase sharCountBase;
    bool creerDataBase;
};

#endif // DBMANAGER_H
