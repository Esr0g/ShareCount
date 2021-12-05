#include "PageGestionDeBudget.h"
#include "ui_pagegestiondebudget.h"
#include <QMessageBox>
#include <iostream>
#include <sstream>
#include <iomanip>

PageGestionDeBudget::PageGestionDeBudget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageGestionDeBudget)
{
    ui->setupUi(this);
}

PageGestionDeBudget::PageGestionDeBudget(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc):
    QWidget(parent),
    ui(new Ui::PageGestionDeBudget),
    pwindow(fp),
    shareCount(sc)
{
    ui->setupUi(this);
}

QLabel *PageGestionDeBudget::getLabelNomGroupe(){
    return ui->label;
}


PageGestionDeBudget::~PageGestionDeBudget()
{
    delete ui;
}

void PageGestionDeBudget::on_ajouterDepenseButton_clicked()
{
    //QDialog *dialog = new QDialog(parent, 0);
    //QString text = QInputDialog::getText(0, "Nouvelle dépense", "Montant", QLineEdit::Normal,"", &ok);

    double valeurDep = QInputDialog::getDouble(this, "Ajouter Une Dépense", "Nouvelle Dépense : ", 0, 0, 10000, 2);

    if (valeurDep != 0) {
        std::ostringstream streamObj;
        streamObj<< std::fixed;
        streamObj << std::setprecision(2);
        streamObj << valeurDep;
        QString valeurTxt = QString::fromStdString(streamObj.str());
        depenses << valeurTxt + " € par " +shareCount->getUtilisateurActif().getIdentifiant();;
    }
    QAbstractItemModel *model = new QStringListModel(depenses);
    ui->depenseListView->setModel(model);
    /*QMessageBox msgBox;
    msgBox.setText("Montant :"); //Titre | date | payé par | pour qui
    msgBox.exec();*/
    //Depense *depense = new Depense();
}

void PageGestionDeBudget::on_ajouterParticipantButton_clicked() {
    QString user = QInputDialog::getText(this, "Ajouter Un Participant", "Identifiant Utilisateur: ");

    bool ajouter = false;

    if (!user.isEmpty()) {
        if (shareCount->findUtilisateur(user)) {
            ajouter = true;
            if (shareCount->appartientAuGroupe(user, ui->label->text())) {
                ajouter = false;
                QMessageBox::critical(this, "Erreur Ajout Participant", "Ce participant appartient déjà à ce groupe");
            }
        } else {
            ajouter = false;
            QMessageBox::critical(this, "Erreur Ajout Participant", "L'identifiant n'existe pas !");
        }
    } else {
        ajouter = false;
    }

    if (ajouter) {
        shareCount->ajouterParticipantAuGroupe(user, ui->label->text());
        QAbstractItemModel *model = new QStringListModel(shareCount->initialiserParticipants(ui->label->text()));
        ui->participantsLisetView->setModel(model);
    }
}

void PageGestionDeBudget::miseAJourParticipant() {
    QAbstractItemModel *model = new QStringListModel(shareCount->initialiserParticipants(ui->label->text()));
    ui->participantsLisetView->setModel(model);
}
