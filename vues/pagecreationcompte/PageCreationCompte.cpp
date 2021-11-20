#include "PageCreationCompte.h"
#include "ui_PageCreationCompte.h"
#include "vues/pageaccueil/PageAccueil.h"

PageCreationCompte::PageCreationCompte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageCreationCompte)
{
    ui->setupUi(this);
    setConnexion();
}

PageCreationCompte::PageCreationCompte(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc) :
    QWidget(parent),
    ui(new Ui::PageCreationCompte),
    pwindow(fp),
    shareCount(sc)
{
    ui->setupUi(this);
    setConnexion();
}

void PageCreationCompte::annuler() {
    pwindow->setPageActive(new PageAccueil(pwindow, pwindow, shareCount));
}

void PageCreationCompte::setConnexion() {
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(annuler()));
    connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(onPushButtonCreerCompte()));
}

void PageCreationCompte::onPushButtonCreerCompte() {
    Utilisateur u;
    u.setIdentifiant(ui->lineEdit_2->text());
    u.setMotDePasse(ui->lineEdit_4->text());
    u.setMail(ui->lineEdit_6->text());

    shareCount->ajouterUtilisateur(u);

    pwindow->setPageActive(new PageAccueil(pwindow, pwindow, shareCount));
}

PageCreationCompte::~PageCreationCompte()
{
    delete ui;
}
