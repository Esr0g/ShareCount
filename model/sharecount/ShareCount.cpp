#include "ShareCount.h"
#include <iostream>

/**
 * @brief ShareCount constructeur par défaut
 * @param parent
 */
ShareCount::ShareCount(QObject *parent): QObject(parent){
    shareCountBDD.createDataBase();

    //On va ajouter au GestionnaireUtilisateur, tous les utilisateurs présent dans la base de donnée
    shareCountBDD.initialiserListeUtilisateur(utilisateurs);
}

/**
 * @brief initialiserListeUtilisateur permet d'initialiser les utilisateurs
 */
void ShareCount::initialiserListeUtilisateur() {
    shareCountBDD.initialiserListeUtilisateur(utilisateurs);
}

/**
 * @brief identifierUtilisateur retourne vrai si l'utilisateur existe
 * @param identifiant
 * @param motDePasse
 * @return
 */
bool ShareCount::identifierUtilisateur(const QString &identifiant, const QString &motDePasse) const {
    return utilisateurs.identifierUtilisateur(identifiant, motDePasse);
}

/**
 * @brief setUtilisateurActif Permet d'affecter au système l'utilisateur actif
 * @param user
 */
void ShareCount::setUtilisateurActif(Utilisateur& user) {
    utilisateurActif = user;
    shareCountBDD.initialiserGroupeUtilisateur(user.getMesGroupes(), user.getIdentifiant());
}

/**
 * @brief getUtilisateur retourne un utilisateur avec l'id spécifique
 * @param id
 * @return
 */
Utilisateur ShareCount::getUtilisateur(const QString& id) const {
    return utilisateurs.getUtilisateur(id);
}

/**
 * @brief findUtilisateur retourne vrai si l'utilisateur existe faux sinon
 * @param id
 * @return
 */
bool ShareCount::findUtilisateur(const QString& id) const {
    return utilisateurs.findUtilisateur(id);
}

/**
 * @brief creerUtilisateur permet d'ajouter un utilisateur à la base de donnée
 * @param user
 */
void ShareCount::creerUtilisateur(Utilisateur& user) {
    shareCountBDD.insererUtilisateur(user);
    utilisateurs.ajouterUtilisateur(user);
}

/**
 * @brief getUtilisateurActif retourne la référence de l'utiisateur actif
 * @return
 */
Utilisateur& ShareCount::getUtilisateurActif() {
    return utilisateurActif;
}

/**
 * @brief inserGroupe permet d'inserer un groupe dans la base de donnée
 * @param grp
 * @param user
 */
void ShareCount::inserGroupe(const Groupe& grp, const Utilisateur& user) {
    shareCountBDD.insererunGroupe(grp, user);
}

/**
 * @brief findGroupe retourne vrai si grp fait partie des groupes d'utilisateurActif
 * @param grp
 * @return
 */
bool ShareCount::findGroupe(const QString& grp) const {
    return utilisateurActif.findGroupe(grp);
}

/**
 * @brief appartientAuGroupe retourne vrai si user appartient à grp
 * @param user
 * @param grp
 * @return
 */
bool ShareCount::appartientAuGroupe(const QString& user, const QString& grp) {
    return shareCountBDD.appartientAuGroupe(user, grp);
}

/**
 * @brief ajouterParticipantAuGroupe ajoute le participant "user" au groupe "grp";
 * @param user
 * @param grp
 */
void ShareCount::ajouterParticipantAuGroupe(const QString& user, const QString& grp) {
    shareCountBDD.ajouterParticipantAuGroupe(user, grp);
}

/**
 * @brief initialiserParticipants permet d'initialiser les participants au groupe grp
 * pour l'afficher
 * @param grp
 */
QStringList ShareCount::initialiserParticipants(const QString& grp) {
    return shareCountBDD.initialiserParticipants(grp);
}

/**
 * @brief ajouterUneDepense permet d'ajouter une dépense au groupe actif
 * @param dep
 */
void ShareCount::ajouterUneDepense(Depense& dep) {
    groupeActif.ajouterUneDepense(dep);
    shareCountBDD.insererUneDepense(dep, groupeActif);
}

/**
 * @brief getGroupeActif retourne le groupe actif
 * @return
 */
Groupe& ShareCount::getGroupeActif() {
    return groupeActif;
}

/**
 * @brief setGroupeActif positionne le groupe actif
 * @param grp
 */
void ShareCount::setGroupeActif(Groupe& grp) {
    groupeActif = grp;
    shareCountBDD.initialiserDepensesGroupe(groupeActif);
}


/**
 * @brief getNombreUtilisateurs retourne le nombre d'utilisateur
 * @return
 */
int ShareCount::getNombreUtilisateurs() const {
    return utilisateurs.getNombreUtilisateur();
}

ShareCount::~ShareCount() {
}
