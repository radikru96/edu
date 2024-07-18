import QtQuick

Rectangle {
    id: rect
    width: 360
    height: 360
    Image {
        id: img
        source: "qrc:/images/Windows.png"
        x: 10
        y: 10
        smooth: true
        Text {
            anchors.verticalCenter: img.verticalCenter
            anchors.top: img.bottom
            text: "Move the mouse!"
        }
        Behavior on x {
            NumberAnimation {
                duration: 1000
                easing.type: Easing.OutBounce
            }
        }
        Behavior on y {
            NumberAnimation {
                duration: 1000
                easing.type: Easing.OutBounce
            }
        }
    }
    MouseArea {
        anchors.fill: rect
        hoverEnabled: true
        onMouseXChanged: img.x = mouseX
        onMouseYChanged: img.y = mouseY
    }
}
