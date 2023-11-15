#include "mainwindowform.hpp"

#include "authorizationform.hpp"
#include "changeform.hpp"
#include "registrationform.hpp"

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
    ChangeForm *changeForm = new ChangeForm(this);
    changeForm->show();
  });
}