#ifndef CONNEXION_H
#define CONNEXION_H

#include <QDialog>
#include "model/sharecount/Sharecount.h"

namespace Ui {
class Connexion;
}

class Connexion : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Connexion constructeur connexion
     * @param sc shareCount objet
     */
    explicit Connexion(ShareCount *sc, QWidget *parent = nullptr);
    ~Connexion();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Connexion *ui;
    ShareCount shareCount;
};

#endif // CONNEXION_H
