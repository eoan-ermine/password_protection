#include "registrationform.hpp"
#include "../database_manager.hpp"

#include <QMessageBox>

RegistrationForm::RegistrationForm(QWidget *parent) : QMainWindow(parent) {
  ui.setupUi(this);
  connect(ui.save_button, &QPushButton::clicked, this, [this](bool) {
    const auto &username = ui.username_edit->text(),
               &pass = ui.password_edit->text(),
               &lastName = ui.last_name_edit->text(),
               &firstName = ui.name_edit->text(),
               &patronymic = ui.patronymic_edit->text(),
               &birthPlace = ui.birthplace_edit->text(),
               &phone = ui.phone_edit->text();
    const auto &birthDate = ui.birthdate_edit->date();

    if (username.isEmpty() || pass.isEmpty() || lastName.isEmpty() ||
        firstName.isEmpty() || patronymic.isEmpty() || birthDate.isNull() ||
        birthPlace.isEmpty() || phone.isEmpty()) {
      QMessageBox::critical(this, "Сохранение невозможно",
                            "Введите все необходимые данные");
      return;
    }

    DatabaseManager *databaseManager =
        qApp->property("databaseManager").value<DatabaseManager *>();

    if (!databaseManager->createUser(username, pass, lastName, firstName,
                                     patronymic, birthDate, birthPlace,
                                     phone)) {
      QMessageBox::critical(this, "Сохранение невозможно",
                            "Вероятно, username уже занят");
    } else {
      QMessageBox::information(this, "Успех",
                               "Поздравляю, вы успешно зарегистрировались");
      this->close();
    }
  });
}