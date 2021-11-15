#include "FenetrePrincipale.h"
#include "ui_FenetrePrincipale.h"
#include "vues/pageCreationCompte/PageCreationCompte.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FenetrePrincipale)
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

void FenetrePrincipale::creerCompte() {
    setPageActive(new PageCreationCompte(this, this));
}



FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;
}
