#include "Gestionnairegroupes.h"
#include <algorithm>

GestionnaireGroupes::GestionnaireGroupes()
{

}

void GestionnaireGroupes::ajouterGroupe(Groupe& groupe){
    groupes.push_back(groupe);
}

Groupe& GestionnaireGroupes::getGroupe(const int& i) {
    return groupes[i];
}

int GestionnaireGroupes::size() const {
    return groupes.size();
}

bool GestionnaireGroupes::findGroupe(const QString& grp) const {
    bool trouve = false;

    for (int i = 0; i < size() && !trouve; i++) {
        if (groupes[i].getIdentifiant() == grp) {
            trouve = true;
        }
    }

    return trouve;
}

Groupe& GestionnaireGroupes::getGroupe(const QString& idGroupe) {
    for (int i = 0; i < size(); i++) {
        if (groupes[i].getIdentifiant() == idGroupe) {
            return groupes[i];
        }
    }
}
