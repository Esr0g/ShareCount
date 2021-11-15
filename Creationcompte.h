#ifndef CREATIONCOMPTE_H
#define CREATIONCOMPTE_H

#include <QDialog>
#include "model/sharecount/Sharecount.h"


namespace Ui {
class Creationcompte;
}

class Creationcompte : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Creationcompte constructeur
     * @param sc shareCount objet
     */
    explicit Creationcompte(ShareCount *sc, QWidget *parent = nullptr);
    ~Creationcompte();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Creationcompte *ui;
    ShareCount shareCount;


};

#endif // CREATIONCOMPTE_H
