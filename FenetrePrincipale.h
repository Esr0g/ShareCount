#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QWidget>

namespace Ui {
class FenetrePrincipale;
}

class FenetrePrincipale : public QWidget
{
    Q_OBJECT

public:
    explicit FenetrePrincipale(QWidget *parent = nullptr);
    ~FenetrePrincipale();

private:
    Ui::FenetrePrincipale *ui;
};

#endif // FENETREPRINCIPALE_H
