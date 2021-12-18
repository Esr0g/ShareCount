#include "Depense.h"

/**
 * @brief Depense constructeur par défaut
 */
Depense::Depense(): numDepense(0),
    valeurBase(0), valeurRemboursee(0),
    estRembourseeB(false) {
}

/**
 * @brief Depense constructeur
 * @param num numéro de la dépense dans un groupe
 * @param user utilisateur qui a crée lé dépense
 * @param valB valeur initiale de la dépense
 * @param valRem valeur remboursée (au début 0)
 * @param estRem donne le statut de la dépense
 */
Depense::Depense(const int& num, QString& user, double &valB, QString& nomDep, QString& dateDep, double valRem, bool estRem):
    numDepense(num), createur(user), valeurBase(valB),
    valeurRemboursee(valRem), estRembourseeB(estRem),
    nom(nomDep), date(dateDep)
{
}

/**
 * @brief getNumDepense retourne le numéro de dépense
 * @return
 */
int Depense::getNumDepense() const {
    return numDepense;
}

/**
 * @brief getCreateur retourne le créateur de la dépense
 * @return
 */
QString Depense::getCreateur() const {
    return createur;
}

/**
 * @brief getVealeurBase retourne la valeur initiale
 * @return
 */
double Depense::getVealeurBase() const {
    return valeurBase;
}

/**
 * @brief getValeurRemboursee retourne la somme déjà remboursée
 * @return
 */
double Depense::getValeurRemboursee() const {
    return valeurRemboursee;
}

/**
 * @brief estRemboursee retourne vrai si la dépense est complétement remboursée,
 * faux sinon
 * @return
 */
bool Depense::isRemboursee() const {
    return estRembourseeB;
}

/**
 * @brief addValeurRemboursee permet de rembourser une partie de la dépense
 * @param val
 */
void Depense::addValeurRemboursee(const double& val) {
    valeurRemboursee += val;
}

/**
 * @brief setEstRemboursee positionne le boolean estRemboursee sur b
 * @param b
 */
void Depense::setEstRemboursee(const bool& b) {
    estRembourseeB = b;
}

/**
 * @brief getNom retourne le nom de la dépense
 * @return
 */
QString Depense::getNom() const {
    return nom;
}

/**
 * @brief getdate retourne la date de la dépense
 * @return
 */
QString Depense::getdate() const {
    return date;
}
