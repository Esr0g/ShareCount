#ifndef PAGEACCUEIL_H
#define PAGEACCUEIL_H

#include <QWidget>
#include <screen/fenetreprincipale/FenetrePrincipale.h>

namespace Ui {
class PageAccueil;
}

class PageAccueil : public QWidget
{
    Q_OBJECT

public:
    explicit PageAccueil(QWidget *parent = nullptr);
    explicit PageAccueil(QWidget *parent, FenetrePrincipale *fp);
    ~PageAccueil();

public slots:
    void creerCompte();

private:
    Ui::PageAccueil *ui;
    FenetrePrincipale *pwindow;
};

#endif // PAGEACCUEIL_H
