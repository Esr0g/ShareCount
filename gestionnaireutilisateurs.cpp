#include "gestionnaireutilisateurs.h"
#include "utilisateur.h"
#include "sharecount.h"
#include <list>

gestionnaireUtilisateurs::gestionnaireUtilisateurs()
{

}
gestionnaireUtilisateurs::ajouterUtilisateur(Utilisateur user){
    int i=0;
    while(users[i]==NULL){
        i++;
    }
    users[i] = user;
}


