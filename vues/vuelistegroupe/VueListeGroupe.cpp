#include "VueListeGroupe.h"
#include "ui_VueListeGroupe.h"
#include "vues/pagecreationgroupe/pagecreationgroupe.h"

VueListeGroupe::VueListeGroupe(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::VueListeGroupe)
{
    ui->setupUi(this);
}

VueListeGroupe::VueListeGroupe(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc) :
    QDockWidget(parent),
    ui(new Ui::VueListeGroupe),
    pwindow(fp),
    shareCount(sc)
{
    ui->setupUi(this);

    //setConnexion();
}

VueListeGroupe::~VueListeGroupe()
{
    delete ui;
}

void VueListeGroupe::creerGroupeButtonClicked(){
    //PageCreationGroupe *pcg = new PageCreationGroupe(pwindow, pwindow, shareCount);
    //setCentralWidget(pcg);
    //pprincipale->ajouterGroupe();
}

QPushButton *VueListeGroupe::getCreerGroupeButton(){
    return ui->creerGroupeButton;
}
