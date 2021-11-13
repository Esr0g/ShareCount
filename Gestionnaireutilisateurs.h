#ifndef GESTIONNAIREUTILISATEURS_H
#define GESTIONNAIREUTILISATEURS_H
#include <list>
#include "Utilisateur.h"


class gestionnaireUtilisateurs
{

public:
    gestionnaireUtilisateurs();
    void ajouterUtilisateur(Utilisateur* user);
    std::list<Utilisateur> getUtilisateurs();
    void setListe(std::list<Utilisateur> liste);

private:
    std::list<Utilisateur> utilisateurs;
};

#endif // GESTIONNAIREUTILISATEURS_H
