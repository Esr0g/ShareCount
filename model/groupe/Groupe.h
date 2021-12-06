#ifndef GROUPE_H
#define GROUPE_H

#include <QDateTime>
#include <QString>

#include "model/gestionnaireutilisateurs/Gestionnaireutilisateur.h"
#include "model/depense/Depense.h"
#include "model/gestionnairedepenses/GestionnaireDepenses.h"
#include <QDebug>
#include <QStandardItemModel>

class GestionnaireUtilisateur;
class Utilisateur;
class Depense;
class GestionnaireDepenses;

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
     * @brief ajouterUnpParticipant ajouter un participant au groupe
     * @param user
     */
    void ajouterUnpParticipant(Utilisateur user);

    /**
     * @brief getParticipants retourne les participants
     * @return
     */
    GestionnaireUtilisateur getParticipants() const;

    /**
     * @brief setDate permet de fixer la date de création groupe
     * @param date
     */
    void setDate(const QString& date);

    /**
     * @brief ajouterUneDepense permet d'ajouter une dépense
     * @param dep
     */
    void ajouterUneDepense(Depense& dep);

    /**
     * @brief nbDepenses retourne le nombre de dépense;
     * @return
     */
     int nbDepenses() const;

     /**
      * @brief depensesToString retourne la liste des dépenses en string
      * @return
      */
     QStringList depensesToString();

     void clearDepenses();

     void setDettes();

     std::map<QString, double> getDettes();

    ~Groupe();

private:
    QString identifiant;
    QString dateCreation;
    QString description;
    GestionnaireUtilisateur* participants;
    GestionnaireDepenses* depenses;
    std::map<QString, double> dettes; //Chaque utilisateur est associé à une dette (positive ou négative) pour le groupe concerné
};

#endif // GROUPE_H
