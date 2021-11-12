#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include "Creationcompte.h"
#include "Connexion.h"

Mainwindow::Mainwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mainwindow)
{
    ui->setupUi(this);
}

Mainwindow::~Mainwindow()
{
    delete ui;
}

void Mainwindow::on_pushButton_2_clicked()
{
    Creationcompte creationcompte;
    creationcompte.setModal(true);
    creationcompte.exec();
}

void Mainwindow::on_pushButton_clicked()
{
    Connexion connexion;
    connexion.setModal(true);
    connexion.exec();
}
