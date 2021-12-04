#ifndef GESTIONNAIREGROUPES_H
#define GESTIONNAIREGROUPES_H

#include <QString>
#include <vector>

#include "model/groupe/Groupe.h"

class Groupe;

class GestionnaireGroupes
{
public:
    explicit GestionnaireGroupes();

    void ajouterGroupe(Groupe& groupe);

    Groupe getGroupe(const int& i) const;

    int size();

private:
    std::vector<Groupe> groupes;
};

#endif // GESTIONNAIREGROUPES_H
