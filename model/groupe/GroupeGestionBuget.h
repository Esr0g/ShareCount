#ifndef GROUPEGESTIONBUGET_H
#define GROUPEGESTIONBUGET_H

#include "model/groupe/Groupe.h"
#include "model/gestionnairedepenses/GestionnaireDepenses.h"

class GroupeGestionBuget : public Groupe
{

public:
    GroupeGestionBuget(const QString& id, const QString& descr = "");
    ~GroupeGestionBuget();

private:
    GestionnaireDepenses depenses;
};

#endif // GROUPEGESTIONBUGET_H
