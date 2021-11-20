#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <QString>

/**
 * @brief The Utilisateur class est une classe qui représente un utilisateur ou un compte.
 * défini par un identifiant, un mot de passe et une adresse mail
 */
class Utilisateur
{
public:
    /**
     * @brief Utilisateur constructeur
     */
    Utilisateur();

    /**
     * @brief getIdentifiant
     * @return l'identifiant de l'utilisateur
     */
    QString getIdentifiant() const;

    /**
     * @brief getMotDePasse
     * @return  le mot de passe de l'utilisateur
     */
    QString getMotDePasse() const;

    /**
     * @brief getMail
     * @return le mail de l'utilisateur
     */
    QString getMail() const;

    /**
     * @brief setIdentifiant modifie l'identifiant
     * @param id
     */
    void setIdentifiant(const QString& id);

    /**
     * @brief setMotDePasse modifier le mdp
     * @param mdp
     */
    void setMotDePasse(const QString& mdp);

    /**
     * @brief setMail modifier le mail
     * @param m
     */
    void setMail(const QString& m);

private:

    /**
     * @brief identifiant de client
     */
    QString identifiant;

    /**
     * @brief motDePasse de compte
     */
    QString motDePasse;
    /**
     * @brief mail de client
     */
    QString mail;
    /**
     * @brief solde de client
     */
    double solde;
};


#endif // UTILISATEUR_H
