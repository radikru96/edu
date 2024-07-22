import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import com.myinc.Calculation 1.0

ApplicationWindow {
    title: "Factorial Calculation"
    width: 250
    height: 40
    visible: true

    Calculation {
        input: sbx.value
        onResultValueChanged: txt.text = "Result:" + result
    }

    RowLayout {
        SpinBox {
            id: sbx
            value: 0
        }
        Text {
            id: txt
        }
    }
}
