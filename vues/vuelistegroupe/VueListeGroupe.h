#ifndef VUELISTEGROUPE_H
#define VUELISTEGROUPE_H

#include <QDockWidget>
#include "screen/fenetreprincipale/FenetrePrincipale.h"
#include "model/sharecount/ShareCount.h"
#include "vues/pagecreationgroupe/PageCreationGroupe.h"
#include <QPushButton>
#include <QStringListModel>
#include <QAbstractItemModel>
#include <QListView>
#include <QDebug>

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
    QListView *getListView();
    QModelIndex getIndexList();
    ~VueListeGroupe();

private slots:
    void creerGroupeButtonClicked();
    void ajouterGroupe();  //ajout d'un groupe dans la listView
    void itemClicked(QModelIndex index);

private:
    void setConnect(PageCreationGroupe *pcg);
    void setConnect1();
private:
    Ui::VueListeGroupe *ui;
    FenetrePrincipale *pwindow;
    ShareCount* shareCount;
    PageCreationGroupe* pageCreationGroupe;
    QStringList groupes;
    QModelIndex indexList;
};

#endif // VUELISTEGROUPE_H
