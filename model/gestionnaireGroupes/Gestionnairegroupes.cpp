#include "Gestionnairegroupes.h"
#include <algorithm>

/**
 * @brief GestionnaireGroupes constructeur
 */
GestionnaireGroupes::GestionnaireGroupes()
{

}

/**
 * @brief ajouterGroupe permet d'ajouter un groupe a la collection
 * @param groupe
 */
void GestionnaireGroupes::ajouterGroupe(Groupe& groupe){
    groupes.push_back(groupe);
}

/**
 * @brief getGroupe permet de retourner un groupe à la position i
 * @param i
 * @return
 */
Groupe& GestionnaireGroupes::getGroupe(const int& i) {
    return groupes[i];
}

/**
 * @brief size retourne la taille de la collection
 * @return
 */
int GestionnaireGroupes::size() const {
    return groupes.size();
}

/**
 * @brief findGroupe renvoie vrai si grp est présent dans la collection, faux sinon
 * @param grp
 * @return
 */
bool GestionnaireGroupes::findGroupe(const QString& grp) const {
    bool trouve = false;

    for (int i = 0; i < size() && !trouve; i++) {
        if (groupes[i].getIdentifiant() == grp) {
            trouve = true;
        }
    }

    return trouve;
}

/**
 * @brief getGroupe retourne un groupe
 * @param idGroupe
 * @return
 */
Groupe& GestionnaireGroupes::getGroupe(const QString& idGroupe) {
    for (int i = 0; i < size(); i++) {
        if (groupes[i].getIdentifiant() == idGroupe) {
            return groupes[i];
        }
    }
}

/**
 * @brief clear permet de supprimer tous les groupes
 */
void GestionnaireGroupes::clear() {
    groupes.clear();
}
