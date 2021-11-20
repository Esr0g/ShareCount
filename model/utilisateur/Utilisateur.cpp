#include "Utilisateur.h"

Utilisateur::Utilisateur(){

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

QString Utilisateur::getIdentifiant() const {
    return identifiant;
}


QString Utilisateur::getMotDePasse() const {
    return motDePasse;
}

QString Utilisateur::getMail() const {
    return mail;
}
