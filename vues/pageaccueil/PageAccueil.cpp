#include "PageAccueil.h"
#include "ui_PageAccueil.h"
#include "vues/pageCreationCompte/PageCreationCompte.h"

PageAccueil::PageAccueil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageAccueil)
{
    ui->setupUi(this);
    connect(ui->boutonCreationCompte, SIGNAL(released()), pwindow, SLOT(creerCompte()));
}

PageAccueil::PageAccueil(QWidget *parent, FenetrePrincipale *fp) :
    QWidget(parent),
    ui(new Ui::PageAccueil),
    pwindow(fp)
{
    ui->setupUi(this);
    connect(ui->boutonCreationCompte, SIGNAL(released()), pwindow, SLOT(creerCompte()));
}

PageAccueil::~PageAccueil()
{
    delete ui;
}
