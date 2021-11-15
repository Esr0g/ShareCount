#include "Gestionnaireutilisateurs.h"
#include "model/utilisateur/Utilisateur.h"
#include "model/sharecount/Sharecount.h"
#include <list>

gestionnaireUtilisateurs::gestionnaireUtilisateurs()
{
    //utilisateurs = {Utilisateur("aa","aaa","aaa","bbbb")};
}
void gestionnaireUtilisateurs::ajouterUtilisateur(Utilisateur& user){
    utilisateurs.push_back(user);
}

/*Utilisateur gestionnaireUtilisateurs::getUtilisateur(int i){
    return utilisateurs[i];
}*/

/*std::vector<Utilisateur> gestionnaireUtilisateurs::getUtilisateurs(){
    return utilisateurs;
}*/
std::list<Utilisateur> gestionnaireUtilisateurs::getUtilisateurs() const {
    return utilisateurs;
}

void gestionnaireUtilisateurs::setListe(std::list<Utilisateur> liste){
    utilisateurs=liste;
}
