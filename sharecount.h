#ifndef SHARECOUNT_H
#define SHARECOUNT_H

#include <string>

using namespace std;

class shareCount
{
public:
    shareCount();
    bool identifierUtilisateur(string identifiant, string motDePasse);
    Utilisateur getUtilisateur(string identifiant);
};

#endif // SHARECOUNT_H
