#include "VueListeGroupe.h"
#include "ui_VueListeGroupe.h"

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

    //setConnexion();
}

VueListeGroupe::~VueListeGroupe()
{
    delete ui;
}
