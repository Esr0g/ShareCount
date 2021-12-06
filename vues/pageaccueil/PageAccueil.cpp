#include "PageAccueil.h"
#include "ui_PageAccueil.h"
#include "vues/pagecreationcompte/PageCreationCompte.h"
#include "vues/pageprincipale/PagePrincipale.h"
#include <iostream>
#include <QMessageBox>

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
        Utilisateur u = shareCount->getUtilisateur(ui->lineEdit->text());
        shareCount->setUtilisateurActif(u);
        if (pwindow->pageEstEnAttente()) {
            pwindow->setPageActive(pwindow->getPageEnattente());
            pwindow->setPageEstEnAttente(false);
            pwindow->hide();
        } else {
            pwindow->setPageActive(new PagePrincipale(pwindow, pwindow, shareCount));
            pwindow->hide();
        }
    } else {
        QMessageBox::critical(this, "Erreur connexion", "Identifiant ou mot de passe inconnu, veuillez réessayer");
    }
}

PageAccueil::~PageAccueil()
{
    delete ui;
}
