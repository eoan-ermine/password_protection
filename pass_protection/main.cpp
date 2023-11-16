#include <QDir>
#include <QFile>
#include <QFileDevice>
#include <QStandardPaths>
#include <QVariant>

#include "forms/mainwindowform.hpp"

#include "database_manager.hpp"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  app.setOrganizationName("eoanermine");
  app.setApplicationName("pass_protection");

  QFile resourcesDatabase{":/pass_protection.database"};
  if (!resourcesDatabase.open(QIODevice::ReadOnly)) {
    qFatal("Can't open resources database");
  }

  auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
  if (path.isEmpty())
    qFatal("Cannot determine settings storage location");
  QDir dir{path};
  if (dir.mkpath(dir.absolutePath()) && QDir::setCurrent(dir.absolutePath())) {
    qDebug() << "database in" << QDir::currentPath();
    auto databasePath =
        dir.filesystemAbsolutePath() / "pass_protection.database";
    QFile database{databasePath};
    database.setPermissions(QFileDevice::WriteOwner | QFileDevice::ReadOwner);
    resourcesDatabase.copy(databasePath);
    DatabaseManager *databaseManager =
        new DatabaseManager("pass_protection.database");
    app.setProperty("databaseManager", QVariant::fromValue(databaseManager));
  }

  app.setProperty("username", QVariant::fromValue(QString()));
  app.setProperty("pass", QVariant::fromValue(QString()));

  MainWindowForm mainwindow;
  mainwindow.show();
  return app.exec();
}