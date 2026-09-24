import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Effects
import Quantum

Item {
    id: root

    property int tabHeight: 40
    property int tabWidth: 238
    property string tabText
    property string tabIcon
    property color hoverFillColor: Appearance.surfaceHover
    property color pressedFillColor: Appearance.surfacePressed
    property color normalFillColor: Appearance.background
    property color selectedFillColor: Appearance.surfaceSelected
    property color normalBorderColor: Appearance.surface
    property color selectedBorderColor: Appearance.borderAccent
    property color textSelectedColor: "#FFFFFF"
    property color textNormalColor: Appearance.textSecondary
    property bool isSelected: false
    signal clicked()

    height: tabHeight
    width: tabWidth

    Rectangle {
        id: backgoround

        anchors.fill: parent

        color: mouseArea.pressed ? pressedFillColor : mouseArea.containsMouse ? hoverFillColor : isSelected ? selectedFillColor : normalFillColor

        Behavior on color {
            ColorAnimation {
                duration: 80
            }
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true

            onClicked: root.clicked()
        }

        // Right border
        Rectangle {
            id: border

            anchors.right: parent.right
            anchors.top: parent.top

            height: parent.height
            width: isSelected ? 4 : 2

            color: isSelected ? selectedBorderColor : normalBorderColor
        }

        // Content
        RowLayout {
            anchors.fill: parent

            spacing: 0

            // TabIcon
            Image {
                id: icon
                source: backend.coloredSvg(tabIcon, "white")

                visible: false
            }

            MultiEffect {
                Layout.preferredHeight: 22
                Layout.preferredWidth: 22

                Layout.leftMargin: 10

                source: icon

                brightness: isSelected ? 0 : -0.604
            }

            Item {
                Layout.preferredWidth: 5
            }

            FontLoader {
                id: appFont
                source: "qrc:/qml/assets/fonts/Lexend.ttf"
            }

            Text {
                id: text
                text: tabText

                font.family: appFont.name
                font.pixelSize: 20
                color: isSelected ? textSelectedColor : textNormalColor
            }

            Item {
                Layout.fillWidth: true
            }
        }
    }
}

