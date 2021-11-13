#ifndef SHARECOUNT_H
#define SHARECOUNT_H

#include <string>
#include "Utilisateur.h"
#include "Gestionnaireutilisateurs.h"

class ShareCount
{
public:
    /**
     * @brief ShareCount constructeur
     */
    ShareCount();
    bool identifierUtilisateur(std::string identifiant, std::string motDePasse);
    Utilisateur getUtilisateur(std::string identifiant);
    gestionnaireUtilisateurs getGestionnaireUtilisateurs();
    void setGestionnaireUtilisateurs(gestionnaireUtilisateurs gu);
private:
    gestionnaireUtilisateurs utilisateurs;
};

#endif // SHARECOUNT_H
