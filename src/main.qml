import QtQuick
import QtQuick.Window

Item {
    width: 320
    height: 480
    Text {
        id: txt
        anchors.centerIn: parent
    }
    property int orientation: Screen.primaryOrientation
    onOrientationChanged: {
        if (orientation === Qt.LandscapeOrientation
                || orientation === Qt.InvertedLandscapeOrientation)
            txt.text = "Landscape Orientation"
        else if (orientation === Qt.PortraitOrientation
                 || orientation === Qt.InvertedPortraitOrientation)
            txt.text = "Portrait Orientation"
    }
}
