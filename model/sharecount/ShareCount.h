#ifndef SHARECOUNT_H
#define SHARECOUNT_H

#include <QObject>
#include <model/gestionnaireutilisateurs/Gestionnaireutilisateurs.h>
#include <model/utilisateur/Utilisateur.h>

#include <model/gestionnaireGroupes/Gestionnairegroupes.h>

#include <model/bdd/BDDManager.h>

#include <model/bdd/BDDManager.h>

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
    void setUtilisateurActif(Utilisateur &user);

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

    ~ShareCount();

public slots:
    /**
     * @brief ajouterUtilisateur permet de créer un compte utilisateur
     * @param u
     */
    void ajouterUtilisateur(Utilisateur& u);


private:
    GestionnaireUtilisateur utilisateurs;
    Utilisateur *utilisateurActif;

    gestionnaireGroupes groupes;

    BDDManager shareCountBDD;


};

#endif // SHARECOUNT_H
