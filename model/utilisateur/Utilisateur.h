#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <QString>


#include "model/gestionnaireGroupes/Gestionnairegroupes.h"
class GestionnaireGroupes;
class Groupe;

/**
 * @brief The Utilisateur class est une classe qui représente un utilisateur ou un compte.
 * défini par un identifiant, un mot de passe et une adresse mail
 */
class Utilisateur
{
public:

    Utilisateur();

    QString getIdentifiant() const;

    QString getMotDePasse() const;

    QString getMail() const;

    void setIdentifiant(const QString& id);

    void setMotDePasse(const QString& mdp);

    void setMail(const QString& m);

    void ajouterAMesGroupes(Groupe& grp);

    QStringList getMesGroupesToString() const;

    GestionnaireGroupes& getMesGroupes() const;

    bool findGroupe(const QString& grp) const;

    Groupe& getGroupe(const QString& idGroupe);

    ~Utilisateur();

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
    GestionnaireGroupes* mesGroupes;
};


#endif // UTILISATEUR_H
