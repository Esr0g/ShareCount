#ifndef CONNECTE_H
#define CONNECTE_H

#include <QDialog>

namespace Ui {
class Connecte;
}

class Connecte : public QDialog
{
    Q_OBJECT

public:
    explicit Connecte(QWidget *parent = nullptr);
    ~Connecte();

private:
    Ui::Connecte *ui;
};

#endif // CONNECTE_H