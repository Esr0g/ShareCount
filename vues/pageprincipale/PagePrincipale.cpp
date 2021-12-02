#include "PagePrincipale.h"
#include "ui_PagePrincipale.h"
#include <QtWidgets>
#include <QDockWidget>
#include "vues/pagecreationgroupe/pagecreationgroupe.h"
#include "model/bdd/BDDManager.h"
#include "QListWidget"
#include "QTextEdit"
#include "vues/vuelistegroupe/VueListeGroupe.h"

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

    setCentralWidget(new QTextEdit());
    QDockWidget *dock = new QDockWidget(tr("Customers"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    dock->setWidget(new QTextEdit());
    addDockWidget(Qt::LeftDockWidgetArea, dock);
    setConnect();
}

PagePrincipale::~PagePrincipale()
{
    delete ui;
}

void PagePrincipale::ajouterGroupe()
{
    VueListeGroupe *vueGroupes = new VueListeGroupe(pwindow, pwindow, shareCount);
    addDockWidget(Qt::LeftDockWidgetArea, vueGroupes);

    PageCreationGroupe *pcg = new PageCreationGroupe(pwindow, pwindow, shareCount);
    setCentralWidget(pcg);
    /*
    QDockWidget *dock = new QDockWidget("CréationGroupe",this);
    dock->setFeatures(dock->features() & ~QDockWidget::DockWidgetClosable);
    dock->setFeatures(dock->features() & ~QDockWidget::DockWidgetMovable);
    dock->setFeatures(dock->features() & ~QDockWidget::DockWidgetFloatable);
    dock->setWidget(pcg);
    dock->setAllowedAreas(Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    //addDockWidget(Qt::RightDockWidgetArea, pcg);*/

}

void PagePrincipale::setConnect(){
    //connect(ui->ajouterGroupe, SIGNAL(released()), this, SLOT(ajouterGroupe()));
}

