import QtQuick

Rectangle {
    width: 150
    height: 150
    Image {
        source: "qrc:/images/Linux.png"
        anchors.centerIn: parent
        smooth: true
        RotationAnimation on rotation {
            from: 0
            to: 360
            duration: 2000
            loops: Animation.Infinite
            easing.type: Easing.InOutBack
        }
    }
}
