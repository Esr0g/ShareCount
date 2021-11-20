#ifndef PAGEACCUEIL_H
#define PAGEACCUEIL_H

#include <QWidget>
#include <screen/fenetreprincipale/FenetrePrincipale.h>
#include <model/sharecount/ShareCount.h>

namespace Ui {
class PageAccueil;
}

/**
 * @brief The PageAccueil class
 * C'est la classe qui permet d'affichier la page ou l'on peut soit se connecter
 * soit choisir de créer un compte
 */
class PageAccueil : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief PageAccueil
     * @param parent
     */
    explicit PageAccueil(QWidget *parent = nullptr);

    /**
     * @brief PageAccueil
     * @param parent
     * @param fp fenêtre principale de l'application
     * @param sc sharcount (Sorte de système de l'application)
     */
    explicit PageAccueil(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc);

    ~PageAccueil();

private:
    /**
     * @brief setConnect
     * Permet de connecter les signaux des éléments afficher avec
     * leur slots correspondant
     */
    void setConnect();

public slots:
    /**
     * @brief creerCompte lorsque l'utilisateur appuie sur le bouton créer un compte
     * celui-ci créer une nouvelle PageCreationCompte
     */
    void creerCompte();

    /**
     * @brief connexion envoie les informations de connexion a ShareCount
     * et accepte la connexion ou pas en fonction de la réponse de ShareCount
     */
    void connexion();

private:
    Ui::PageAccueil *ui;
    FenetrePrincipale *pwindow;
    ShareCount* shareCount;
};

#endif // PAGEACCUEIL_H
