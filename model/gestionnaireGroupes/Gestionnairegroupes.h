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
    /**
     * @brief GestionnaireGroupes constructeur
     */
    explicit GestionnaireGroupes();

    /**
     * @brief ajouterGroupe permet d'ajouter un groupe a la collection
     * @param groupe
     */
    void ajouterGroupe(Groupe &groupe);

    /**
     * @brief getGroupe permet de retourner un groupe à la position i
     * @param i
     * @return
     */
    Groupe& getGroupe(const int& i);

    /**
     * @brief size retourne la taille de la collection
     * @return
     */
    int size() const;

    /**
     * @brief findGroupe renvoie vrai si grp est présent dans la collection, faux sinon
     * @param grp
     * @return
     */
    bool findGroupe(const QString& grp) const;

    /**
     * @brief getGroupe retourne un groupe
     * @param idGroupe
     * @return
     */
    Groupe& getGroupe(const QString& idGroupe);

    void clear();

private:
    std::vector<Groupe> groupes;
};

#endif // GESTIONNAIREGROUPES_H
