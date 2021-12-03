#ifndef PAGECREATIONCOMPTE_H
#define PAGECREATIONCOMPTE_H

#include <QWidget>
#include "screen/fenetreprincipale/FenetrePrincipale.h"
#include "model/sharecount/ShareCount.h"
#include "QKeyEvent"

namespace Ui {
class PageCreationCompte;
}


/**
 * @brief The PageCreationCompte class page qui permet de créer son compte
 */
class PageCreationCompte : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief PageCreationCompte
     * @param parent
     */
    explicit PageCreationCompte(QWidget *parent = nullptr);

    /**
     * @brief PageCreationCompte
     * @param fp fenêtre principale de l'application
     * @param sc sharcount (Sorte de système de l'application)
     * @param sc
     */
    explicit PageCreationCompte(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc);
    ~PageCreationCompte();

private:
    /**
     * @brief setConnect
     * Permet de connecter les signaux des éléments afficher avec
     * leur slots correspondant
     */
    void setConnexion();

public slots:
    /**
     * @brief annuler Permet d'annuler la création de compte et de retrouner
     * sur la page d'accueil
     */
    void annuler();

    /**
     * @brief onPushButtonCreerCompte Envoie les informations entré par l'utilisateur
     * a ShareCount pour les traiter.
     */
    void onPushButtonCreerCompte();

private:

    Ui::PageCreationCompte *ui;
    FenetrePrincipale *pwindow;
    ShareCount* shareCount;
};

#endif // PAGECREATIONCOMPTE_H
