import QtQuick
import QtQuick.Controls

ApplicationWindow {
    title: "Image Brightness"
    width: controls.width
    height: controls.height
    visible: true
    Column {
        id: controls
        Image {
            id: img
            source: "image://brightness/MacOS.png;" + sld.brightnessValue
        }
        Slider {
            id: sld
            width: img.width
            value: 0.75
            stepSize: 0.01
            property int brightnessValue: (value * 255 - 127)
        }
        Text {
            width: img.width
            text: "<h1>Brightness:" + sld.brightnessValue + "</h1>"
        }
    }
}
