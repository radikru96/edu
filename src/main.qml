import QtQuick
import QtQuick.Particles

Rectangle{
    width: 360
    height: 360
    color: "MidnightBlue"
    Repeater {
        model: [
            "MacOS.jpg", "Linux.jpg", "OS2.jpg", "Windows.jpg",
            "MacOS_old.png", "Linux_old.png", "OS2_old.png", "Windows_old.png",
            "MacOS.png", "Linux.png", "OS2.png", "Windows.png",
        ]
        ParticleSystem {
            width: parent.width
            height: parent.height
            y: -parent.height/2

            ImageParticle {
                source: "qrc:/images/" + modelData + ""
                opacity: 0.2
            }
            Emitter {
                width: parent.width
                height: parent.height
                anchors.bottom: parent.bottom
                lifeSpan: 10000
                sizeVariation: 16
                emitRate: 16383/12/2
                velocity: AngleDirection {
                    angle: 90
                    angleVariation: 10
                    magnitude: 100
                }
            }
            Gravity {
                y: parent.height
                width: parent.width
                height: parent.height
                angle: 90
                magnitude: 250
            }
        }
    }
}
