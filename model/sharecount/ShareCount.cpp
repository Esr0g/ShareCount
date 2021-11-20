#include "ShareCount.h"

ShareCount::ShareCount(QObject *parent): QObject(parent){
}

bool ShareCount::identifierUtilisateur(const QString &mail, const QString &motDePasse) const {
    return utilisateurs.identifierUtilisateur(mail, motDePasse);
}

void ShareCount::ajouterUtilisateur(Utilisateur& u) {
    utilisateurs.ajouterUtilisateur(u);
}

void ShareCount::setUtilisateurActif(Utilisateur &user) {
    utilisateurActif = &user;
}

ShareCount::~ShareCount() {
}
