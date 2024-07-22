import QtQuick

Rectangle {
    id: root
    objectName: "root"
    color: "black"
    width: 200
    height: 200
    onColorChanged: {
        text.text = myText;
        listView.model = myModel;
    }

    Text {
        id: text
        anchors.centerIn: parent
        text: ""
    }
    ListView {
        id: listView
        anchors.fill: parent
        model: null
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
