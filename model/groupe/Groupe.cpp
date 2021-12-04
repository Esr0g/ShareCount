#include "Groupe.h"


Groupe::Groupe(const QString& id, const QString& descr):
    identifiant(id),
    description(descr),
    participants(new GestionnaireUtilisateur())
{
    QDateTime d;
    dateCreation = d.currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
}

Groupe::Groupe(): participants(new GestionnaireUtilisateur()) {
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

Groupe::~Groupe() {
    //delete participants;
}
