import QtQuick 2.15
import QtQuick.Layouts
import Quantum

Rectangle {
    id: root

    property int progress

    Layout.preferredWidth: 300
    Layout.preferredHeight: 16

    color: Appearance.backgroundTop
    border.color: Appearance.borderAccent
    border.width: 1

    RowLayout {
        anchors.fill: parent
        Rectangle {
            Layout.alignment: Qt.AlignLeft
            Layout.margins: 1

            Layout.preferredWidth: (progress * root.width) / 100 - 2
            Layout.preferredHeight: 14

            color: progress === 100 ? Appearance.progressFillComplete : Appearance.progressFill
        }
    }
}
