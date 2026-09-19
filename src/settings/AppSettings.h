#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QObject>
#include <QStandardPaths>

struct DownloadSettings
{
    QString SavePath =
        QStandardPaths::writableLocation
            (QStandardPaths::DownloadLocation);
};

#endif // APPSETTINGS_H
