#include "Depense.h"

Depense::Depense(): numDepense(0),
    valeurBase(0), valeurRemboursee(0),
    estRembourseeB(false) {
}

Depense::Depense(const int& num, QString& user, double &valB, QString& nomDep, QString& dateDep, double valRem, bool estRem):
    numDepense(num), createur(user), valeurBase(valB),
    valeurRemboursee(valRem), estRembourseeB(estRem),
    nom(nomDep), date(dateDep)
{
}

int Depense::getNumDepense() const {
    return numDepense;
}

QString Depense::getCreateur() const {
    return createur;
}

double Depense::getVealeurBase() const {
    return valeurBase;
}

double Depense::getValeurRemboursee() const {
    return valeurRemboursee;
}

bool Depense::isRemboursee() const {
    return estRembourseeB;
}

void Depense::addValeurRemboursee(const int& val) {
    valeurRemboursee += val;
}

void Depense::setEstRemboursee(const bool& b) {
    estRembourseeB = b;
}

QString Depense::getNom() const {
    return nom;
}

QString Depense::getdate() const {
    return date;
}
