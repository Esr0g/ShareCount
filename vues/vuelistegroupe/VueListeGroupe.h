#ifndef VUELISTEGROUPE_H
#define VUELISTEGROUPE_H

#include <QDockWidget>
#include "screen/fenetreprincipale/FenetrePrincipale.h"
#include "model/sharecount/ShareCount.h"
#include "vues/pagecreationgroupe/pagecreationgroupe.h"
#include <QPushButton>
#include <QStringListModel>
#include <QAbstractItemModel>

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
    void setPageCreationGroupe(PageCreationGroupe *pcg);
    ~VueListeGroupe();

private slots:
    void creerGroupeButtonClicked();
    void ajouterGroupe();  //ajout d'un groupe dans le tree view
private:
    void setConnect(PageCreationGroupe *pcg);
private:
    Ui::VueListeGroupe *ui;
    FenetrePrincipale *pwindow;
    ShareCount* shareCount;
    PageCreationGroupe* pageCreationGroupe;
};

#endif // VUELISTEGROUPE_H
