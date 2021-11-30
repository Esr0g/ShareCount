#ifndef PAGECREATIONGROUPE_H
#define PAGECREATIONGROUPE_H

#include <QWidget>

namespace Ui {
class PageCreationGroupe;
}

class PageCreationGroupe : public QWidget
{
    Q_OBJECT

public:
    explicit PageCreationGroupe(QWidget *parent = nullptr);
    ~PageCreationGroupe();

private:
    Ui::PageCreationGroupe *ui;
};

#endif // PAGECREATIONGROUPE_H
