import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: buttons.width
    height: buttons.height
    visible: true
    title: "Buttons"

    Column {
        id: buttons
        CheckBox {
            text: "Check Box"
        }
        DelayButton {
            text: "Delay Button"
        }
        RadioButton {
            text: "Radio Button1"
        }
        RadioButton {
            text: "Radio Button2"
        }
        RoundButton {
            text: "Round Button"
        }
        Switch {
            text: "Switch"
        }
        ToolButton {
            text: "Tool Button"
        }
        RadioButton {
            text: "Radio Button3"
        }
        Button {
            text: "Quit"
            onClicked: Qt.quit()
        }
    }
}
