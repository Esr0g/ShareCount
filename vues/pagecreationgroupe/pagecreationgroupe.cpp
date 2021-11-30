#include "pagecreationgroupe.h"
#include "ui_pagecreationgroupe.h"

PageCreationGroupe::PageCreationGroupe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageCreationGroupe)
{
    ui->setupUi(this);
}

PageCreationGroupe::~PageCreationGroupe()
{
    delete ui;
}
