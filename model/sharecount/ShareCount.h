#ifndef SHARECOUNT_H
#define SHARECOUNT_H

#include <QObject>
#include <QWidget>
#include "model/bdd/BDDManager.h"
#include "model/gestionnaireutilisateurs/Gestionnaireutilisateur.h"
#include "model/gestionnaireGroupes/Gestionnairegroupes.h"

/**
 * @brief The ShareCount class
 * Classe principale du model qui est aussi un QObjet pour pouvoir utiliser les
 * sigaux et les slots
 */
class ShareCount: public QObject
{

    Q_OBJECT

public:

    explicit ShareCount(QObject *parent = nullptr);

    bool identifierUtilisateur(const QString &identifiant, const QString &motDePasse) const;

    void setUtilisateurActif(Utilisateur& user);

    Utilisateur getUtilisateur(const QString& id) const;

    bool findUtilisateur(const QString& id) const;

    void creerUtilisateur(Utilisateur& user);

    Utilisateur& getUtilisateurActif();

    void inserGroupe(const Groupe& grp, const Utilisateur& user);

    bool findGroupe(const QString& grp) const;

    bool appartientAuGroupe(const QString& user, const QString& grp);

    void ajouterParticipantAuGroupe(const QString& user, const QString& grp);

    QStringList initialiserParticipants(const QString& grp);

    void ajouterUneDepense(Depense& dep);

    Groupe& getGroupeActif();

    void setGroupeActif(Groupe& grp);

    void initialiserListeUtilisateur();

    int getNombreUtilisateurs() const;

    ~ShareCount();


private:
    GestionnaireUtilisateur utilisateurs;
    Utilisateur utilisateurActif;
    GestionnaireGroupes groupes;
    BDDManager shareCountBDD;
    Groupe groupeActif;
};

#endif // SHARECOUNT_H
