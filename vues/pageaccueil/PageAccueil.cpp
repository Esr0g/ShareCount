#include "PageAccueil.h"
#include "ui_PageAccueil.h"
#include "vues/pagecreationcompte/PageCreationCompte.h"

PageAccueil::PageAccueil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageAccueil)
{
    ui->setupUi(this);
    connect(ui->boutonCreationCompte, SIGNAL(released()), this, SLOT(creerCompte()));
}

PageAccueil::PageAccueil(QWidget *parent, FenetrePrincipale *fp) :
    QWidget(parent),
    ui(new Ui::PageAccueil),
    pwindow(fp)
{
    ui->setupUi(this);
    connect(ui->boutonCreationCompte, SIGNAL(released()), this, SLOT(creerCompte()));
}

void PageAccueil::creerCompte() {
    pwindow->setPageActive(new PageCreationCompte(pwindow, pwindow));
}

PageAccueil::~PageAccueil()
{
    delete ui;
}
