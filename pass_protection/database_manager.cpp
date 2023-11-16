#include "database_manager.hpp"

#include <QDebug>

DatabaseManager::DatabaseManager(const QString &path) {
  database = QSqlDatabase::addDatabase("QSQLITE");
  database.setDatabaseName(path);

  if (!database.open()) {
    qDebug() << "Error: connection with database";
  } else {
    qDebug() << "Database: connection ok";
  }
}