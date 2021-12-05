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
    QDialog * d = new QDialog();
    QVBoxLayout * vbox = new QVBoxLayout();
    QLineEdit * lineEditA = new QLineEdit();
    QLineEdit * lineEditB = new QLineEdit();
    QLineEdit * lineEditC = new QLineEdit();
    QLabel * labelA = new QLabel();
    QLabel * labelB = new QLabel();
    QLabel * labelC = new QLabel();

    labelA->setText("Titre :");
    labelB->setText("Montant :");
    labelC->setText("Date :"); //ou payé par

    QDialogButtonBox * buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    QObject::connect(buttonBox, &QDialogButtonBox::clicked, d, &QDialog::accept);
    QObject::connect(buttonBox, SIGNAL(rejected()), d, SLOT(reject()));

    vbox->addWidget(labelA);
    vbox->addWidget(lineEditA);
    vbox->addWidget(labelB);
    vbox->addWidget(lineEditB);
    vbox->addWidget(labelC);
    vbox->addWidget(lineEditC);
    vbox->addWidget(buttonBox);

    d->setAttribute(Qt::WA_QuitOnClose, false); //Empêche la fermeture de la main window
    d->setLayout(vbox);
    d->exec();

    //QString text = QInputDialog::getText(this, "Nouvelle dépense ", "Montant : ");

    depenses << lineEditA->text();
    QAbstractItemModel *model = new QStringListModel(depenses);
    ui->depenseListView->setModel(model);

}
