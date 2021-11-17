#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <QString>


class Utilisateur
{
public:
    /**
     * @brief Utilisateur constructeur, classe qui représente un utilisateur
     * (on peut appeler cela un compte)
     */
    Utilisateur();
    Utilisateur(const QString& u_nom, const QString u_prenom, const QString& u_identifiant, const QString& u_mail, const QString& u_motDePasse);
    QString getNom() const;
    QString getPrenom() const;
    QString getIdentifiant() const;
    QString getMotDePasse() const;
    QString getMail() const;
    void setNom(const QString& n);
    void setPrenom(const QString& p);
    void setIdentifiant(const QString& id);
    void setMotDePasse(const QString& mdp);
    void setMail(const QString& m);

private:
    /**
     * @brief nom client
     */
    QString nom;
    /**
     * @brief identifiant de client
     */
    QString identifiant;
    QString prenom;
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
