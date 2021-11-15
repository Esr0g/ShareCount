#include "FenetrePrincipale.h"
#include "ui_FenetrePrincipale.h"

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
    if (pageActive) {
        delete pageActive;
    }

    pageActive = p;
}

void FenetrePrincipale::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    if (pageActive) {
        pageActive->resize(width(), height());
    }
}


FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;
}
