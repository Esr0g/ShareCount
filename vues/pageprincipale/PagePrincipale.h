#ifndef PAGEPRINCIPALE_H
#define PAGEPRINCIPALE_H

#include <QMainWindow>
#include <screen/fenetreprincipale/FenetrePrincipale.h>
#include "vues/vuelistegroupe/VueListeGroupe.h"
#include "vues/pagegestiondebudget/PageGestionDeBudget.h"
#include <QListView>
#include <QDebug>

namespace Ui {
class PagePrincipale;
}

class PagePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    explicit PagePrincipale(QWidget *parent = nullptr);
    explicit PagePrincipale(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc);
    ShareCount* getShareCount();
    ~PagePrincipale();

private:
    void setConnect(VueListeGroupe *vlg);

private slots:
    void ajouterGroupe();
    void afficherGroupe();  //Affichage des données du groupe dans le central widget

private:
    Ui::PagePrincipale *ui;
    FenetrePrincipale* pwindow;
    ShareCount* shareCount;
    VueListeGroupe* vlg;
};

#endif // PAGEPRINCIPALE_H
