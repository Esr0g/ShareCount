#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <string>


class Utilisateur
{
public:
    /**
     * @brief Utilisateur constructeur
     */
    Utilisateur();
    Utilisateur(std::string u_nom, std::string u_identifiant, std::string u_mail, std::string u_motDePasse);
    std::string getNom();
    std::string getIdentifiant();
    std::string getMotDePasse();
    std::string getMail();

private:
    /**
     * @brief nom client
     */
    std::string nom;
    /**
     * @brief identifiant de client
     */
    std::string identifiant;
    /**
     * @brief motDePasse de compte
     */
    std::string motDePasse;
    /**
     * @brief mail de client
     */
    std::string mail;
    /**
     * @brief solde de client
     */
    double solde;
};


#endif // UTILISATEUR_H
