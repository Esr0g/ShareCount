#ifndef CREATIONCOMPTE_H
#define CREATIONCOMPTE_H

#include <QDialog>

namespace Ui {
class Creationcompte;
}

class Creationcompte : public QDialog
{
    Q_OBJECT

public:
    explicit Creationcompte(QWidget *parent = nullptr);
    ~Creationcompte();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Creationcompte *ui;
};

#endif // CREATIONCOMPTE_H
