#include "Groupe.h"


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

QString Groupe::getIdentifiant() const {
    return identifiant;
}

void Groupe::setIdentifiant(const QString &id){
    identifiant = id;
}

QString Groupe::getDescription() const {
    return description;
}

void Groupe::setDescription(const QString &descr) {
    description = descr;
}

QString Groupe::getDateCreation() const {
    return dateCreation;
}

void Groupe::ajouterUnpParticipant(Utilisateur& user) {
    participants->ajouterUtilisateur(user);
}

GestionnaireUtilisateur Groupe::getParticipants() const {
    return *participants;
}

void Groupe::setDate(const QString& date) {
    dateCreation = date;
}

void Groupe::ajouterUneDepense(Depense& dep){
    depenses->ajouterUneDepense(dep);
}

int Groupe::nbDepenses() const {
    return depenses->nbDepense();
}

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

void Groupe::clearDepenses() {
    depenses->clearDepenses();
}

Groupe::~Groupe() {
    //delete participants;
}
