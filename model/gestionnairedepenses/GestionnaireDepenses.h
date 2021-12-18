#ifndef GESTIONNAIREDEPENSES_H
#define GESTIONNAIREDEPENSES_H

#include <vector>
#include <string>

#include "model/depense/Depense.h"
class Depense;

/**
 * @brief The GestionnaireDepenses class permet de gérer une collection de dépenses:
 * Un groupe peut avoir plusieurs dépenses associées de même pour les utilisateurs
 */
class GestionnaireDepenses
{
public:
    explicit GestionnaireDepenses();

    void ajouterUneDepense(Depense& dep);

    Depense getDepense(const int& i) const;

    Depense& getDepense(const std::string& str);

    int nbDepense() const;

    std::vector<Depense>::iterator begin();

    std::vector<Depense>::iterator end();

    void clearDepenses();

private:
    std::vector<Depense> depenses;

};

#endif // GESTIONNAIREDEPENSES_H
