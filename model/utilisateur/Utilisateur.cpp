#include "Utilisateur.h"

/**
 * @brief Utilisateur constructeur
 */
Utilisateur::Utilisateur(): mesGroupes(new GestionnaireGroupes){
}


/**
 * @brief setIdentifiant modifie l'identifiant
 * @param id
 */
void Utilisateur::setIdentifiant(const QString& id) {
    identifiant = id;
}

/**
 * @brief setMotDePasse modifier le mdp
 * @param mdp
 */
void Utilisateur::setMotDePasse(const QString& mdp) {
    motDePasse = mdp;
}

/**
 * @brief setMail modifier le mail
 * @param m
 */
void Utilisateur::setMail(const QString& m) {
    mail = m;
}

/**
 * @brief getIdentifiant
 * @return l'identifiant de l'utilisateur
 */
QString Utilisateur::getIdentifiant() const{
    return identifiant;
}

/**
 * @brief getMotDePasse
 * @return  le mot de passe de l'utilisateur
 */
QString Utilisateur::getMotDePasse() const {
    return motDePasse;
}

/**
 * @brief getMail
 * @return le mail de l'utilisateur
 */
QString Utilisateur::getMail() const {
    return mail;
}

/**
 * @brief ajouterAMesGroupes permet d'ajouter un groupe
 * @param grp
 */
void Utilisateur::ajouterAMesGroupes(Groupe& grp) {
    mesGroupes->ajouterGroupe(grp);
}

/**
 * @brief getMesGroupesToString retourne la liste des groupe sous la
 * forme d'une liste de QString
 * @return
 */
QStringList Utilisateur::getMesGroupesToString() const {
    QStringList qsl;
    for (int i = 0; i < mesGroupes->size(); i++) {
        qsl << mesGroupes->getGroupe(i).getIdentifiant();
    }

    return qsl;
}

/**
 * @brief getMesGroupes retourne une référence sur mesGroupes
 * @return
 */
GestionnaireGroupes& Utilisateur::getMesGroupes() const {
    return *mesGroupes;
}

/**
 * @brief findGroupe retourne vrai si grp fait partie des groupes
 * @param grp
 * @return
 */
bool Utilisateur::findGroupe(const QString& grp) const {
    return mesGroupes->findGroupe(grp);
}

/**
 * @brief getGroupe retourne un groupe
 * @param idGroupe
 * @return
 */
Groupe& Utilisateur::getGroupe(const QString& idGroupe) {
    return mesGroupes->getGroupe(idGroupe);
}

Utilisateur::~Utilisateur() {
    //delete mesGroupes;
}
