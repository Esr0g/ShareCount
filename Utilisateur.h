#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <string>


class Utilisateur
{
public:
    Utilisateur();
    Utilisateur(std::string u_nom, std::string u_identifiant, std::string u_motDePasse);

private:
    std::string nom;
    std::string identifiant;
    std::string motDePasse;
    std::string mail;
    double solde;
};


#endif // UTILISATEUR_H
