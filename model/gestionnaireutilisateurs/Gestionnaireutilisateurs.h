#ifndef GESTIONNAIREUTILISATEURS_H
#define GESTIONNAIREUTILISATEURS_H
#include <list>
#include "model/utilisateur/Utilisateur.h"


class gestionnaireUtilisateurs
{

public:
    /**
     * @brief gestionnaireUtilisateurs constructeur
     */
    gestionnaireUtilisateurs();
    void ajouterUtilisateur(Utilisateur& user);
    std::list<Utilisateur> getUtilisateurs() const;
    void setListe(std::list<Utilisateur> liste);

private:
    std::list<Utilisateur> utilisateurs;
};

#endif // GESTIONNAIREUTILISATEURS_H
