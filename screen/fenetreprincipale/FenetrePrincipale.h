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

    /**
     * @brief getThis permet de renvoyer le pointeur de la classe pour pouvoir ajouter des "enfants"
     * @return this
     */
    virtual FenetrePrincipale* getThis();

    /**
     * @brief resizeEvent permet de redimensionner automatiquement la taille de la page lorsque
     * l'utilisateur modifie la taille de la fenêtre
     * @param event
     */
    void resizeEvent(QResizeEvent *event);

    /**
     * @brief setPageActive permet de positionner la page active
     * détruit celle précédente si elle existe
     * @param p page que l'on souhaite afficher
     */
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
