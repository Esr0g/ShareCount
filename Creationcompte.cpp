#include "Creationcompte.h"
#include "ui_Creationcompte.h"
#include <QDebug>
#include "Utilisateur.h"
#include "Sharecount.h"
#include <iostream>
#include "Mainwindow.h" //--------



Creationcompte::Creationcompte(ShareCount *sc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Creationcompte)
{
    ui->setupUi(this);
    shareCount = *sc;
}

Creationcompte::~Creationcompte()
{
    delete ui;
}

void Creationcompte::on_pushButton_clicked()
{
    QString nom = ui->lineEdit_4->text();  //on stock les informations données
    QString prenom = ui->lineEdit_3->text();
    QString mail = ui->lineEdit_2->text();
    QString identifiant = ui->lineEdit->text();
    QString mdp = ui->lineEdit_5->text();
    count.getGestionnaireUtilisateurs().getUtilisateurs();
    std::list<Utilisateur> users = count.getGestionnaireUtilisateurs().getUtilisateurs();

    Utilisateur utilisateur = Utilisateur(nom.toStdString(), identifiant.toStdString(), mail.toStdString(), mdp.toStdString());
    //users.push_back(utilisateur);
    //shareCount.getGestionnaireUtilisateurs().ajouterUtilisateur(&utilisateur);
    //std::cout << users.size();
    std::cout << users.size() << " taille avant \n";

    users.push_back(utilisateur);

    std::cout << users.size() << " taille après \n";

    gestionnaireUtilisateurs gu = gestionnaireUtilisateurs();
    gu.setListe(users);
    count.setGestionnaireUtilisateurs(gu);
    std::cout << count.getGestionnaireUtilisateurs().getUtilisateurs().size() << " taille après encore \n";
    //std::cout << shareCount.getGestionnaireUtilisateurs().getUtilisateurs().back().getIdentifiant();
    close();
    //qDebug() << nom;
    //Mainswindow Mainwindow = new Mainwindow();
}
