#include "Connecte.h"
#include "ui_Connecte.h"
#include "Mainwindow.h"
#include <string>

Connecte::Connecte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connecte)
{
    ui->setupUi(this);
    QString msg = "Bienvenue ";
    std::string str = count.getGestionnaireUtilisateurs().getUtilisateurs().back().getIdentifiant();
    QString qstr = QString::fromStdString(str);
    msg.append(qstr);
    msg.append("\n Vous êtes connecté !");
    ui->label->setText(msg);
}

Connecte::~Connecte()
{
    delete ui;
}
