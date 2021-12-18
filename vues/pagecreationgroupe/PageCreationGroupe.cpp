#include "PageCreationGroupe.h"
#include "ui_PageCreationGroupe.h"
#include <QDockWidget>
#include <iostream>
#include <QMessageBox>

/**
 * @brief PageCreationGroupe
 * @param parent
 */
PageCreationGroupe::PageCreationGroupe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageCreationGroupe)
{
    ui->setupUi(this);
}

/**
 * @brief PageCreationGroupe
 * @param fp fenêtre principale de l'application
 * @param sc sharcount (Sorte de système de l'application)
 * @param parent
 */
PageCreationGroupe::PageCreationGroupe(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc) :
    QWidget(parent),
    ui(new Ui::PageCreationGroupe),
    pwindow(fp),
    shareCount(sc)
{
    ui->setupUi(this);

    //setConnexion();
}


/**
 * @brief getCreerGroupeButton retourne le bouton creerGroupe
 * @return
 */
QPushButton *PageCreationGroupe::getCreerGroupeButton(){
    return ui->CreerGroupe;
}


/**
 * @brief setConnexion
 */
void PageCreationGroupe::setConnexion() {
    //connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(annuler()));
    //connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(onPushButtonCreerCompte()));
}


/**
 * @brief on_CreerGroupe_clicked ajoute un groupe à la listView des groupes (groupe portant le nom donné dans le lineEdit)
 */
void PageCreationGroupe::on_CreerGroupe_clicked()
{
    if (shareCount->findGroupe(ui->lineEdit->text())) {
        QMessageBox::critical(this, "Erreur création groupe", "Deux groupes ne peuvent pas avoir le même nom !");
    } else {
        Utilisateur u = shareCount->getUtilisateurActif();
        Groupe ggb(ui->lineEdit->text());
        u.ajouterAMesGroupes(ggb);
        shareCount->inserGroupe(ggb, u);
    }
}

PageCreationGroupe::~PageCreationGroupe()
{
    delete ui;
}
