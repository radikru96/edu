import QtQuick

Rectangle {
    id: mainRect
    width: 320
    height: 480
    color: "black"
    Rectangle {
        id: rect
        color: "white"
        anchors.centerIn: parent
        width: Math.min(mainRect.width, mainRect.height) / 2
        height: width
        PinchArea {
            anchors.fill: rect
            pinch.minimumRotation: -360
            pinch.maximumRotation: 360
            pinch.minimumScale: 0.5
            pinch.maximumScale: 2.0
            onPinchStarted: print("PinchStarted")
            onPinchUpdated: {
                rect.rotation = -pinch.angle
                var nW = rect.width * pinch.scale
                var nMax = Math.min(mainRect.width, mainRect.height)
                var nMin = nMax / 2
                rect.width = nW > nMax ? nMax : nW < nMin ? nMin : nW
                rect.height = rect.width
            }
            onPinchFinished: print("PinchFinished")
        }
    }
}
