#include "PagePrincipale.h"
#include "ui_PagePrincipale.h"
#include <QtWidgets>
#include <QDockWidget>
#include "vues/pagecreationgroupe/PageCreationGroupe.h"
#include "vues/pagegestiondebudget/PageGestionDeBudget.h"
#include "model/bdd/BDDManager.h"
#include "QListWidget"
#include "QTextEdit"

/**
 * @brief PagePrincipale
 * @param parent
 */
PagePrincipale::PagePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PagePrincipale)
{
    ui->setupUi(this);
}

/**
 * @brief PagePrincipale
 * @param fp fenêtre principale de l'application
 * @param sc sharcount (Sorte de système de l'application)
 * @param sc
 */
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

/**
 * @brief afficherGroupe place la page de gestion de budget au centre de la mainWindow
 */
void PagePrincipale::afficherGroupe(){
    PageGestionDeBudget *pgdb = new PageGestionDeBudget(pwindow, pwindow, shareCount);

    //qDebug() << vlg->getListView()->currentIndex().data().toString();
    pgdb->getLabelNomGroupe()->setText(vlg->getListView()->currentIndex().data().toString());
    setCentralWidget(pgdb);
    pgdb->miseAJourParticipant();
    shareCount->setGroupeActif(shareCount->getUtilisateurActif().getGroupe(vlg->getListView()->currentIndex().data().toString()));
    pgdb->miseAJourDepenses();
    pgdb->setEquilibre();
}

PagePrincipale::~PagePrincipale()
{
    delete ui;
}


/**
 * @brief ajouterGroupe place la page de création de groupe au centre de la mainWindow
 */
void PagePrincipale::ajouterGroupe()
{
    PageCreationGroupe *pcg = new PageCreationGroupe(pwindow, pwindow, shareCount);
    setCentralWidget(pcg);
    vlg->setPageCreationGroupe(pcg);
}

/**
 * @brief setConnect connecte les signaux et slots
 */
void PagePrincipale::setConnect(VueListeGroupe *vlg){
    QObject::connect(vlg->getCreerGroupeButton(), &QPushButton::clicked, this, &PagePrincipale::ajouterGroupe); //lors d'un clique sur le bouton "Créer un groupe" de la vueListeGroupe on affiche la pageCréation groupe
    QObject::connect(vlg->getListView(), SIGNAL(clicked(const QModelIndex)),this,SLOT(afficherGroupe()));
    QObject::connect(ui->actionDeconnexion, SIGNAL(triggered(bool)), this->parent(), SLOT(deconnexion()));
}


/**
 * @brief getShareCount retourne le ShareCount
 * @return
 */
ShareCount* PagePrincipale::getShareCount() {
    return shareCount;
}
