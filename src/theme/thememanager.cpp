#include "thememanager.h"

ThemeManager::ThemeManager(QObject *parent)
    : QObject{parent}
{}

void ThemeManager::load(const QString &path)
{
    QFile file(path);                           // Create a QFile with the included path.

    if (!file.open(QFile::ReadOnly))            // Open the file and handle failures.
    {
        qDebug() << "Failed to open appearance file";
        return;
    }

    try
    {
        m_root = YAML::Load(file                // Load the yaml from the opened file.
                                .readAll()
                                .toStdString());
    }
    catch (YAML::Exception &e)                  // Handle load failures.
    {
        qDebug() << "Invalid yaml " << e.msg;
        return;
    }

    if (!m_root["theme"])                       // Handle theme section not found.
    {
        qDebug() << "No theme section found";
        return;
    }

    // Assign into the macros-generated members
#define READ(name, _ignored) m_##name = readColor(#name, m_##name);
    READ(chromeBackground,    _)
    READ(chromeText,          _)
    READ(chromeVersionText,   _)
    READ(windowButtonHover,   _)
    READ(windowButtonPressed, _)
    READ(closeButtonHover,    _)
    READ(closeButtonPressed,  _)
    READ(backgroundTop,       _)
    READ(backgroundBottom,    _)
    READ(background,          _)
    READ(surface,             _)
    READ(surfaceHover,        _)
    READ(surfacePressed,      _)
    READ(surfaceSelected,     _)
    READ(popupItemHover,      _)
    READ(border,              _)
    READ(borderAccent,        _)
    READ(textPrimary,         _)
    READ(textSecondary,       _)
    READ(textMuted,           _)
    READ(textDim,             _)
    READ(accent,              _)
    READ(accentFocus,         _)
    READ(accentDim,           _)
    READ(buttonFill,          _)
    READ(buttonHover,         _)
    READ(buttonPressed,       _)
    READ(buttonBorder,        _)
    READ(buttonText,          _)
    READ(inputBackground,     _)
    READ(inputBackgroundHover,_)
    READ(inputBorder,         _)
    READ(inputBorderFocus,    _)
    READ(inputText,           _)
    READ(progressTrack,       _)
    READ(progressFill,        _)
    READ(progressFillComplete,_)
    READ(progressBorder,      _)
    READ(success,             _)
    READ(successBackground,   _)
    READ(danger,              _)
    READ(dangerBackground,    _)
#undef READ

}

QColor ThemeManager::readColor(const QString &key, const QColor &fallBack)
{
    const auto node                             // Get the color node by key.
        = m_root["theme"][key.toStdString()];

    const QColor color(                         // Convert the extracted string to a color.
        QString::fromStdString(node.as<std::string>())
        );

    if (!color.isValid())                       // Safe guard if the color is invalid.
    {
        qDebug() << "Invalid color loaded: "    // Print error message.
                 << node.as<std::string>()
                 << " fallback to: "
                 << color.name();

        return fallBack;                        // Return the fallback color.
    }

    return color;                               // Return the loaded color if it's valid.
}