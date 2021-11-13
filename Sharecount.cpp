#include "Sharecount.h"
#include <string>
#include "Utilisateur.h"
#include "Gestionnaireutilisateurs.h"

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
