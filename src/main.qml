import QtQuick
import QtQuick.Controls
import QtMultimedia
import QtSensors
import Qt.labs.platform

Rectangle {
    id: mainRect
    width: 320
    height: 480
    property int minDim: Math.min(width, height)
    property bool alarm: false
    color: "black"
    Item {
        id: infoButton
        anchors.bottom: mainRect.bottom
        width: mainRect.minDim / 6
        height: width
        Image {
            source: "qrc:/media/InfoButton.png"
            visible: true
            anchors.fill: infoButton
        }
        MouseArea {
            anchors.fill: infoButton
            onClicked: aboutDialog.open()
        }
    }

    MessageDialog {
        id: aboutDialog
        text: "Do not touch it for " + Qt.platform.os
        informativeText: "Version " + Qt.application.version
        buttons: MessageDialog.Ok
    }
    Text {
        anchors {
            top: mainRect.top
            horizontalCenter: mainRect.horizontalCenter
        }
        font.pixelSize: mainRect.minDim / 15
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        text: mainRect.alarm ? "DO NOT TOUCH IT!" : "Put your device\non a smooth surface"
        color: "gray"
    }
    DelayButton {
        id: btn
        width: mainRect.minDim / 1.5
        height: width
        anchors.centerIn: mainRect
        text: checked ? "Deactivate" : "Tap & Hold<br>to Activate"
        onCheckedChanged: mainRect.alarm = false
        // background: Rectangle {
        //     color: btn.pressed ? "DarkGray" : "gray"
        // }
    }
    Gyroscope {
        active: btn.checked
        alwaysOn: btn.checked
        // Sensor.axesOrientationMode: Gyroscope.FixedOrientation
        // Sensor.skipDuplicates: true
        onReadingChanged: {
            var movement = Math.max(Math.abs(reading.x), Math.abs(reading.y),
                                    Math.abs(reading.z))
            if (movement > 10 && btn.checked) {
                mainRect.alarm = true
            }
        }
    }
    Timer {
        id: timer
        interval: 250
        repeat: true
        property bool bBlink: false
        onTriggered: {
            mainRect.color = bBlink ? "black" : "darkRed"
            bBlink = !bBlink
        }
        onRunningChanged: {
            if (!running) {
                mainRect.color = "black"
            }
        }
    }
    MediaPlayer {
        id: sound
        source: (assetsPath + "alarm.mp3")
        loops: MediaPlayer.Infinite
        // volume: 1.0
    }
    onAlarmChanged: {
        if (alarm) {
            sound.play()
            timer.start()
        } else {
            sound.stop()
            timer.stop()
        }
    }
}
