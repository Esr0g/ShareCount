#include "PageCreationCompte.h"
#include "ui_PageCreationCompte.h"

PageCreationCompte::PageCreationCompte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageCreationCompte)
{
    ui->setupUi(this);
}

PageCreationCompte::PageCreationCompte(QWidget *parent, FenetrePrincipale *fp) :
    QWidget(parent),
    ui(new Ui::PageCreationCompte),
    pwindow(fp)
{
    ui->setupUi(this);
}


PageCreationCompte::~PageCreationCompte()
{
    delete ui;
}
