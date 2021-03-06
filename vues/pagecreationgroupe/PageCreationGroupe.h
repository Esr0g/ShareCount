#ifndef PAGECREATIONGROUPE_H
#define PAGECREATIONGROUPE_H

#include <QWidget>
#include "screen/fenetreprincipale/FenetrePrincipale.h"
#include "model/sharecount/ShareCount.h"
#include <QDockWidget>
#include <QPushButton>
#include <QString>

namespace Ui {
class PageCreationGroupe;
}

class PageCreationGroupe : public QWidget
{
    Q_OBJECT

public:
    explicit PageCreationGroupe(QWidget *parent = nullptr);
    explicit PageCreationGroupe(QWidget *parent, FenetrePrincipale *fp, ShareCount* sc);
    QPushButton *getCreerGroupeButton();
    QString getNomGroupe();
    ~PageCreationGroupe();

private:
    void setConnexion();

private slots:
    void on_CreerGroupe_clicked();

private:
    Ui::PageCreationGroupe *ui;
    FenetrePrincipale* pwindow;
    ShareCount* shareCount;
};

#endif // PAGECREATIONGROUPE_H
