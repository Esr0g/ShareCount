#include "PagePrincipale.h"
#include "ui_PagePrincipale.h"

PagePrincipale::PagePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PagePrincipale)
{
    ui->setupUi(this);
}

PagePrincipale::PagePrincipale(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc) :
    QMainWindow(parent),
    pwindow(fp),
    ui(new Ui::PagePrincipale),
    shareCount(sc)
{
    ui->setupUi(this);
}

PagePrincipale::~PagePrincipale()
{
    delete ui;
}
