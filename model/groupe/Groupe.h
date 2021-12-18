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

    Groupe(const QString& id, const QString& descr = "");

    void setIdentifiant(const QString& id);

    QString getIdentifiant() const;

    QString getDescription() const;

    void setDescription(const QString &descr);

    QString getDateCreation() const;

    void ajouterUnpParticipant(Utilisateur user);

    GestionnaireUtilisateur getParticipants() const;

    void setDate(const QString& date);

    void ajouterUneDepense(Depense& dep);


    int nbDepenses() const;

    QStringList depensesToString();

    void clearDepenses();

    void setDettes();

    std::map<QString, double> getDettes();

    GestionnaireDepenses getDepenses() const;

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
