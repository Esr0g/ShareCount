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
    //PageCreationGroupe *pcg = new PageCreationGroupe(pwindow, pwindow, shareCount);
    //setCentralWidget(pcg);
    //pprincipale->ajouterGroupe();
}

QPushButton *VueListeGroupe::getCreerGroupeButton(){
    return ui->creerGroupeButton;
}

void VueListeGroupe::setConnect(PageCreationGroupe *pcg){
    //QString nomGroupe = QString::fromStdString("Groupe1");
    QObject::connect(pcg->getCreerGroupeButton(), &QPushButton::clicked, this, &VueListeGroupe::ajouterGroupe);
}

void VueListeGroupe::ajouterGroupe(){
    //QStringList groupes;
    groupes << pageCreationGroupe->getNomGroupe();
    QAbstractItemModel *model = new QStringListModel(groupes);
    ui->listView->setModel(model);
}
