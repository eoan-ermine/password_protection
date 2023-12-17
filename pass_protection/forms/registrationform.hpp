#pragma once

#include "ui_registration.h"

class RegistrationForm : public QMainWindow {
  Q_OBJECT
public:
  explicit RegistrationForm(QWidget *parent = nullptr);

private:
  Ui::Registration ui;
};