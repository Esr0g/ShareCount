#include "Connexion.h"
#include "ui_Connexion.h"
#include "Gestionnaireutilisateurs.h"
#include <iostream>
#include "Mainwindow.h"
#include "Connecte.h"


Connexion::Connexion(ShareCount *sc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connexion)
{
    ui->setupUi(this);
    shareCount = *sc;
}

Connexion::~Connexion()
{
    delete ui;
}

void Connexion::on_pushButton_clicked()
{
    QString identifiant = ui->lineEdit->text();
    QString mdp = ui->lineEdit_2->text();
    std::list<Utilisateur> users = count.getGestionnaireUtilisateurs().getUtilisateurs();
    Utilisateur user = users.back(); //Il ne récupère rien -> std::logic_error
    std::cout << identifiant.toStdString() << "\n";
    std::cout << user.getIdentifiant() << "\n";
    std::cout << mdp.toStdString() << "\n";
    std::cout << user.getMotDePasse() << "\n";
    if((identifiant.toStdString()==user.getIdentifiant())&&(mdp.toStdString()==user.getMotDePasse())){
        std::cout << "Vous êtes connecté ! ";
        close();

        Connecte connecte;
        connecte.setModal(true);
        connecte.exec();
    }
}
