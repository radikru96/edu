import QtQuick
import QtQuick.Dialogs
import QtQuick.Controls
import QtMultimedia
import QtSensors

Rectangle {
    id: main
    width: 320
    height: 480
    property int minDim: Math.min(width, height)
    property bool alarm: false
}
