#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include "appsettings.h"
#include "yaml-cpp/yaml.h"

#include <QObject>
#include <fstream>
#include <QDebug>

class SettingsManager : public QObject
{
    Q_OBJECT
public:
    explicit SettingsManager(QObject *parent = nullptr);

    void save();

signals:

private:
    YAML::Node m_root;

    DownloadSettings m_downloadSettings;
};

#endif // SETTINGSMANAGER_H
