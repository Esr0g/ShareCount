#include "Creationcompte.h"
#include "ui_Creationcompte.h"
#include <QDebug>

Creationcompte::Creationcompte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Creationcompte)
{
    ui->setupUi(this);
}

Creationcompte::~Creationcompte()
{
    delete ui;
}

void Creationcompte::on_pushButton_clicked()
{
    QString nom = ui->lineEdit_4->text();  //on stock les informations données
    QString prenom = ui->lineEdit_3->text();
    QString mail = ui->lineEdit->text();
    QString identifiant = ui->lineEdit_2->text();
    QString mdp = ui->lineEdit_5->text();
    //qDebug() << nom;
}
