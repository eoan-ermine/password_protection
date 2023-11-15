#include "ui_change.h"

class ChangeForm : public QMainWindow {
  Q_OBJECT
public:
  explicit ChangeForm(QWidget *parent = nullptr);

private:
  Ui::Change ui;
};