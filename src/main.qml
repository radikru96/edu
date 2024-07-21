import QtQuick
import QtQuick.Controls
import QtQuick.Window

Window {
    visible: true
    width: 150
    height: 150
    Column {
        anchors.centerIn: parent
        Button {
            signal infoClicked( string str )
            objectName: "InfoButton"
            text: "Info"
            onClicked: infoClicked( "Information")
        }
        Button {
            signal quitClicked()
            objectName: "QuitButton"
            text: "Quit"
            onClicked: quitClicked()
        }
    }
}
