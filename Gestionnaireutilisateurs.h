#ifndef GESTIONNAIREUTILISATEURS_H
#define GESTIONNAIREUTILISATEURS_H
#include <list>
#include "Utilisateur.h"

class gestionnaireUtilisateurs
{

public:
    gestionnaireUtilisateurs();
    void ajouterUtilisateur(Utilisateur user);

private:
    Utilisateur users[100];
};

#endif // GESTIONNAIREUTILISATEURS_H
