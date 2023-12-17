#include "utils.hpp"

#include <QStandardPaths>
#include <QDir>

std::filesystem::path getAppFilePath(const char* filename) {
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty())
        qFatal("Cannot determine settings storage location");
    QDir dir{path};
    dir.mkpath(dir.absolutePath());
    QDir::setCurrent(dir.absolutePath());
    auto appFilePath =
            dir.filesystemAbsolutePath() / filename;
    return appFilePath;
}