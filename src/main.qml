import QtQuick

Rectangle{
    width: 300
    height: 300
    color: focus ? "red" : "lightgreen"
    KeyNavigation.tab: childrect
    focus: true
    Rectangle {
        id: childrect
        width: 150
        height: 150
        anchors.centerIn: parent
        color: focus ? "red" : "lightgreen"
        KeyNavigation.tab: parent
        Text {
            anchors.centerIn: parent
            text: "Press TAB"
        }
    }
}
