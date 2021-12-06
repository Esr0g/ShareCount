#include "FenetrePrincipale.h"
#include "ui_FenetrePrincipale.h"
#include "vues/pageaccueil/PageAccueil.h"
#include "vues/pageprincipale/PagePrincipale.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FenetrePrincipale)
{
    ui->setupUi(this);
    pageActive = nullptr;
    resize(1280, 720);
}

FenetrePrincipale::FenetrePrincipale(QWidget *parent, ShareCount* sc):
     QWidget(parent),
     ui(new Ui::FenetrePrincipale),
     shareCount(sc)
 {
     ui->setupUi(this);
     pageActive = nullptr;
     resize(1280, 720);
 }

FenetrePrincipale* FenetrePrincipale::getThis() {
    return this;
}

void FenetrePrincipale::setPageActive(QWidget *p) {
    if (pageActive != nullptr) {
        delete pageActive;
        pageActive = nullptr;
    }

    pageActive = p;
    resizeEvent(nullptr);
    pageActive->show();
}

void FenetrePrincipale::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    if (pageActive) {
        pageActive->resize(width(), height());
    }
}

void FenetrePrincipale::deconnexion() {
    this->setVisible(true);
    shareCount = ((PagePrincipale*)pageActive)->getShareCount();
    pageActive->close();
    pageActive = nullptr;
    setPageActive(new PageAccueil(this, this, shareCount));
}

FenetrePrincipale::~FenetrePrincipale()
{
    delete pageActive;
    delete ui;
}
