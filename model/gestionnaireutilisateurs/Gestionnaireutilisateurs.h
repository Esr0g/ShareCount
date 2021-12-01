#ifndef GESTIONNAIREUTILISATEURS_H
#define GESTIONNAIREUTILISATEURS_H
#include <map>
#include <iterator>
#include "model/utilisateur/Utilisateur.h"

///
/// \brief The GestionnaireUtilisateur class C'est un classe qui permet de gérer la collection d'utilisateur
///
class GestionnaireUtilisateur
{

public:
    /**
     * @brief class GestionnaireUtilisateur constructeur
     */
    explicit GestionnaireUtilisateur();

    /**
     * @brief ajouterUtilisateur permet d'ajouter un utilisateur
     * @param user
     */
    void ajouterUtilisateur(Utilisateur& user);

    /**
     * @brief identifierUtilisateur permet d'identifer un utilisateur à l'aide de son mot de
     * passe et de sont identifiant
     * @param identifiant
     * @param mdp
     * @return
     */
    bool identifierUtilisateur(const QString& id, const QString& mdp) const;

    ///
    /// \brief getUtilisateur retorune l'utilisateur avec l'identifiant "id"
    /// \param id
    /// \return
    ///
    Utilisateur getUtilisateur(const QString& id) const;

    /**
     * @brief findUtilisateur retourne vrai si l'utilisateur st trouvé, faux sinon
     * @param id
     * @return
     */
    bool findUtilisateur(const QString& id) const;

    int getNombreUtilisateur() const;

private:
    std::map<QString, Utilisateur> utilisateurs;
};

#endif // GESTIONNAIREUTILISATEURS_H
