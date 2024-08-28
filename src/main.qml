import QtQuick
import QtPositioning

Rectangle {
    id: mainRect
    width: 320
    height: 480
    color: "black"
    Text {
        id: txt
        anchors.centerIn: parent
        color: "gray"
        PositionSource {
            updateInterval: 1000
            active: Qt.application.state
            onPositionChanged: {
                txt.text = "Latitude" + position.coordinate.latitude
                        + "<br>Longitude" + position.coordinate.longitude
            }
        }
    }
}
