#ifndef PAGECREATIONCOMPTE_H
#define PAGECREATIONCOMPTE_H

#include <QWidget>
#include "screen/fenetreprincipale/FenetrePrincipale.h"
#include "model/sharecount/ShareCount.h"

namespace Ui {
class PageCreationCompte;
}

class PageCreationCompte : public QWidget
{
    Q_OBJECT

public:
    explicit PageCreationCompte(QWidget *parent = nullptr);
    explicit PageCreationCompte(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc);
    ~PageCreationCompte();

public slots:
    void annuler();
    void onPushButtonCreerCompte();

private:
    void setConnexion();

    Ui::PageCreationCompte *ui;
    FenetrePrincipale *pwindow;
    ShareCount* shareCount;
};

#endif // PAGECREATIONCOMPTE_H
