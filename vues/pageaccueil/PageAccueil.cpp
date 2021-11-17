#include "PageAccueil.h"
#include "ui_PageAccueil.h"
#include "vues/pagecreationcompte/PageCreationCompte.h"
#include <iostream>

PageAccueil::PageAccueil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageAccueil)
{
    ui->setupUi(this);
    setConnect();
}

PageAccueil::PageAccueil(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc) :
    QWidget(parent),
    ui(new Ui::PageAccueil),
    pwindow(fp),
    shareCount(sc)
{
    ui->setupUi(this);
    setConnect();
}

void PageAccueil::creerCompte() {
    pwindow->setPageActive(new PageCreationCompte(pwindow, pwindow, shareCount));
}

void PageAccueil::setConnect() {
    connect(ui->boutonCreationCompte, SIGNAL(released()), this, SLOT(creerCompte()));
    connect(ui->boutonConnexion, SIGNAL(released()), this, SLOT(connexion()));
}

void PageAccueil::connexion() {
    if (shareCount->identifierUtilisateur(ui->lineEdit->text(), ui->lineEdit_2->text())) {
        std::cout << "La connexion est presque réussie !" << std::endl;
    }
}

PageAccueil::~PageAccueil()
{
    delete ui;
}
