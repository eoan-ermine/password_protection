#include <QDir>
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
    resourcesDatabase.copy(databasePath);
    DatabaseManager *databaseManager =
        new DatabaseManager("database_pass.database");
    app.setProperty("databaseManager", QVariant::fromValue(databaseManager));
  }

  MainWindowForm mainwindow;
  mainwindow.show();
  return app.exec();
}