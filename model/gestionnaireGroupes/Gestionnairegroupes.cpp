#include "Gestionnairegroupes.h"
#include "model/groupe/Groupe.h"
#include <iostream>
#include "model/sharecount/ShareCount.h"

gestionnaireGroupes::gestionnaireGroupes()
{

}

void gestionnaireGroupes::ajouterGroupe(Groupe& groupe){
    groupes[groupe.getIdentifiant()] = groupe;
}

Groupe gestionnaireGroupes::getGroupe(const QString& id) const{
    std::map<QString, Groupe>::const_iterator it = groupes.find(id);

    return it->second;
}

