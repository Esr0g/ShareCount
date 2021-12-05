#ifndef SHARECOUNT_H
#define SHARECOUNT_H

#include <QObject>
#include <QWidget>
#include "model/utilisateur/Utilisateur.h"
#include "model/groupe/Groupe.h"
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

    Utilisateur getUtilisateurActif();

    void inserGroupe(const Groupe& grp, const Utilisateur& user);

    ~ShareCount();


private:
    GestionnaireUtilisateur utilisateurs;
    Utilisateur utilisateurActif;
    GestionnaireGroupes groupes;
    BDDManager shareCountBDD;
};

#endif // SHARECOUNT_H
