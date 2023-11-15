#include "ui_mainwindow.h"

class MainWindowForm : public QMainWindow {
  Q_OBJECT
public:
  explicit MainWindowForm(QWidget *parent = nullptr);

private:
  Ui::MainWindow ui;
};