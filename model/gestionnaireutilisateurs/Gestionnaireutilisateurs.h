#ifndef GESTIONNAIREUTILISATEURS_H
#define GESTIONNAIREUTILISATEURS_H
#include <map>
#include "model/utilisateur/Utilisateur.h"

class GestionnaireUtilisateur
{

public:
    /**
     * @brief class GestionnaireUtilisateur constructeur
     */
    explicit GestionnaireUtilisateur();
    void ajouterUtilisateur(Utilisateur& user);
    bool identifierUtilisateur(const QString& mail, const QString& mdp) const;

private:
    std::map<QString, Utilisateur> utilisateurs;
};

#endif // GESTIONNAIREUTILISATEURS_H
