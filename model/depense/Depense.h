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
    explicit Depense();

    explicit Depense(const int& num, QString& user, double& valB, QString& nomDep, QString& dateDep, double valRem = 0, bool estRem = false);

    int getNumDepense() const;

    QString getCreateur() const;

    double getVealeurBase() const;

    double getValeurRemboursee() const;

    bool isRemboursee() const;

    void addValeurRemboursee(const double& val);

    void setEstRemboursee(const bool& b);

    QString getNom() const;

    QString getdate() const;


private:
    int numDepense;
    QString nom;
    QString date;
    QString createur;
    int valeurBase;
    double valeurRemboursee;
    bool estRembourseeB;


};

#endif // DEPENSE_H
