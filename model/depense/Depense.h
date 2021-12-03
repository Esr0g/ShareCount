#ifndef DEPENSE_H
#define DEPENSE_H

#include <QObject>
#include "model/groupe/Groupe.h"
#include "model/utilisateur/Utilisateur.h"

/**
 * @brief The Depense class définie une dépense, qui sera la fonction princiaple
 * des GroupesGestionsBudget
 */
class Depense : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Depense constructeur par défaut
     */
    explicit Depense();

    /**
     * @brief Depense constructeur
     * @param num numéro de la dépense dans un groupe
     * @param user utilisateur qui a crée lé dépense
     * @param valB valeur initiale de la dépense
     * @param valRem valeur remboursée (au début 0)
     * @param estRem donne le statut de la dépense
     */
    explicit Depense(const int& num, Utilisateur& user, int& valB, int valRem = 0, bool estRem = false);

    /**
     * @brief getNumDepense retourne le numéro de dépense
     * @return
     */
    int getNumDepense() const;

    /**
     * @brief getCreateur retourne le créateur de la dépense
     * @return
     */
    Utilisateur getCreateur() const;

    /**
     * @brief getVealeurBase retourne la valeur initiale
     * @return
     */
    int getVealeurBase() const;

    /**
     * @brief getValeurRemboursee retourne la somme déjà remboursée
     * @return
     */
    int getValeurRemboursee() const;

    /**
     * @brief estRemboursee retourne vrai si la dépense est complétement remboursée,
     * faux sinon
     * @return
     */
    bool estRemboursee() const;

    /**
     * @brief addValeurRemboursee permet de rembourser une partie de la dépense
     * @param val
     */
    void addValeurRemboursee(const int& val);

    /**
     * @brief setEstRemboursee positionne le boolean estRemboursee sur b
     * @param b
     */
    void setEstRemboursee(const bool& b);


private:
    int numDepense;
    Utilisateur createur;
    int valeurBase;
    int valeurRemboursee;
    bool estRemboursee;


signals:

};

#endif // DEPENSE_H
