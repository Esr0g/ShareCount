#ifndef PAGEACCUEIL_H
#define PAGEACCUEIL_H

#include <QWidget>

namespace Ui {
class PageAccueil;
}

class PageAccueil : public QWidget
{
    Q_OBJECT

public:
    explicit PageAccueil(QWidget *parent = nullptr);
    ~PageAccueil();

private:
    Ui::PageAccueil *ui;
};

#endif // PAGEACCUEIL_H
