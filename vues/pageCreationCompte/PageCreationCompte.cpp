#include "PageCreationCompte.h"
#include "ui_PageCreationCompte.h"
#include "vues/pageaccueil/PageAccueil.h"

PageCreationCompte::PageCreationCompte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageCreationCompte)
{
    ui->setupUi(this);
}

PageCreationCompte::PageCreationCompte(QWidget *parent, FenetrePrincipale *fp) :
    QWidget(parent),
    ui(new Ui::PageCreationCompte),
    pwindow(fp)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(annuler()));
}

void PageCreationCompte::annuler() {
    pwindow->setPageActive(new PageAccueil(pwindow, pwindow));
}


PageCreationCompte::~PageCreationCompte()
{
    delete ui;
}
