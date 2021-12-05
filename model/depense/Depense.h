#ifndef DEPENSE_H
#define DEPENSE_H


#include "model/utilisateur/Utilisateur.h"

class Utilisateur;

/**
 * @brief The Depense class définie une dépense, qui sera la fonction princiaple
 * des GroupesGestionsBudget
 */
class Depense
{

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
    explicit Depense(const int& num, QString& user, double& valB, QString& nomDep, QString& dateDep, double valRem = 0, bool estRem = false);

    /**
     * @brief getNumDepense retourne le numéro de dépense
     * @return
     */
    int getNumDepense() const;

    /**
     * @brief getCreateur retourne le créateur de la dépense
     * @return
     */
    QString getCreateur() const;

    /**
     * @brief getVealeurBase retourne la valeur initiale
     * @return
     */
    double getVealeurBase() const;

    /**
     * @brief getValeurRemboursee retourne la somme déjà remboursée
     * @return
     */
    double getValeurRemboursee() const;

    /**
     * @brief estRemboursee retourne vrai si la dépense est complétement remboursée,
     * faux sinon
     * @return
     */
    bool isRemboursee() const;

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

    /**
     * @brief getNom retourne le nom de la dépense
     * @return
     */
    QString getNom() const;

    /**
     * @brief getdate retourne la date de la dépense
     * @return
     */
    QString getdate() const;


private:
    int numDepense;
    QString nom;
    QString date;
    QString createur;
    int valeurBase;
    int valeurRemboursee;
    bool estRembourseeB;


};

#endif // DEPENSE_H
