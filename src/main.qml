import QtQuick

Rectangle {
    color: myColor
    width: 200
    height: 200
    Text {
        anchors.centerIn: parent
        text: myText
    }
    ListView {
        anchors.fill: parent
        model: myModel
        delegate: Text {
            text: model.display
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            myWidget.setWindowTitle( "Hello from Qml!" );
            myWidget.slotDisplayDialog();
        }
    }
}
