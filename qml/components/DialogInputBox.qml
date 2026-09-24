import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import Quantum

Item {
    property string titleText
    property string placeHolderText
    property alias text: input.text
    signal boxTextChanged()

    height: 51
    width: 600

    ColumnLayout {
        anchors.fill: parent

        Text {
            text: titleText

            color: Appearance.textSecondary

            font.pixelSize: 10
            font.family: appFont.name
        }

        Rectangle {
            id: urlBox

            color: input.hovered ? Appearance.inputBackgroundHover : Appearance.background

            radius: 6

            border.color: input.activeFocus ? Appearance.accentFocus : Appearance.accentDim
            border.width: 2

            Layout.preferredHeight: 32
            Layout.fillWidth: true

            Behavior on color {
                ColorAnimation {
                    duration: 200
                }
            }

            Behavior on border.color {
                ColorAnimation {
                    duration: 80
                }
            }

            TextField {
                id: input

                anchors.fill: parent
                anchors.margins: 1

                hoverEnabled: true

                verticalAlignment: Text.AlignVCenter

                placeholderText: placeHolderText

                color: "white"
                font.family: appFont.name
                font.pixelSize: 16

                background: Rectangle {
                    color: "transparent"
                }

                onTextChanged: boxTextChanged()
            }
        }
    }
}
