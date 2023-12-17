#include <QApplication>

#include "forms/mainwindowform.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setOrganizationName("eoanermine");
    app.setApplicationName("pass_protection");

    MainWindowForm mainwindow;
    mainwindow.show();
    return app.exec();
}