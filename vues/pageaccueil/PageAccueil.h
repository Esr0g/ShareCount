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

    explicit PageAccueil(QWidget *parent = nullptr);

    explicit PageAccueil(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc);

    ~PageAccueil();

private:
    void setConnect();

public slots:
    void creerCompte();

    void connexion();

private:
    Ui::PageAccueil *ui;
    FenetrePrincipale *pwindow;
    ShareCount* shareCount;
};

#endif // PAGEACCUEIL_H
