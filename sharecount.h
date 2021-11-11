#ifndef SHARECOUNT_H
#define SHARECOUNT_H

#include <string>
#include "utilisateur.h"

using namespace std;

class ShareCount
{
public:
    ShareCount();
    bool identifierUtilisateur(string identifiant, string motDePasse);
    Utilisateur getUtilisateur(string identifiant);
};

#endif // SHARECOUNT_H
