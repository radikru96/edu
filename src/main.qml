import QtQuick

Item {
    width: 150
    height: 100
    Button {
        anchors.centerIn: parent
        text: "Please, Click me!"
        onClicked: {
            text = "Clicked!"
        }
    }
}
