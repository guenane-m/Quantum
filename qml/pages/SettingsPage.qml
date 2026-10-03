import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Dialogs
import Quantum
import "../components"
import "../js/Helper.js" as Helper

Item {
    id: root

    Flickable {
        anchors.fill: parent
        anchors.margins: 10
        contentHeight: column.implicitHeight
        clip: true

        ColumnLayout {
            id: column

            width: parent.width
            spacing: 10

            SettingsBox {
                title: "Download Settings"
                Layout.fillWidth: true

                SettingRow {
                    title: "Default download save location"

                    FolderDialog {
                        id: downloadLocDialog

                        title: "Select download location"
                        currentFolder: Helper.formatFilePaths(backend.savePath)

                        onAccepted: {
                            backend.savePath = Helper.formatFilePaths(selectedFolder)
                        }
                    }

                    UiButton {
                        buttonHeight: 32
                        buttonWidth: 130
                        buttonText: "Browse"
                        buttonIcon: "qrc:/qml/assets/icons/folder.svg"

                        onClicked: downloadLocDialog.open()
                    }
                }

                SettingRow {
                    title: "Clear database"

                    UiButton {
                        buttonHeight: 32
                        buttonWidth: 130

                        buttonText: "Clear"
                        buttonIcon: "qrc:/qml/assets/icons/reset.svg"

                        onClicked: {
                            backend.clearDatabase()
                        }
                    }
                }
            }

            SettingsBox {
                title: "Appearance Settings"
                Layout.fillWidth: true

                SettingRow {
                    title: "Change theme configuration file"

                    FileDialog {
                        id: themeFileDialog

                        title: "Select theme configuration file"

                        nameFilters: ["YAML files (*.yaml)"]
                        currentFolder: Helper.formatFilePaths(backend.savePath)

                        onAccepted: {
                            backend.setTheme(Helper.formatFilePaths(selectedFile))
                        }
                    }

                    UiButton {
                        buttonHeight: 32
                        buttonWidth: 130
                        buttonText: "Browse"
                        buttonIcon: "qrc:/qml/assets/icons/folder.svg"

                        onClicked: themeFileDialog.open()
                    }
                }
            }
        }
    }
}
