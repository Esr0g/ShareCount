#ifndef SHARECOUNT_H
#define SHARECOUNT_H

#include <QObject>
#include <model/gestionnaireutilisateurs/Gestionnaireutilisateurs.h>
#include <model/utilisateur/Utilisateur.h>

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
    bool identifierUtilisateur(const QString &mail, const QString &motDePasse) const;

    void setUtilisateurActif(Utilisateur &user);

    ~ShareCount();

public slots:
    /**
     * @brief ajouterUtilisateur
     * @param u
     */
    void ajouterUtilisateur(Utilisateur& u);


private:
    GestionnaireUtilisateur utilisateurs;
    Utilisateur *utilisateurActif;
};

#endif // SHARECOUNT_H
