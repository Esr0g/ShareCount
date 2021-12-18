#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QWidget>
#include <QResizeEvent>
#include "model/sharecount/ShareCount.h"

namespace Ui {
class FenetrePrincipale;
}

/**
 * @brief The FenetrePrincipale class, cette classe
 * va permettre de contenir toutes les pages de l'application
 */
class FenetrePrincipale : public QWidget
{
    Q_OBJECT

public:
    explicit FenetrePrincipale(QWidget *parent = nullptr);
    explicit FenetrePrincipale(QWidget *parent, ShareCount* sc);

    virtual FenetrePrincipale* getThis();

    void resizeEvent(QResizeEvent *event);

    void setPageActive(QWidget *p);

    ~FenetrePrincipale();

public slots:
    void deconnexion();

private:
    Ui::FenetrePrincipale *ui;
    QWidget *pageActive;
    ShareCount* shareCount;
};

#endif // FENETREPRINCIPALE_H
