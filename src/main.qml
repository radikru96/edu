import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: wnd
    title: "Image Brightness"
    width: controls.width
    height: controls.height
    visible: true
    Column {
        id: controls
        Image {
            id: img
            source: "image://brightness/Linux_old.png;" + sld.brightnessValue
            width: wnd.width
            height: wnd.height - sld.height - txt.height
            fillMode: Image.PreserveAspectFit
        }
        Slider {
            id: sld
            width: img.width
            value: 0.75
            stepSize: 0.01
            property int brightnessValue: (value * 255 - 127)
        }
        Text {
            id: txt
            width: img.width
            text: "<h1>Brightness:" + sld.brightnessValue + "</h1>"
        }
    }
}
