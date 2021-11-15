#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <QString>


class Utilisateur
{
public:
    /**
     * @brief Utilisateur constructeur
     */
    Utilisateur();
    Utilisateur(QString u_nom, QString u_identifiant, QString u_mail, QString u_motDePasse);
    QString getNom() const;
    QString getIdentifiant() const;
    QString getMotDePasse() const;
    QString getMail() const;

private:
    /**
     * @brief nom client
     */
    QString nom;
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
