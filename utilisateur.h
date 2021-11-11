#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <string>

using namespace std;

class Utilisateur
{
public:
    Utilisateur();

private:
    string nom;
    string identifiant;
    string motDePasse;
    string mail;
    double solde;
};


#endif // UTILISATEUR_H
