#include <QDate>
#include <QSqlDatabase>
#include <QString>

class DatabaseManager {
public:
  DatabaseManager(const QString &path);

  bool createUser(const QString &username, const QString &pass,
                  const QString &lastName, const QString &firstName,
                  const QString &patronymic, const QDate &birthDate,
                  const QString &birthPlace, const QString &phone);

  bool changePass(const QString &username, const QString &pass,
                  const QString &lastName, const QString &firstName,
                  const QString &patronymic, const QDate &birthDate,
                  const QString &birthPlace, const QString &phone);

  bool login(const QString &username, const QString &pass);

private:
  QSqlDatabase database;
};