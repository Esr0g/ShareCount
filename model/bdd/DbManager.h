#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QSqlDatabase>

/**
 * @brief The DbManager class qui permet de gérer les entrées et les sorties
 * avec la base de donnée
 */
class DbManager : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief DbManager Constrcteur par défaut
     * @param path de la base de donnée
     */
    explicit DbManager(const QString& path);


private:
    /**
     * @brief createDataBase permet de créer et d'initialiser la base de donnée
     * si le fichier ShareCountDataBase.db n'existe pas
     */
    void createDataBase();

    QSqlDatabase sharCountBase;
};

#endif // DBMANAGER_H
