#include "Groupe.h"

/**
 * @brief Groupe constructeur
 * @param id nom / identifiant du groupe
 * @param date date de création du group
 * @param descr petite déscription du groupe
 */
Groupe::Groupe(const QString& id, const QString& descr):
    identifiant(id),
    description(descr),
    participants(new GestionnaireUtilisateur),
    depenses(new GestionnaireDepenses)
{
    QDateTime d;
    dateCreation = d.currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
}

Groupe::Groupe(): participants(new GestionnaireUtilisateur),
    depenses(new GestionnaireDepenses) {
}

/**
 * @brief getIdentifiant retourne l'identifiant / nom du groupe
 * @return
 */
QString Groupe::getIdentifiant() const {
    return identifiant;
}

void Groupe::setIdentifiant(const QString &id){
    identifiant = id;
}

/**
 * @brief getDescription retourne la descrption du groupe, qui peut etre
 * ajouté ou pas par le créateur
 * @return
 */
QString Groupe::getDescription() const {
    return description;
}

/**
 * @brief setDescription permet de donné une déscription pour le groupe
 * @param descr
 */
void Groupe::setDescription(const QString &descr) {
    description = descr;
}

/**
 * @brief getDateCreation retourne la date de création du groupe
 * @return
 */
QString Groupe::getDateCreation() const {
    return dateCreation;
}

/**
 * @brief ajouterUnpParticipant ajouter un participant au groupe
 * @param user
 */
void Groupe::ajouterUnpParticipant(Utilisateur user) {
    participants->ajouterUtilisateur(user);
}

/**
 * @brief getParticipants retourne les participants
 * @return
 */
GestionnaireUtilisateur Groupe::getParticipants() const {
    return *participants;
}


/**
 * @brief getDepenses retourne le gestionnaire de dépense
 * @return
 */
GestionnaireDepenses Groupe::getDepenses() const{
    return *depenses;
}

/**
 * @brief setDate permet de fixer la date de création groupe
 * @param date
 */
void Groupe::setDate(const QString& date) {
    dateCreation = date;
}

/**
 * @brief ajouterUneDepense permet d'ajouter une dépense
 * @param dep
 */
void Groupe::ajouterUneDepense(Depense& dep){
    depenses->ajouterUneDepense(dep);
}

/**
 * @brief nbDepenses retourne le nombre de dépense;
 * @return
 */
int Groupe::nbDepenses() const {
    return depenses->nbDepense();
}

/**
 * @brief depensesToString retourne la liste des dépenses en string
 * @return
 */
QStringList Groupe::depensesToString() {
    QStringList qsl;

    for (int i = 0; i < nbDepenses(); i++) {
        Depense dep = depenses->getDepense(i);
        QString valeurBase = QString::number(dep.getVealeurBase());
        QString valeurRembourse = QString::number(dep.getValeurRemboursee());
        qsl << dep.getNom()+" : "+valeurBase+" € avancé par "+dep.getCreateur()+"\n"+valeurRembourse+" € Remboursé\nLe "+dep.getdate();
    }

    return qsl;
}


/**
 * @brief clearDepenses supprime toutes les dépenses de la collection
 */
void Groupe::clearDepenses() {
    depenses->clearDepenses();
}


/**
 * @brief getDettes retourne les dettes de chaque utilisateur du groupe
 * @return
 */
std::map<QString, double> Groupe::getDettes(){
    return dettes;
}


/**
 * @brief setDettes On calcule les dettes de tous les participants du groupe, en fonction de leur dépense
 */
void Groupe::setDettes(){
    for(std::map<QString, Utilisateur>::iterator it = participants->begin(); it != participants->end(); ++it){ //on initialise toutes les dettes à 0 €
        dettes[it->second.getIdentifiant()] = 0;
    }
    for(int i = 0; i<nbDepenses(); i++){ //Pour chaque dépense on vérifie qui l'a créé pour ajuster les calculs (répartir les dépenses sur l'ensemble des membres du groupes)
        for(std::map<QString, Utilisateur>::iterator it = participants->begin(); it != participants->end(); ++it){
            qDebug() << it->second.getIdentifiant();
            if(depenses->getDepense(i).getCreateur() == it->first){
                qDebug() << it->first;
                dettes[it->second.getIdentifiant()] += depenses->getDepense(i).getVealeurBase()-depenses->getDepense(i).getVealeurBase()/participants->getNombreUtilisateur();
            }else{
                dettes[it->second.getIdentifiant()] -= (depenses->getDepense(i).getVealeurBase()/participants->getNombreUtilisateur());
            }
        }
    }
}

/**
 * @brief Destructeur
 */
Groupe::~Groupe() {
    //delete participants;
}
