#include "PageAccueil.h"
#include "ui_PageAccueil.h"
#include "vues/pagecreationcompte/PageCreationCompte.h"
#include "vues/pageprincipale/PagePrincipale.h"
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
        pwindow->setPageActive(new PagePrincipale(pwindow, pwindow, shareCount));
        pwindow->hide();
    } else {
        std::cout << "Identifiant ou Mot de passe incorrect" << std::endl;
    }
}

PageAccueil::~PageAccueil()
{
    delete ui;
}
