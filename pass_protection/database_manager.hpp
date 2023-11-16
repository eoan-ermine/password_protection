#include <QSqlDatabase>
#include <QString>

class DatabaseManager {
public:
  DatabaseManager(const QString &path);

private:
  QSqlDatabase database;
};