import QtQuick

Rectangle {
    color: "lightGreen"
    width: 100
    height: 100
    Text {
        objectName: "text"
        anchors.centerIn: parent
        text: "Hello Qml"
        function setFontSize( newSize ) {
            font.pixelSize = newSize
            return font.family + " Size = " + newSize
        }
    }
}
