#include "Sharecount.h"
#include <string>
#include "model/utilisateur/Utilisateur.h"
#include "model/gestionnaireutilisateurs/Gestionnaireutilisateurs.h"

using namespace std;


ShareCount::ShareCount()
{
    utilisateurs = gestionnaireUtilisateurs();
}

Utilisateur ShareCount::getUtilisateur(string identifiantUtilisateur){
    
}

gestionnaireUtilisateurs ShareCount::getGestionnaireUtilisateurs(){
    return utilisateurs;
}

void ShareCount::setGestionnaireUtilisateurs(gestionnaireUtilisateurs gu){
    utilisateurs = gu;
}
