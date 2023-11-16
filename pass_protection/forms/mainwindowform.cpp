#include "mainwindowform.hpp"

#include "../database_manager.hpp"
#include "authorizationform.hpp"
#include "changeform.hpp"
#include "registrationform.hpp"

#include <QMessageBox>

MainWindowForm::MainWindowForm(QWidget *parent) : QMainWindow(parent) {
  ui.setupUi(this);
  connect(ui.login_button, &QPushButton::clicked, this, [this](bool) {
    AuthorizationForm *authorizationForm = new AuthorizationForm(this);
    authorizationForm->show();
  });
  connect(ui.signup_button, &QPushButton::clicked, this, [this](bool) {
    RegistrationForm *registrationForm = new RegistrationForm(this);
    registrationForm->show();
  });
  connect(ui.change_button, &QPushButton::clicked, this, [this](bool) {
    DatabaseManager *databaseManager =
        qApp->property("databaseManager").value<DatabaseManager *>();
    const QString &username = qApp->property("username").value<QString>(),
                  &pass = qApp->property("pass").value<QString>();
    if (!databaseManager->login(username, pass)) {
      QMessageBox::critical(this, "Ошибка", "Вы не авторизованы");
      return;
    }

    ChangeForm *changeForm = new ChangeForm(this);
    changeForm->show();
  });
}