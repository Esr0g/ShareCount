#ifndef GROUPE_H
#define GROUPE_H
#include <QString>

class Groupe
{
public:
    Groupe();

    void setIdentifiant(const QString& id);

    QString getIdentifiant() const;

private:
    QString identifiant;
};

#endif // GROUPE_H
