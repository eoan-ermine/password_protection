#include "authorizationform.hpp"
#include "../database_manager.hpp"

#include <QMessageBox>

AuthorizationForm::AuthorizationForm(QWidget *parent) : QMainWindow(parent) {
  ui.setupUi(this);

  connect(ui.login_button, &QPushButton::clicked, this, [this](bool) {
    const auto &username = ui.username_edit->text(),
               &pass = ui.password_edit->text();

    if (username.isEmpty() || pass.isEmpty()) {
      QMessageBox::critical(this, "Вход невозможен",
                            "Введите все необходимые данные");
      return;
    }

    DatabaseManager *databaseManager =
        qApp->property("databaseManager").value<DatabaseManager *>();

    if (!databaseManager->login(username, pass)) {
      QMessageBox::critical(this, "Вход невозможен", "Неверные данные");
    } else {
      QMessageBox::information(this, "Успех",
                               "Поздравляю, вы успешно зашли в аккаунт");
      qApp->setProperty("username", QVariant::fromValue(username));
      qApp->setProperty("pass", QVariant::fromValue(pass));
      this->close();
    }
  });
}