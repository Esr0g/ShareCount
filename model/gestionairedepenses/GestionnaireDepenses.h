#ifndef GESTIONNAIREDEPENSES_H
#define GESTIONNAIREDEPENSES_H

#include <QObject>
#include <model/depense/Depense.h>
#include <vector>

/**
 * @brief The GestionnaireDepenses class permet de gérer une collection de dépenses:
 * Un groupe peut avoir plusieurs dépenses associées de même pour les utilisateurs
 */
class GestionnaireDepenses : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief GestionnaireDepenses constructeur par défaut
     * @param parent
     */
    explicit GestionnaireDepenses(QObject *parent = nullptr);

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

private:
    std::vector<Depense> depenses;

signals:


};

#endif // GESTIONNAIREDEPENSES_H
