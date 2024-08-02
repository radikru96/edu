import QtQuick
import QtQuick.Controls
import QtQuick.Window
import com.myinc.Ellipse 1.0

Window {
    title: "PaintElement"
    visible: true
    width: 200
    height: 100

    Ellipse {
        anchors.fill: parent
        color: "blue"
    }
}
