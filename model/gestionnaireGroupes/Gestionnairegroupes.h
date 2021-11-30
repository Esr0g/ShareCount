#ifndef GESTIONNAIREGROUPES_H
#define GESTIONNAIREGROUPES_H
#include <QString>
#include "model/groupe/Groupe.h"
#include <iostream>
#include <map>
#include <iterator>

class gestionnaireGroupes
{
public:
    //gestionnaireGroupes();

    explicit gestionnaireGroupes();

    void ajouterGroupe(Groupe& groupe);

    Groupe getGroupe(const QString& id) const;

private:
    std::map<QString, Groupe> groupes;
};

#endif // GESTIONNAIREGROUPES_H
