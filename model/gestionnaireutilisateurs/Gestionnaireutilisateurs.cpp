#include "Gestionnaireutilisateurs.h"
#include "model/utilisateur/Utilisateur.h"
#include "model/sharecount/ShareCount.h"
#include <iostream>

GestionnaireUtilisateur::GestionnaireUtilisateur()
{
}

bool GestionnaireUtilisateur::identifierUtilisateur(const QString& id, const QString& mdp) const{

    return true;
}

void GestionnaireUtilisateur::ajouterUtilisateur(Utilisateur& user){
    utilisateurs[user.getIdentifiant()] = user;
}

/*std::vector<Utilisateur> GestionnaireUtilisateur::getUtilisateurs(){
    return utilisateurs;
}*/
