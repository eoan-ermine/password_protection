#include <QFile>
#include <QFileDevice>
#include <QStandardPaths>
#include <QVariant>
#include <memory>

#include "forms/mainwindowform.hpp"

#include "database_manager.hpp"
#include "utils.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setOrganizationName("eoanermine");
    app.setApplicationName("pass_protection");

    QFile resourcesDatabase{":/pass_protection.database"};
    if (!resourcesDatabase.open(QIODevice::ReadOnly)) {
        qFatal("Can't open resources database");
    }
    std::shared_ptr<DatabaseManager> databaseManager = nullptr;

    auto databasePath = getAppFilePath("pass_protection.database");
    resourcesDatabase.copy(databasePath);
    QFile database{databasePath};
    database.setPermissions(QFileDevice::WriteOwner | QFileDevice::ReadOwner);
    databaseManager =
            std::make_shared<DatabaseManager>("pass_protection.database");
    app.setProperty("databaseManager", QVariant::fromValue(databaseManager));

    app.setProperty("username", QVariant::fromValue(QString()));
    app.setProperty("pass", QVariant::fromValue(QString()));

    MainWindowForm mainwindow;
    mainwindow.show();
    return app.exec();
}