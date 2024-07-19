import QtQuick
import QtQuick.Particles

Rectangle{
    width: 360
    height: 360
    color: "MidnightBlue"
    ParticleSystem {
        anchors.fill: parent
        ImageParticle {
            source: "qrc:/images/MacOS.png"
        }
        Emitter {
            width: parent.width
            height: parent.height
            anchors.bottom: parent.bottom
            lifeSpan: 10000
            sizeVariation: 16
            emitRate: 20
            velocity: AngleDirection {
                angle: 90
                angleVariation: 10
                magnitude: 100
            }
        }
    }
}
