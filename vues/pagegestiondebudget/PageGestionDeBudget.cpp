#include "PageGestionDeBudget.h"
#include "ui_pagegestiondebudget.h"
#include <QMessageBox>

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
    bool ok;
    //QString text = QInputDialog::getText(0, "Nouvelle dépense", "Montant", QLineEdit::Normal,"", &ok);
    QString text = QInputDialog::getText(this, "blabla ", "Nouvelle dépense : ");

    depenses << text;
    QAbstractItemModel *model = new QStringListModel(depenses);
    ui->depenseListView->setModel(model);
    /*QMessageBox msgBox;
    msgBox.setText("Montant :"); //Titre | date | payé par | pour qui
    msgBox.exec();*/
    //Depense *depense = new Depense();
}
