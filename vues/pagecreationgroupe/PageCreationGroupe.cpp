#include "PageCreationGroupe.h"
#include "ui_PageCreationGroupe.h"
#include "model/groupe/GroupeGestionBuget.h"
#include <QDockWidget>
#include <iostream>

PageCreationGroupe::PageCreationGroupe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageCreationGroupe)
{
    ui->setupUi(this);
}

PageCreationGroupe::PageCreationGroupe(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc) :
    QWidget(parent),
    ui(new Ui::PageCreationGroupe),
    pwindow(fp),
    shareCount(sc)
{
    ui->setupUi(this);

    //setConnexion();
}

QPushButton *PageCreationGroupe::getCreerGroupeButton(){
    return ui->CreerGroupe;
}

void PageCreationGroupe::setConnexion() {
    //connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(annuler()));
    //connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(onPushButtonCreerCompte()));
}

void PageCreationGroupe::on_CreerGroupe_clicked()
{
    Utilisateur u = shareCount->getUtilisateurActif();
    GroupeGestionBuget ggb(ui->lineEdit->text());
    u.ajouterAMesGroupes(ggb);
}

PageCreationGroupe::~PageCreationGroupe()
{
    delete ui;
}
