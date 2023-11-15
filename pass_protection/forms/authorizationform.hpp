#include "ui_authorization.h"

class AuthorizationForm : public QMainWindow {
  Q_OBJECT
public:
  explicit AuthorizationForm(QWidget *parent = nullptr);

private:
  Ui::Authorization ui;
};