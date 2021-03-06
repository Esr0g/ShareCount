#ifndef PAGEGESTIONDEBUDGET_H
#define PAGEGESTIONDEBUDGET_H

#include "screen/fenetreprincipale/FenetrePrincipale.h"
#include "model/sharecount/ShareCount.h"
#include <QWidget>
#include <QLabel>
#include "model/depense/Depense.h"
#include <QInputDialog>
#include <QStringListModel>
#include <QDialogButtonBox>
#include <QDebug>
#include <QRegExp>
#include <string>

namespace Ui {
class PageGestionDeBudget;
}

class PageGestionDeBudget : public QWidget
{
    Q_OBJECT

public:
    explicit PageGestionDeBudget(QWidget *parent = nullptr);
    explicit PageGestionDeBudget(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc);
    QLabel *getLabelNomGroupe();
    void miseAJourParticipant();
    void miseAJourDepenses();
    void setEquilibre();
    ~PageGestionDeBudget();

private slots:
    void on_ajouterDepenseButton_clicked();
    void on_ajouterParticipantButton_clicked();

    void on_reglerDepense_clicked();

private:
    Ui::PageGestionDeBudget *ui;
    FenetrePrincipale* pwindow;
    ShareCount* shareCount;
    QLabel nomGroupe;
    QStringList depenses;
};

#endif // PAGEGESTIONDEBUDGET_H
