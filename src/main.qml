import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import com.myinc.Calculation 1.0

ApplicationWindow {
    title: "Factorial Calculation"
    width: 250
    height: 80
    visible: true

    Calculation {
        id: calc
    }

    ColumnLayout {
        RowLayout {
            SpinBox {
                id: sbx
                value: 0
            }
            Text {
                text: "Result:" + calc.factorial(sbx.value)
            }
        }
        RowLayout {
            SpinBox {
                value: 0
                onValueChanged: calc.input = value
            }
            Text {
                text: "Result:" + calc.result
            }
        }
    }
}
