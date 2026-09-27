#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H

#include <QObject>
#include <QColor>
#include <yaml-cpp/yaml.h>
#include <QFile>
#include <QDebug>

class ThemeManager : public QObject
{
    Q_OBJECT

#define THEME_COLOR(name, defaultHex)                                   \
    Q_PROPERTY(QColor name READ name NOTIFY changed)                    \
        QColor name() const { return m_##name; }                            \
        QColor m_##name{QStringLiteral(defaultHex)};

    THEME_COLOR(chromeBackground,    "#000000")
    THEME_COLOR(chromeText,          "#ffffff")
    THEME_COLOR(chromeVersionText,   "#616161")
    THEME_COLOR(windowButtonHover,   "#151515")
    THEME_COLOR(windowButtonPressed, "#101010")
    THEME_COLOR(closeButtonHover,    "#ff0000")
    THEME_COLOR(closeButtonPressed,  "#700000")

    THEME_COLOR(backgroundTop,       "#1F0024")
    THEME_COLOR(backgroundBottom,    "#0E0010")
    THEME_COLOR(background,          "#100019")

    THEME_COLOR(surface,             "#35003D")
    THEME_COLOR(surfaceHover,        "#1B002B")
    THEME_COLOR(surfacePressed,      "#2A0040")
    THEME_COLOR(surfaceSelected,     "#1E0030")
    THEME_COLOR(popupItemHover,      "#2A0040")

    THEME_COLOR(border,              "#35003D")
    THEME_COLOR(borderAccent,        "#AC00FB")

    THEME_COLOR(textPrimary,         "#ffffff")
    THEME_COLOR(textSecondary,       "#656565")
    THEME_COLOR(textMuted,           "#595959")
    THEME_COLOR(textDim,             "#808080")

    THEME_COLOR(accent,              "#AC00FB")
    THEME_COLOR(accentFocus,         "#AE00FF")
    THEME_COLOR(accentDim,           "#480069")

    THEME_COLOR(buttonFill,          "#35003D")
    THEME_COLOR(buttonHover,         "#4A0055")
    THEME_COLOR(buttonPressed,       "#2A0030")
    THEME_COLOR(buttonBorder,        "#AC00FB")
    THEME_COLOR(buttonText,          "#ffffff")

    THEME_COLOR(inputBackground,     "#100019")
    THEME_COLOR(inputBackgroundHover,"#200025")
    THEME_COLOR(inputBorder,         "#480069")
    THEME_COLOR(inputBorderFocus,    "#AE00FF")
    THEME_COLOR(inputText,           "#ffffff")

    THEME_COLOR(progressTrack,       "#1F0024")
    THEME_COLOR(progressFill,        "#480069")
    THEME_COLOR(progressFillComplete,"#209F00")
    THEME_COLOR(progressBorder,      "#AC00FB")

    THEME_COLOR(success,             "#0AC300")
    THEME_COLOR(successBackground,   "#041500")
    THEME_COLOR(danger,              "#C30003")
    THEME_COLOR(dangerBackground,    "#150000")

#undef THEME_COLOR

public:
    explicit ThemeManager(QObject *parent = nullptr);

    Q_INVOKABLE void load(const QString &path);

private:
    // Functions
    QColor readColor(const QString &key, const QColor &fallBack);

    // Types
    YAML::Node m_root;

signals:
    void changed();
};

#endif // THEMEMANAGER_H
