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
    /**
     * @brief ShareCount constructeur par défaut
     * @param parent
     */
    explicit ShareCount(QObject *parent = nullptr);

    /**
     * @brief identifierUtilisateur retourne vrai si l'utilisateur existe
     * @param identifiant
     * @param motDePasse
     * @return
     */
    bool identifierUtilisateur(const QString &identifiant, const QString &motDePasse) const;

    /**
     * @brief setUtilisateurActif Permet d'affecter au système l'utilisateur actif
     * @param user
     */
    void setUtilisateurActif(Utilisateur& user);

    /**
     * @brief getUtilisateur retourne un utilisateur avec l'id spécifique
     * @param id
     * @return
     */
    Utilisateur getUtilisateur(const QString& id) const;

    /**
     * @brief findUtilisateur retourne vrai si l'utilisateur existe faux sinon
     * @param id
     * @return
     */
    bool findUtilisateur(const QString& id) const;

    /**
     * @brief creerUtilisateur permet d'ajouter un utilisateur à la base de donnée
     * @param user
     */
    void creerUtilisateur(Utilisateur& user);

    /**
     * @brief getUtilisateurActif retourne la référence de l'utiisateur actif
     * @return
     */
    Utilisateur& getUtilisateurActif();

    /**
     * @brief inserGroupe permet d'inserer un groupe dans la base de donnée
     * @param grp
     * @param user
     */
    void inserGroupe(const Groupe& grp, const Utilisateur& user);

    /**
     * @brief findGroupe retourne vrai si grp fait partie des groupes d'utilisateurActif
     * @param grp
     * @return
     */
    bool findGroupe(const QString& grp) const;

    /**
     * @brief appartientAuGroupe retourne vrai si user appartient à grp
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
     * @brief ajouterUneDepense permet d'ajouter une dépense au groupe actif
     * @param dep
     */
    void ajouterUneDepense(Depense& dep);

    /**
     * @brief getGroupeActif retourne le groupe actif
     * @return
     */
    Groupe& getGroupeActif();

    /**
     * @brief setGroupeActif positionne le groupe actif
     * @param grp
     */
    void setGroupeActif(Groupe& grp);

    ~ShareCount();


private:
    GestionnaireUtilisateur utilisateurs;
    Utilisateur utilisateurActif;
    GestionnaireGroupes groupes;
    BDDManager shareCountBDD;
    Groupe groupeActif;
};

#endif // SHARECOUNT_H
