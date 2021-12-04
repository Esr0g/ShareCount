#include "Depense.h"

Depense::Depense(): numDepense(0), createur(nullptr),
    valeurBase(0), valeurRemboursee(0),
    estRemboursee(false) {
}

Depense::Depense(const int& num, Utilisateur& user, int& valB, int valRem = 0, bool estRem = false):
    numDepense(num), createur(user), valeurBase(valB),
    valRem(valRem), estRemboursee(estRem) {
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

bool Depense::isRemboursee() const {
    return estRemboursee;
}

void Depense::addValeurRemboursee(const int& val) {
    valeurRemboursee += val;
}

void Depense::setEstRemboursee(const bool& b) {
    estRemboursee = b;
}
