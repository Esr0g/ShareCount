#include "pagecreationgroupe.h"
#include "ui_pagecreationgroupe.h"

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

PageCreationGroupe::~PageCreationGroupe()
{
    delete ui;
}


void PageCreationGroupe::setConnexion() {
    //connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(annuler()));
    //connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(onPushButtonCreerCompte()));
}

void PageCreationGroupe::on_CreerGroupe_clicked()
{

}
