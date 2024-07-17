import QtQuick

BorderImage {
    property alias text: txt.text
    signal clicked;
    source: "qrc:/images/Windows.png"
    width: txt.width > txt.height ? txt.width  + 15: txt.height + 15
    height: txt.width > txt.height ? txt.width  + 15: txt.height + 15
    border {
        left: 15; top: 12
        right: 15; bottom: 12
    }
    Text {
        id: txt
        color: "white"
        anchors.centerIn: parent
    }
    MouseArea {
        anchors.fill: parent
        onClicked: parent.clicked();
        onPressed: parent.source = "qrc:/images/Linux.png"
        onReleased: parent.source = "qrc:/images/OS2.png"
    }
}
