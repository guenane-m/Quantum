#include "settingsmanager.h"

SettingsManager::SettingsManager(QObject *parent)
    : QObject{parent}
    , m_root(YAML::LoadFile("config.yaml"))
{}

void SettingsManager::save()
{
    // Save Download Settings:
    YAML::Node download;
    download["SavePath"] = m_downloadSettings.SavePath
                            .toStdString();

    // Assign each category to the settings root:
    m_root["DownloadSettings"] = download;

    // Write the config to the file:
    std::ofstream fout("config.yaml");
    fout << m_root;
}