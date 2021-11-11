#ifndef SHARECOUNT_H
#define SHARECOUNT_H

#include <string>
#include "Utilisateur.h"

class ShareCount
{
public:
    ShareCount();
    bool identifierUtilisateur(std::string identifiant, std::string motDePasse);
    Utilisateur getUtilisateur(std::string identifiant);
};

#endif // SHARECOUNT_H
