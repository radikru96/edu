import QtQuick
// import QtQuick.Dialogs
import QtQuick.Controls
import QtMultimedia
import QtSensors
import Qt.labs.platform

Rectangle {
    id: main
    width: 320
    height: 480
    property int minDim: Math.min(width, height)
    property bool alarm: false

    Image {
        id: infoButton
        anchors.Bottom: main.bottom
        width: main.minDim / 6
        height: width
        source: "qrc:/images/InfoButton.png"
        MouseArea {
            anchors.fill: infoButton
            onClicked: aboutDialog.visible = true
        }
    }
    MessageDialog {
        id: aboutDialog
        visible: false
        title: "Do not touch it for " + Qt.platform.os
        text: "Version 1.0"
    }
    Text {
        anchors {
            top: main.top
            horizontalCenter: main.horizontalCenter
        }
        font.pixelSize: main.minDim / 15
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        text: main.alarm ? "DO NOT TOUCH IT!" : "Put your device\non a smooth surface"
    }
    DelayButton {
        id: btn
        width: main.minDim / 1.5
        height: width
        anchors.centerIn: main
        text: checked ? "Deactivate" : "Tap & Hold<br>to Activate"
        onCheckedChanged: main.alarm = false
    }
}
