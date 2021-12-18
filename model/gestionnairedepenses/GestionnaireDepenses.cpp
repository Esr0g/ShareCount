#include "GestionnaireDepenses.h"

/**
 * @brief GestionnaireDepenses constructeur par défaut
 * @param parent
 */
GestionnaireDepenses::GestionnaireDepenses()
{

}

/**
 * @brief ajouterUneDepense permet d'ajouter une dépense
 * @param dep
 */
void GestionnaireDepenses::ajouterUneDepense(Depense& dep) {
    depenses.push_back(dep);
}

/**
 * @brief getDepense permet de récupérer une dépense
 * @param i
 * @return
 */
Depense GestionnaireDepenses::getDepense(const int& i) const {
    return depenses[i];
}

/**
 * @brief nbDepense retourne le nombre de dépenses
 * @return
 */
Depense GestionnaireDepenses::getDepense(const std::string& str) {
    for(Depense depense : depenses){
        if(depense.getNom().toStdString() == str){
            return depense;
        }
    }
}

/**
 * @brief begin retourne l'itérateur begin de la collection
 * @return
 */
int GestionnaireDepenses::nbDepense() const {
    return depenses.size();
}

/**
 * @brief begin retourne l'itérateur begin de la collection
 * @return
 */
std::vector<Depense>::iterator GestionnaireDepenses::begin() {
    return depenses.begin();
}


/**
 * @brief end retorune l'itérateur end de la collection
 * @return
 */
std::vector<Depense>::iterator GestionnaireDepenses::end() {
    return depenses.end();
}


/**
 * @brief clearDepenses supprimme toutes les dépenses de la collection
 */
void GestionnaireDepenses::clearDepenses() {
    depenses.clear();
}

