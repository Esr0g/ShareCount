#include "Depense.h"

Depense::Depense(): numDepense(0),
    valeurBase(0), valeurRemboursee(0),
    estRembourseeB(false) {
}

Depense::Depense(const int& num, Utilisateur& user, int& valB, int valRem, bool estRem):
    numDepense(num), createur(user), valeurBase(valB),
    valeurRemboursee(valRem), estRembourseeB(estRem) {
}

int Depense::getNumDepense() const {
    return numDepense;
}

Utilisateur Depense::getCreateur() const {
    return createur;
}

int Depense::getVealeurBase() const {
    return valeurBase;
}

int Depense::getValeurRemboursee() const {
    return valeurRemboursee;
}

bool Depense::estRemboursee() const {
    return estRembourseeB;
}

void Depense::addValeurRemboursee(const int& val) {
    valeurRemboursee += val;
}

void Depense::setEstRemboursee(const bool& b) {
    estRembourseeB = b;
}
