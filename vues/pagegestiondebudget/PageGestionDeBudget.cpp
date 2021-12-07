#include "PageGestionDeBudget.h"
#include "ui_pagegestiondebudget.h"
#include <QMessageBox>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <QDoubleSpinBox>
#include <QDateEdit>

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
    ui->depenseListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->participantsLisetView->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
    QString idGroupe = ui->label->text();

    QDialog * d = new QDialog();
    QVBoxLayout * vbox = new QVBoxLayout();
    QLineEdit * lineEditA = new QLineEdit();
    QDoubleSpinBox * doubleSpinBoxA = new QDoubleSpinBox();
    doubleSpinBoxA->setMinimum(0);
    doubleSpinBoxA->setMaximum(10000);
    doubleSpinBoxA->setSingleStep(0.01);
    doubleSpinBoxA->setValue(0);
    doubleSpinBoxA->setDecimals(2);
    QDateEdit * dateEditA = new QDateEdit();
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
    vbox->addWidget(doubleSpinBoxA);
    vbox->addWidget(labelC);
    vbox->addWidget(dateEditA);
    vbox->addWidget(buttonBox);

    d->setAttribute(Qt::WA_QuitOnClose, false); //Empêche la fermeture de la main window
    d->setLayout(vbox);
    d->exec();

    /* On récupère les informations des éditeurs et on les vérifie */
    bool ajouterDepense = false;
    QString titre = lineEditA->text();
    double montant = doubleSpinBoxA->value();
    QString montantTxt;
    QDate date = dateEditA->date();
    QString dateTxt;

    if (montant != 0) {
        ajouterDepense = true;

        std::ostringstream streamObj;
        streamObj<< std::fixed;
        streamObj << std::setprecision(2);
        streamObj << montant;
        montantTxt = QString::fromStdString(streamObj.str());

        if (titre.isEmpty()) {
            titre.append("Depense ");
            titre.append(QString::fromStdString(std::to_string(shareCount->getGroupeActif().nbDepenses() + 1)));
        }

        if (!date.isValid()) {
            ajouterDepense = false;
            QMessageBox::critical(this, "Erreur Ajout Dépense", "Date invalide");
        } else {
            dateTxt = date.toString("dd/MM/yyyy");
        }


    } else {
        ajouterDepense = false;
        QMessageBox::critical(this, "Erreur Ajout Dépense", "Montant invalide");
    }

    if (ajouterDepense) {
        QString user = shareCount->getUtilisateurActif().getIdentifiant();
        Depense dep (shareCount->getGroupeActif().nbDepenses(), user,
                     montant, titre, dateTxt);
        shareCount->ajouterUneDepense(dep);
        miseAJourDepenses();
    }
    setEquilibre();
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
/* affichage des dettes dans une listView, sur l'ensemble des dépenses (qui a avancé plus d'argent que les autres/ qui doit de l'argent) */
void PageGestionDeBudget::setEquilibre(){
    QString participant;
    QStringList list = shareCount->initialiserParticipants(ui->label->text());
    qDebug() << QString::number(list.size());
    for(int i=0; i<list.size();i++){
        participant = list.at(i);
        shareCount->getGroupeActif().ajouterUnpParticipant(shareCount->getUtilisateur(participant)); //ajout des participants dans le groupe actif
    }
    shareCount->getGroupeActif().setDettes(); //initialisation des dettes (calcul des dettes)
    std::map<QString, double> dettes = shareCount->getGroupeActif().getDettes();
    QStringList equilibreDette;
    QString nom;
    QString val;
    for(std::map<QString, double>::iterator it = dettes.begin(); it != dettes.end(); ++it){
        val = QString::number(it->second);
        nom = it->first;
        equilibreDette << nom + " : "+val+" €";
    }

    QStandardItemModel *model = new QStandardItemModel();
    QList<QStandardItem *> list1;
    ui->listView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView_3->setViewMode(QListView::ListMode);

    QRegExp rx(".+-{1}.+"); //Cherche un '-', pour trouver un nombre négatif
    for(int i=0;i<equilibreDette.size();i++){
        list1 << new QStandardItem(equilibreDette.at(i));
    }
    model->appendColumn(list1);

    for(int i=0;i<equilibreDette.size();i++){

        QModelIndex vIndex = model->index(i, 0);
        QMap<int, QVariant> vMap = model->itemData(vIndex);
        if(rx.exactMatch(equilibreDette.at(i))){
            vMap.insert(Qt::BackgroundRole, QVariant(QBrush(Qt::red))); // Si l'utilisateur doit de l'argent au groupe
        }else{
            vMap.insert(Qt::BackgroundRole, QVariant(QBrush(Qt::green))); // Si l'utilisateur a avancé plus d'argent que les autres
        }
        model->setItemData(vIndex, vMap);

    }
    ui->listView_3->setModel(model);
}

void PageGestionDeBudget::miseAJourParticipant() {
    QAbstractItemModel *model = new QStringListModel(shareCount->initialiserParticipants(ui->label->text()));
    ui->participantsLisetView->setModel(model);
}

void PageGestionDeBudget::miseAJourDepenses() {
    QAbstractItemModel *model = new QStringListModel(shareCount->getGroupeActif().depensesToString());
    ui->depenseListView->setModel(model);
}
