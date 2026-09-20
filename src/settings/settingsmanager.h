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

    // Functions:
    void load();
    void save();

    // Properties:
    DownloadSettings m_downloadSettings;

signals:

private:
    YAML::Node m_root;

};

#endif // SETTINGSMANAGER_H
