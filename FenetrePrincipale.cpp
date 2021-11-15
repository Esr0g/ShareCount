#include "FenetrePrincipale.h"
#include "ui_FenetrePrincipale.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FenetrePrincipale)
{
    ui->setupUi(this);
}

FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;
}
