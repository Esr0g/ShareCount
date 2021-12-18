#include "GestionnaireDepenses.h"

GestionnaireDepenses::GestionnaireDepenses()
{

}

void GestionnaireDepenses::ajouterUneDepense(Depense& dep) {
    depenses.push_back(dep);
}

Depense GestionnaireDepenses::getDepense(const int& i) const {
    return depenses[i];
}

Depense GestionnaireDepenses::getDepense(const std::string& str) {
    for(Depense depense : depenses){
        if(depense.getNom().toStdString() == str){
            return depense;
        }
    }
}

int GestionnaireDepenses::nbDepense() const {
    return depenses.size();
}

std::vector<Depense>::iterator GestionnaireDepenses::begin() {
    return depenses.begin();
}

std::vector<Depense>::iterator GestionnaireDepenses::end() {
    return depenses.end();
}

void GestionnaireDepenses::clearDepenses() {
    depenses.clear();
}

