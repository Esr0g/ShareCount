#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <string>

using namespace std;

class Utilisateur
{
public:
    Utilisateur();
    Utilisateur(string u_nom, string u_identifiant, string u_motDePasse);

private:
    string nom;
    string identifiant;
    string motDePasse;
    string mail;
    double solde;
};


#endif // UTILISATEUR_H
