import QtQuick

Rectangle {
    width: img.width
    height: 300 + img.height + txt.height
    Image {
        id: img
        source: "qrc:/images/Windows.png"
        smooth: true
        Text {
            id: txt
            anchors.horizontalCenter: img.horizontalCenter
            anchors.top: img.bottom
            text: "Click me!"
        }
        MouseArea {
            anchors.fill: img
            onClicked: anim.running = true
        }
        SequentialAnimation {
            id: anim
            NumberAnimation {
                target: img
                from: 20;
                to: 300;
                properties: "y"
                easing.type: Easing.OutBounce
                duration: 1000
            }
            RotationAnimation {
                target: img
                from: 0;
                to: 360;
                properties: "rotation"
                direction: RotationAnimation.Clockwise
                duration: 1000
            }
            PauseAnimation {
                duration: 500
            }
            NumberAnimation {
                target: img
                from: 300;
                to: 20;
                properties: "y"
                easing.type: Easing.OutBack
                duration: 1000
            }
        }
    }
}
