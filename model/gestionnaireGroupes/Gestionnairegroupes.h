#ifndef GESTIONNAIREGROUPES_H
#define GESTIONNAIREGROUPES_H

#include <QString>
#include <vector>

#include "model/groupe/Groupe.h"

class Groupe;

/**
 * @brief The GestionnaireGroupes class qui gère une collection de groupes
 */
class GestionnaireGroupes
{
public:
    explicit GestionnaireGroupes();

    void ajouterGroupe(Groupe &groupe);

    Groupe& getGroupe(const int& i);

    int size() const;

    bool findGroupe(const QString& grp) const;

    Groupe& getGroupe(const QString& idGroupe);

    void clear();

private:
    std::vector<Groupe> groupes;
};

#endif // GESTIONNAIREGROUPES_H
