#include "VueListeGroupe.h"
#include "ui_VueListeGroupe.h"
#include "vues/pagecreationgroupe/pagecreationgroupe.h"

VueListeGroupe::VueListeGroupe(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::VueListeGroupe)
{
    ui->setupUi(this);
}

VueListeGroupe::VueListeGroupe(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc) :
    QDockWidget(parent),
    ui(new Ui::VueListeGroupe),
    pwindow(fp),
    shareCount(sc)
{
    ui->setupUi(this);
    setConnect1();

    //setConnect(pageCreationGroupe);
    //setConnexion();
}

VueListeGroupe::~VueListeGroupe()
{
    delete ui;
}

void VueListeGroupe::setPageCreationGroupe(PageCreationGroupe *pcg){
    pageCreationGroupe = pcg;
    setConnect(pageCreationGroupe);
}

void VueListeGroupe::creerGroupeButtonClicked(){
    //active le signal
}

QPushButton *VueListeGroupe::getCreerGroupeButton(){
    return ui->creerGroupeButton;
}

QListView *VueListeGroupe::getListView(){
    return ui->listView;
}

void VueListeGroupe::setConnect(PageCreationGroupe *pcg){
    QObject::connect(pcg->getCreerGroupeButton(), &QPushButton::clicked, this, &VueListeGroupe::ajouterGroupe); //lors d'un clique sur le bouton "Créer un groupe" de la pageCreationGroupe on affiche le groupe crée dans la listView
}

void VueListeGroupe::setConnect1(){
    QObject::connect(ui->listView,SIGNAL(clicked(const QModelIndex)),this,SLOT(itemClicked(QModelIndex)));
}

void VueListeGroupe::ajouterGroupe(){
    groupes << pageCreationGroupe->getNomGroupe();
    QAbstractItemModel *model = new QStringListModel(groupes);
    ui->listView->setModel(model);
}

QModelIndex VueListeGroupe::getIndexList(){
    return indexList;
}

void VueListeGroupe::itemClicked(QModelIndex index){
    qDebug() << index.data().toString();
}
