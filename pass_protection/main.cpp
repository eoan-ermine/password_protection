#include "forms/mainwindowform.hpp"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindowForm mainwindow;
  mainwindow.show();
  return app.exec();
}