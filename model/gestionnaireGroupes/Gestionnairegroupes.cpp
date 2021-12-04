#include "Gestionnairegroupes.h"

GestionnaireGroupes::GestionnaireGroupes()
{

}

void GestionnaireGroupes::ajouterGroupe(Groupe& groupe){
    groupes.push_back(groupe);
}

Groupe GestionnaireGroupes::getGroupe(const int& i) const{
    return groupes[i];
}

int GestionnaireGroupes::size() {
    return groupes.size();
}
