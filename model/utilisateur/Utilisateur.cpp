#include "Utilisateur.h"

Utilisateur::Utilisateur(){

}

Utilisateur::Utilisateur(const QString& u_nom, const QString u_prenom,
                         const QString& u_identifiant, const QString& u_mail,
                         const QString& u_motDePasse) :
    nom(u_nom),
    prenom(u_prenom),
    identifiant(u_identifiant),
    mail(u_mail),
    motDePasse(u_motDePasse)
{

}

void Utilisateur::setNom(const QString& n) {
    nom = n;
}

void Utilisateur::setPrenom(const QString& p) {
    prenom = p;
}

void Utilisateur::setIdentifiant(const QString& id) {
    identifiant = id;
}

void Utilisateur::setMotDePasse(const QString& mdp) {
    motDePasse = mdp;
}

void Utilisateur::setMail(const QString& m) {
    mail = m;
}

QString Utilisateur::getNom() const {
    return nom;
}

QString Utilisateur::getIdentifiant() const {
    return identifiant;
}

QString Utilisateur::getPrenom() const {
    return prenom;
}

QString Utilisateur::getMotDePasse() const {
    return motDePasse;
}

QString Utilisateur::getMail() const {
    return mail;
}
