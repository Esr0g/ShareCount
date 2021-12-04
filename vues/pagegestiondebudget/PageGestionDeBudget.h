#ifndef PAGEGESTIONDEBUDGET_H
#define PAGEGESTIONDEBUDGET_H

#include "screen/fenetreprincipale/FenetrePrincipale.h"
#include "model/sharecount/ShareCount.h"
#include <QWidget>
#include <QLabel>

namespace Ui {
class PageGestionDeBudget;
}

class PageGestionDeBudget : public QWidget
{
    Q_OBJECT

public:
    explicit PageGestionDeBudget(QWidget *parent = nullptr);
    explicit PageGestionDeBudget(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc);
    QLabel *getLabelNomGroupe();
    ~PageGestionDeBudget();

private:
    Ui::PageGestionDeBudget *ui;
    FenetrePrincipale* pwindow;
    ShareCount* shareCount;
    QLabel nomGroupe;
};

#endif // PAGEGESTIONDEBUDGET_H
