#include "ShareCount.h"
#include <QWidget>
#include <vues/pageprincipale/PagePrincipale.h>
#include <model/bdd/BDDManager.h>

ShareCount::ShareCount(QObject *parent): QObject(parent){
    shareCountBDD.createDataBase();

    //On va ajouter au GestionnaireUtilisateur, tous les utilisateurs présent dans la base de donnée
    shareCountBDD.initialiserListeUtilisateur(utilisateurs);
}

bool ShareCount::identifierUtilisateur(const QString &identifiant, const QString &motDePasse) const {
    return utilisateurs.identifierUtilisateur(identifiant, motDePasse);
}

void ShareCount::ajouterUtilisateur(Utilisateur& u) {
    utilisateurs.ajouterUtilisateur(u);
}

void ShareCount::setUtilisateurActif(Utilisateur &user) {
    *utilisateurActif = user;
}

Utilisateur ShareCount::getUtilisateur(const QString& id) const{
    return utilisateurs.getUtilisateur(id);
}

bool ShareCount::findUtilisateur(const QString& id) const {
    return utilisateurs.findUtilisateur(id);
}

void ShareCount::creerUtilisateur(Utilisateur& user) {
    shareCountBDD.insererUtilisateur(user);
    utilisateurs.ajouterUtilisateur(user);
}

ShareCount::~ShareCount() {
}
