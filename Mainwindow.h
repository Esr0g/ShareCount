#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model/sharecount/Sharecount.h"
#include "Creationcompte.h"
#include "Connecte.h"
#include "Connexion.h"

#include <QDialog>

extern ShareCount count; //------

namespace Ui {
class Mainwindow;
}

class Mainwindow : public QDialog
{
    Q_OBJECT

public:/**
     * @brief Mainwindow constructeur
     * @param sc shareCount objet
     */
    explicit Mainwindow(ShareCount *sc, QWidget *parent = nullptr);
    ~Mainwindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Mainwindow *ui;
    ShareCount *shareCount;
    Creationcompte *creationcomte;
    Connexion *connexion;
};

#endif // MAINWINDOW_H
