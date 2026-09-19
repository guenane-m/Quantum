#include "settingsmanager.h"

SettingsManager::SettingsManager(QObject *parent)
    : QObject{parent}
{
    try {
        m_root = YAML::LoadFile("config.yaml");     // Load the file if it already exists.
    }
    catch (YAML::BadFile)
    {
        m_root = YAML::Node(YAML::NodeType::Map);   // If file does not exist, start a fresh document
    }                                               // in memory.
    catch (const YAML::Exception &e)
    {
        qDebug() << "Error opening config.yaml: "   // If an error occurs print the error message.
                 << e.msg;
    }
}

void SettingsManager::load()
{
    // Load Download Settings:
    auto download = m_root["DownloadSettings"];
    if (download["savePath"])               // Check if savePath is available and load it.
        m_downloadSettings.SavePath =
            QString::fromStdString(download["savePath"].as<std::string>());
}

void SettingsManager::save()
{
    // Save Download Settings:
    YAML::Node download;
    download["savePath"] = m_downloadSettings.SavePath
                            .toStdString();

    // Assign each category to the settings root:
    m_root["DownloadSettings"] = download;

    // Write the config to the file:
    std::ofstream fout("config.yaml");
    fout << m_root;
}