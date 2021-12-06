#include "FenetrePrincipale.h"
#include "ui_FenetrePrincipale.h"
#include "vues/pageaccueil/PageAccueil.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FenetrePrincipale),
    pageEnAttenteBool(false)
{
    ui->setupUi(this);
    pageActive = nullptr;
    resize(1280, 720);
}

FenetrePrincipale::FenetrePrincipale(QWidget *parent, ShareCount* sc):
     QWidget(parent),
     ui(new Ui::FenetrePrincipale),
     shareCount(sc),
     pageEnAttenteBool(false)
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
    this->show();
    pageActive->hide();
    pageEnAttente = pageActive;
    setPageEstEnAttente(true);
    pageActive = nullptr;
    std::cout << shareCount->getNombreUtilisateurs() << std::endl;
    setPageActive(new PageAccueil(this, this, shareCount));
}

bool FenetrePrincipale::pageEstEnAttente() {
    return pageEnAttenteBool;
}

QWidget* FenetrePrincipale::getPageEnattente() {
    return pageEnAttente;
}

void FenetrePrincipale::setPageEstEnAttente(bool b) {
    pageEnAttenteBool = b;
}



FenetrePrincipale::~FenetrePrincipale()
{
    delete pageActive;
    delete ui;
}
