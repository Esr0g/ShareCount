#ifndef PAGEACCUEIL_H
#define PAGEACCUEIL_H

#include <QWidget>
#include <screen/fenetreprincipale/FenetrePrincipale.h>
#include <model/sharecount/ShareCount.h>

namespace Ui {
class PageAccueil;
}

class PageAccueil : public QWidget
{
    Q_OBJECT

public:
    explicit PageAccueil(QWidget *parent = nullptr);
    explicit PageAccueil(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc);
    void setConnect();
    ~PageAccueil();

public slots:
    void creerCompte();
    void connexion();

private:
    Ui::PageAccueil *ui;
    FenetrePrincipale *pwindow;
    ShareCount* shareCount;
};

#endif // PAGEACCUEIL_H
