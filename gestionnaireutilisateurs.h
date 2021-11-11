#ifndef GESTIONNAIREUTILISATEURS_H
#define GESTIONNAIREUTILISATEURS_H
#include <list>

using namespace std;

class gestionnaireUtilisateurs
{
public:
    gestionnaireUtilisateurs();
    void ajouterUtilisateur(Utilisateur user);
private:
    Utilisateur users[100];
};

#endif // GESTIONNAIREUTILISATEURS_H
