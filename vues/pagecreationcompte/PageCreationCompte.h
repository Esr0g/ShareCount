#ifndef PAGECREATIONCOMPTE_H
#define PAGECREATIONCOMPTE_H

#include <QWidget>
#include "screen/fenetreprincipale/FenetrePrincipale.h"

namespace Ui {
class PageCreationCompte;
}

class PageCreationCompte : public QWidget
{
    Q_OBJECT

public:
    explicit PageCreationCompte(QWidget *parent = nullptr);
    explicit PageCreationCompte(QWidget *parent, FenetrePrincipale *fp);
    ~PageCreationCompte();

public slots:
    void annuler();

private:
    Ui::PageCreationCompte *ui;
    FenetrePrincipale *pwindow;
};

#endif // PAGECREATIONCOMPTE_H
