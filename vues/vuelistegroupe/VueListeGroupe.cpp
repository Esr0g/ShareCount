#include "VueListeGroupe.h"
#include "ui_VueListeGroupe.h"
#include "vues/pagecreationgroupe/PageCreationGroupe.h"
#include <iostream>

/**
 * @brief VueListeGroupe
 * @param parent
 */
VueListeGroupe::VueListeGroupe(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::VueListeGroupe)
{
    ui->setupUi(this);
    groupes = shareCount->getUtilisateurActif().getMesGroupesToString();
    QAbstractItemModel *model = new QStringListModel(groupes);
    ui->listView->setModel(model);
}

/**
 * @brief VueListeGroupe
 * @param fp fenêtre principale de l'application
 * @param sc sharcount (Sorte de système de l'application)
 * @param parent
 */
VueListeGroupe::VueListeGroupe(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc) :
    QDockWidget(parent),
    ui(new Ui::VueListeGroupe),
    pwindow(fp),
    shareCount(sc)
{
    ui->setupUi(this);
    setConnect1();
    groupes = shareCount->getUtilisateurActif().getMesGroupesToString();
    QAbstractItemModel *model = new QStringListModel(groupes);
    ui->listView->setModel(model);

    //setConnect(pageCreationGroupe);
    //setConnexion();
}

VueListeGroupe::~VueListeGroupe()
{
    delete ui;
}


/**
 * @brief setPageCreationGroupe met en place la page de création de groupe
 */
void VueListeGroupe::setPageCreationGroupe(PageCreationGroupe *pcg){
    pageCreationGroupe = pcg;
    setConnect(pageCreationGroupe);
}


/**
 * @brief creerGroupeButtonClicked active un signal, qui sera capté par le slot qui affichera la page de création de groupe
 */
void VueListeGroupe::creerGroupeButtonClicked(){
    //active le signal
}

/**
 * @brief getCreerGroupeButton retourne le bouton creerGroupe
 * @return
 */
QPushButton *VueListeGroupe::getCreerGroupeButton(){
    return ui->creerGroupeButton;
}

/**
 * @brief getListView retourne la listView (qui affiche tous les groupes)
 * @return
 */
QListView *VueListeGroupe::getListView(){
    return ui->listView;
}

/**
 * @brief setConnect connecte les signaux et slots
 */
void VueListeGroupe::setConnect(PageCreationGroupe *pcg){
    QObject::connect(pcg->getCreerGroupeButton(), &QPushButton::clicked, this, &VueListeGroupe::ajouterGroupe); //lors d'un clique sur le bouton "Créer un groupe" de la pageCreationGroupe on affiche le groupe crée dans la listView
}

/**
 * @brief setConnect1 connecte les signaux et slots
 */
void VueListeGroupe::setConnect1(){
    QObject::connect(ui->listView,SIGNAL(clicked(const QModelIndex)),this,SLOT(itemClicked(QModelIndex)));
}

/**
 * @brief ajouterGroupe ajoute dans la listView le nom du groupe créé
 */
void VueListeGroupe::ajouterGroupe() {
    groupes = shareCount->getUtilisateurActif().getMesGroupesToString();
    QAbstractItemModel *model = new QStringListModel(groupes);
    ui->listView->setModel(model);
}

/**
 * @brief getIndexList retourne la liste d'index de la listView
 * @return
 */
QModelIndex VueListeGroupe::getIndexList(){
    return indexList;
}

/**
 * @brief itemClicked affiche le rang de l'item de la listView qui a été cliqué
 */
void VueListeGroupe::itemClicked(QModelIndex index){
    qDebug() << index.data().toString();
}
