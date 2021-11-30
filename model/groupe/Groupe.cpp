#include "Groupe.h"

Groupe::Groupe()
{

}
QString Groupe::getIdentifiant() const {
    return identifiant;
}

void Groupe::setIdentifiant(const QString &id){
    identifiant = id;
}

