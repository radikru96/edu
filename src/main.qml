import QtQuick
import QtQuick.Controls
import QtQuick.Window

Window {
    visible: true
    width: buttons.width
    height: buttons.height
    Column {
        anchors.centerIn: parent
        Button {
            signal infoClicked( string str )
            objectName: "InfoButton"
            text: "Info"
            onClicked: infoClicked( "Information")
        }
        Button {
            signal quitClicked( string str )
            objectName: "QuitButton"
            text: "Quit"
            onClicked: quitClicked()
        }
    }
}
