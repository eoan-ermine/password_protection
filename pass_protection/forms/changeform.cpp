#include "changeform.hpp"
#include "../database_manager.hpp"
#include "../validators.h"

#include <QMessageBox>

ChangeForm::ChangeForm(QWidget *parent) : QMainWindow(parent) {
  ui.setupUi(this);

  connect(ui.save_button, &QPushButton::clicked, this, [this](bool) {
    const auto &current_pass = ui.current_password_edit->text(),
               &new_pass = ui.new_password_edit->text(),
               &control_pass = ui.control_password_edit->text();

    if (current_pass.isEmpty() || new_pass.isEmpty() ||
        control_pass.isEmpty()) {
      QMessageBox::critical(this, "Ошибка", "Введите все необходимые данные");
      return;
    }

    if (new_pass != control_pass) {
      QMessageBox::critical(this, "Ошибка",
                            "Новый пароль не совпадает с контрольным паролем");
      return;
    }

    if (current_pass == new_pass) {
      QMessageBox::critical(this, "Ошибка",
                            "Новый пароль должен быть отличен от текущего");
      return;
    }

      PassValidator passValidator(new_pass);
      if (!passValidator.validate()) {
          QMessageBox::critical(this, "Сохранение невозможно",
                                passValidator.getErrorMessage());
          return;
      }

      DatabaseManager *databaseManager =
        qApp->property("databaseManager").value<DatabaseManager *>();
    const QString &username = qApp->property("username").value<QString>();

    if (!databaseManager->changePass(username, current_pass, new_pass)) {
      QMessageBox::critical(this, "Ошибка", "Неверный пароль");
      return;
    }

    QMessageBox::information(this, "Успех",
                             "Поздравляю, вы успешно сменили пароль");
    qApp->setProperty("username", QVariant::fromValue(username));
    qApp->setProperty("pass", QVariant::fromValue(new_pass));
    this->close();
  });
}