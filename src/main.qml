import QtQuick

Item {
    width: 360
    height: 360
    Rectangle {
        id: rect
        width: 100
        height: 100
        color: "magenta"
        state: "State1"
        Text {
            anchors.centerIn: parent
            text: "Click Me!"
        }
        MouseArea {
            anchors.fill: rect
            onClicked: rect.state = ( rect.state === "State1" ) ? "State2" : "State1"
        }
        states: [
            State {
                name: "State1"
                PropertyChanges {
                    target: rect
                    x: 0
                    y: 0
                }
            },
            State {
                name: "State2"
                PropertyChanges {
                    target: rect
                    x: 200
                    y: 200
                }
            }
        ]
        transitions:
            Transition {
                from: "*"
                to: "*"
                PropertyAnimation {
                    target: rect
                    properties: "x,y"
                    easing.type: Easing.InCirc
                    duration: 1000
                }
            }
    }
}
