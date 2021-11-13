#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include "Creationcompte.h"
#include "Connexion.h"


ShareCount count;

Mainwindow::Mainwindow(ShareCount *sc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mainwindow)
{
    ui->setupUi(this);
    shareCount = sc;
    count = *sc; //-------
}

Mainwindow::~Mainwindow()
{
    delete ui;
}

void Mainwindow::on_pushButton_2_clicked()
{
    //hide();
    creationcomte = new Creationcompte(&count , this);
    creationcomte->show();

//    Creationcompte creationcompte(&count);
//    creationcompte.setModal(true);
//    creationcompte.exec();
}

void Mainwindow::on_pushButton_clicked()
{
    hide();

    connexion = new Connexion(&count,this);
    connexion->show();


//    Connexion connexion(&count);
//    connexion.setModal(true);
//    connexion.exec();
}
