#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <string>


class Utilisateur
{
public:
    Utilisateur();
    Utilisateur(std::string u_nom, std::string u_identifiant, std::string u_mail, std::string u_motDePasse);
    std::string getNom();
    std::string getIdentifiant();
    std::string getMotDePasse();
    std::string getMail();

private:
    std::string nom;
    std::string identifiant;
    std::string motDePasse;
    std::string mail;
    double solde;
};


#endif // UTILISATEUR_H
