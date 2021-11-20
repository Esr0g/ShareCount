#ifndef PAGEPRINCIPALE_H
#define PAGEPRINCIPALE_H

#include <QMainWindow>
#include <screen/fenetreprincipale/FenetrePrincipale.h>

namespace Ui {
class PagePrincipale;
}

class PagePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    explicit PagePrincipale(QWidget *parent = nullptr);
    explicit PagePrincipale(QWidget *parent, FenetrePrincipale* fp, ShareCount* sc);
    ~PagePrincipale();

private:
    Ui::PagePrincipale *ui;
    FenetrePrincipale* pwindow;
    ShareCount* shareCount;
};

#endif // PAGEPRINCIPALE_H
