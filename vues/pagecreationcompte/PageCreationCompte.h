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
    explicit PageCreationCompte(QWidget *parent = nullptr);

    explicit PageCreationCompte(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc);
    ~PageCreationCompte();

private:
    void setConnexion();

public slots:
    void annuler();

    void onPushButtonCreerCompte();

private:

    Ui::PageCreationCompte *ui;
    FenetrePrincipale *pwindow;
    ShareCount* shareCount;
};

#endif // PAGECREATIONCOMPTE_H
