#include "Utilisateur.h"

using namespace std;

Utilisateur::Utilisateur(string u_nom, string u_identifiant, std::string u_mail, string u_motDePasse)
{
    nom=u_nom;
    identifiant=u_identifiant;
    motDePasse=u_motDePasse;

}

Utilisateur::Utilisateur(){

}

std::string Utilisateur::getNom(){
    return nom;
}
std::string Utilisateur::getIdentifiant(){
    return identifiant;
}
std::string Utilisateur::getMotDePasse(){
    return motDePasse;
}
std::string Utilisateur::getMail(){
    return mail;
}
