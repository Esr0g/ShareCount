#include "ShareCount.h"
#include <iostream>

ShareCount::ShareCount(QObject *parent): QObject(parent){
    shareCountBDD.createDataBase();

    //On va ajouter au GestionnaireUtilisateur, tous les utilisateurs présent dans la base de donnée
    shareCountBDD.initialiserListeUtilisateur(utilisateurs);
}

bool ShareCount::identifierUtilisateur(const QString &identifiant, const QString &motDePasse) const {
    return utilisateurs.identifierUtilisateur(identifiant, motDePasse);
}

void ShareCount::setUtilisateurActif(Utilisateur& user) {
    utilisateurActif = user;
    shareCountBDD.initialiserGroupeUtilisateur(user.getMesGroupes(), user.getIdentifiant());
    std::cout << user.getMesGroupes().size() << std::endl;
}

Utilisateur ShareCount::getUtilisateur(const QString& id) const {
    return utilisateurs.getUtilisateur(id);
}

bool ShareCount::findUtilisateur(const QString& id) const {
    return utilisateurs.findUtilisateur(id);
}

void ShareCount::creerUtilisateur(Utilisateur& user) {
    shareCountBDD.insererUtilisateur(user);
    utilisateurs.ajouterUtilisateur(user);
}

Utilisateur ShareCount::getUtilisateurActif()  {
    return utilisateurActif;
}

void ShareCount::inserGroupe(const Groupe& grp, const Utilisateur& user) {
    shareCountBDD.insererunGroupe(grp, user);
}

ShareCount::~ShareCount() {
}
