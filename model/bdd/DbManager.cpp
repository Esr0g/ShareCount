#include "DbManager.h"
#include <QFile>
#include <QSqlQuery>
#include <QDebug>

DbManager::DbManager(const QString& path)
{
    sharCountBase = QSqlDatabase::addDatabase("QSQLITE");
    sharCountBase.setDatabaseName(path);

    if (!sharCountBase.open()) {
        qDebug() << "Erreur: connection avec la base de donnée échouée";
    } else {
        qDebug() << "Connection réussie";
    }

    createDataBase();
}

void DbManager::createDataBase() {
    QFile dataBase("../ShareCount/sql/ShareCountDataBase.db");

    if (!dataBase.exists()) {
        QSqlQuery query("CREATE TABLE utilisateurs(id INTEGER PRIMARY KEY, mdp TEXT, mail TEXT");
        query.exec();
        query.prepare("CREATE TABLE groupes(id INTEGER PRIMARY KEY)");
        query.exec();
    }
}


