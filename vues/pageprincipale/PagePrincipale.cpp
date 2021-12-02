#include "PagePrincipale.h"
#include "ui_PagePrincipale.h"
#include <QtWidgets>
#include <QDockWidget>
#include "vues/pagecreationgroupe/pagecreationgroupe.h"
#include "model/bdd/BDDManager.h"
#include "QListWidget"
#include "QTextEdit"

PagePrincipale::PagePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PagePrincipale)
{
    ui->setupUi(this);
    /*dockOptions().setFlag(QMainWindow::VerticalTabs);
    QDockWidget *dock = new QDockWidget("VuePrincipale",this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);
    dock->setWidget(new PageCreationGroupe(pwindow, pwindow, shareCount));
    addDockWidget(Qt::RightDockWidgetArea, dock);
    this->show();*/

    /*QDockWidget *dock = new QDockWidget;
    dock->setAllowedAreas(Qt::AllDockWidgetAreas);
    dock->setWidget(new PageCreationGroupe(pwindow, pwindow, shareCount));
    this->addDockWidget(Qt::LeftDockWidgetArea, dock);
    setConnect();*/
    //QHBoxLayout *box =  this->findChild<QHBoxLayout*>("verticalLayout");
    //box->addWidget(new QPushButton("Bonjour"));
    //QHBoxLayout *layout =
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
    //pwindow->setPageActive(new PageCreationGroupe(pwindow, pwindow, shareCount));
    //pwindow->show();

}

void PagePrincipale::setConnect(){
    //connect(ui->ajouterGroupe, SIGNAL(released()), this, SLOT(ajouterGroupe()));
}

