#ifndef VUELISTEGROUPE_H
#define VUELISTEGROUPE_H

#include <QDockWidget>
#include "screen/fenetreprincipale/FenetrePrincipale.h"
#include "model/sharecount/ShareCount.h"
//#include "vues/pageprincipale/PagePrincipale.h"
#include <QPushButton>

namespace Ui {
class VueListeGroupe;
}

class VueListeGroupe : public QDockWidget
{
    Q_OBJECT

public:
    explicit VueListeGroupe(QWidget *parent = nullptr);
    explicit VueListeGroupe(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc);
    QPushButton *getCreerGroupeButton();
    ~VueListeGroupe();

private slots:
    void creerGroupeButtonClicked();

private:
    Ui::VueListeGroupe *ui;
    FenetrePrincipale *pwindow;
    ShareCount* shareCount;
};

#endif // VUELISTEGROUPE_H
