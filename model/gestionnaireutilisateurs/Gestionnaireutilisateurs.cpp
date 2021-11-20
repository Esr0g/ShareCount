#include "Gestionnaireutilisateurs.h"
#include "model/utilisateur/Utilisateur.h"
#include "model/sharecount/ShareCount.h"
#include <iostream>
#include <string>

GestionnaireUtilisateur::GestionnaireUtilisateur()
{
}

bool GestionnaireUtilisateur::identifierUtilisateur(const QString& id, const QString& mdp) const{
    std::map<QString, Utilisateur>::const_iterator it = utilisateurs.find(id);

    bool identifie = false;

    if (it == utilisateurs.end()) {
        identifie = false;
    } else {
        identifie = true;
        if (mdp == it->second.getMotDePasse()) {
            identifie = true;
        } else {
            identifie = false;
        }
    }

    return identifie;
}

void GestionnaireUtilisateur::ajouterUtilisateur(Utilisateur& user){
    utilisateurs[user.getIdentifiant()] = user;
}

/*std::vector<Utilisateur> GestionnaireUtilisateur::getUtilisateurs(){
    return utilisateurs;
}*/
