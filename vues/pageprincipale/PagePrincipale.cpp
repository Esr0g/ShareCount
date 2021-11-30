#include "PagePrincipale.h"
#include "ui_PagePrincipale.h"
#include "vues/pagecreationgroupe/pagecreationgroupe.h"

PagePrincipale::PagePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PagePrincipale)
{
    ui->setupUi(this);
    setConnect();
}

PagePrincipale::PagePrincipale(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc) :
    QMainWindow(parent),
    ui(new Ui::PagePrincipale),
    pwindow(fp),
    shareCount(sc)
{
    ui->setupUi(this);
    setConnect();
}

PagePrincipale::~PagePrincipale()
{
    delete ui;
}

void PagePrincipale::ajouterGroupe()
{
    pwindow->setPageActive(new PageCreationGroupe(pwindow, pwindow, shareCount));
    pwindow->show();
}


void PagePrincipale::setConnect(){
    connect(ui->ajouterGroupe, SIGNAL(released()), this, SLOT(ajouterGroupe()));
}

