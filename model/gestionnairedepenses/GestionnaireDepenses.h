#ifndef GESTIONNAIREDEPENSES_H
#define GESTIONNAIREDEPENSES_H

#include <vector>

#include "model/depense/Depense.h"

/**
 * @brief The GestionnaireDepenses class permet de gérer une collection de dépenses:
 * Un groupe peut avoir plusieurs dépenses associées de même pour les utilisateurs
 */
class GestionnaireDepenses
{
public:
    /**
     * @brief GestionnaireDepenses constructeur par défaut
     * @param parent
     */
    explicit GestionnaireDepenses();

    /**
     * @brief ajouterUneDepense permet d'ajouter une dépense
     * @param dep
     */
    void ajouterUneDepense(Depense& dep);

    /**
     * @brief getDepense permet de récupérer une dépense
     * @param i
     * @return
     */
    Depense getDepense(const int& i) const;

    /**
     * @brief nbDepense retourne le nombre de dépenses
     * @return
     */
    int nbDepense() const;

    /**
     * @brief begin retourne l'itérateur begin de la collection
     * @return
     */
    std::vector<Depense>::iterator begin();

    /**
     * @brief end retorune l'itérateur ed de la collection
     * @return
     */
    std::vector<Depense>::iterator end();

private:
    std::vector<Depense> depenses;

};

#endif // GESTIONNAIREDEPENSES_H
