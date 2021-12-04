#ifndef GROUPE_H
#define GROUPE_H

#include <QDateTime>
#include <QString>

#include "model/gestionnaireutilisateurs/Gestionnaireutilisateur.h"

class GestionnaireUtilisateur;
class Utilisateur;

/**
 * @brief classe abstraite de base pour GestionDeBudget et Cagnotte
 */
class Groupe
{
public:
    Groupe();
    /**
     * @brief Groupe constructeur
     * @param id nom / identifiant du groupe
     * @param date date de création du group
     * @param descr petite déscription du groupe
     */
    Groupe(const QString& id, const QString& descr = "");

    void setIdentifiant(const QString& id);

    /**
     * @brief getIdentifiant retourne l'identifiant / nom du groupe
     * @return
     */
    QString getIdentifiant() const;

    /**
     * @brief getDescription retourne la descrption du groupe, qui peut etre
     * ajouté ou pas par le créateur
     * @return
     */
    QString getDescription() const;

    /**
     * @brief setDescription permet de donné une déscription pour le groupe
     * @param descr
     */
    void setDescription(const QString &descr);

    /**
     * @brief getDateCreation retourne la date de création du groupe
     * @return
     */
    QString getDateCreation() const;

    /**
     * @brief estUnGroupeGestionDeBuget retourne vrai si this est de type GroupeGestionBudget
     * faux sinon
     * @return
     */
    bool estUnGroupeGestionDeBuget() const;

    /**
     * @brief ajouterUnpParticipant ajouter un participant au groupe
     * @param user
     */
    void ajouterUnpParticipant(Utilisateur& user);

    GestionnaireUtilisateur getParticipants() const;

    ~Groupe();

private:
    QString identifiant;
    QString dateCreation;
    QString description;
    GestionnaireUtilisateur* participants;
};

#endif // GROUPE_H
