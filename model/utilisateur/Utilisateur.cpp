#include "Utilisateur.h"

Utilisateur::Utilisateur(QString u_nom, QString u_identifiant, QString u_mail, QString u_motDePasse)
{
    nom=u_nom;
    identifiant=u_identifiant;
    motDePasse=u_motDePasse;

}

Utilisateur::Utilisateur(){

}

QString Utilisateur::getNom() const {
    return nom;
}
QString Utilisateur::getIdentifiant() const {
    return identifiant;
}
QString Utilisateur::getMotDePasse() const {
    return motDePasse;
}
QString Utilisateur::getMail() const {
    return mail;
}
