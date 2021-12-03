#include "GestionnaireDepenses.h"

GestionnaireDepenses::GestionnaireDepenses(QObject *parent) : QObject(parent)
{

}

void GestionnaireDepenses::ajouterUneDepense(Depense& dep) {
    depenses.push_back(dep);
}

Depense GestionnaireDepenses::getDepense(const int& i) const {
    return depenses[i];
}

int GestionnaireDepenses::nbDepense() const {
    return depenses.size();
}
