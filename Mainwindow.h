#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Sharecount.h"
#include <QDialog>

extern ShareCount count; //------

namespace Ui {
class Mainwindow;
}

class Mainwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Mainwindow(ShareCount *sc, QWidget *parent = nullptr);
    ~Mainwindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Mainwindow *ui;
    ShareCount shareCount;
};

#endif // MAINWINDOW_H
