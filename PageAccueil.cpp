#include "PageAccueil.h"
#include "ui_PageAccueil.h"

PageAccueil::PageAccueil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageAccueil)
{
    ui->setupUi(this);
}

PageAccueil::~PageAccueil()
{
    delete ui;
}
