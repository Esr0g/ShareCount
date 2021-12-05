#include "PagePrincipale.h"
#include "ui_PagePrincipale.h"
#include <QtWidgets>
#include <QDockWidget>
#include "vues/pagecreationgroupe/PageCreationGroupe.h"
#include "vues/pagegestiondebudget/PageGestionDeBudget.h"
#include "model/bdd/BDDManager.h"
#include "QListWidget"
#include "QTextEdit"

PagePrincipale::PagePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PagePrincipale)
{
    ui->setupUi(this);
}

PagePrincipale::PagePrincipale(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc) :
    QMainWindow(parent),
    ui(new Ui::PagePrincipale),
    pwindow(fp),
    shareCount(sc)
{
    ui->setupUi(this);

    VueListeGroupe *vueGroupes = new VueListeGroupe(pwindow, pwindow, shareCount);
    addDockWidget(Qt::LeftDockWidgetArea, vueGroupes);
    vlg = vueGroupes;
    setConnect(vlg);
    setWindowTitle("ShareCount - " + shareCount->getUtilisateurActif().getIdentifiant());
    //afficherGroupe();
}

void PagePrincipale::afficherGroupe(){
    PageGestionDeBudget *pgdb = new PageGestionDeBudget(pwindow, pwindow, shareCount);

    //qDebug() << vlg->getListView()->currentIndex().data().toString();
    pgdb->getLabelNomGroupe()->setText(vlg->getListView()->currentIndex().data().toString());
    setCentralWidget(pgdb);
    pgdb->miseAJourParticipant();
    shareCount->setGroupeActif(shareCount->getUtilisateurActif().getGroupe(vlg->getListView()->currentIndex().data().toString()));
    pgdb->miseAJourDepenses();
}

PagePrincipale::~PagePrincipale()
{
    delete ui;
}

void PagePrincipale::ajouterGroupe()
{
    PageCreationGroupe *pcg = new PageCreationGroupe(pwindow, pwindow, shareCount);
    setCentralWidget(pcg);
    vlg->setPageCreationGroupe(pcg);
}

void PagePrincipale::setConnect(VueListeGroupe *vlg){
    QObject::connect(vlg->getCreerGroupeButton(), &QPushButton::clicked, this, &PagePrincipale::ajouterGroupe); //lors d'un clique sur le bouton "Créer un groupe" de la vueListeGroupe on affiche la pageCréation groupe
    QObject::connect(vlg->getListView(), SIGNAL(clicked(const QModelIndex)),this,SLOT(afficherGroupe()));
}

