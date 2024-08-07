import QtQuick
import Qt3D.Core
import Qt3D.Render
import Qt3D.Input
import Qt3D.Extras
import QtQuick.Scene3D

Rectangle{
    color: "black"
    Scene3D {
        anchors.fill: parent
        focus: true
        aspects: [ "input", "logic" ]
        cameraAspectRatioMode: Scene3D.AutomaticAspectRatio
        Entity {
            Camera {
                id: camera
                nearPlane: 0.1
                farPlane: 1000.0
                position: Qt.vector3d( 0.0, 0.0, 50.0 )
            }
            FirstPersonCameraController {
                camera: camera
                linearSpeed: 1000.0
                acceleration: 0.1
                deceleration: 1.0
            }
            components: [
            RenderSettings {
                    activeFrameGraph: ForwardRenderer {
                        camera: camera
                        clearColor: "transparent"
                    }
                },
                InputSettings {}
            ]
            DirectionalLight {
                color: "#afafff"
            }
            Entity {
                PhongMaterial {
                    id: phongMaterial
                    ambient: Qt.rgba( 0.3, 0.3, 0.3, 1.0 )
                    diffuse: Qt.rgba( 1, 1, 1, 1 )
                }
                SphereMesh {
                    id: sphereMesh
                    radius: 6
                }
                components: [ sphereMesh, phongMaterial ]
            }
        }
    }
}
