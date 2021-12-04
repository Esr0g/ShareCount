#include "Utilisateur.h"

Utilisateur::Utilisateur(): mesGroupes(new GestionnaireGroupes){
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

void Utilisateur::ajouterAMesGroupes(Groupe& grp) {
    mesGroupes->ajouterGroupe(grp);
}

QStringList Utilisateur::getMesGroupes() const {
    QStringList qsl;
    for (int i = 0; i < mesGroupes->size(); i++) {
        qsl << mesGroupes->getGroupe(i).getIdentifiant();
    }

    return qsl;
}

Utilisateur::~Utilisateur() {
    //delete mesGroupes;
}
