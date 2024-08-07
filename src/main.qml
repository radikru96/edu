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
                Transform {
                    id: sphereTransform
                    property real myParam: 0
                    matrix: {
                        var mat = Qt.matrix4x4();
                        mat.rotate( myParam, Qt.vector3d(0, 1, 0) );
                        mat.translate(Qt.vector3d( 24, 0, 0 ));
                        return mat;
                    }
                }
                components: [ sphereMesh, phongMaterial, sphereTransform ]
                NumberAnimation {
                    target: sphereTransform
                    property: "myParam"
                    duration: 10000
                    from: 0
                    to: 360
                    loops: Animation.Infinite
                    running: true
                }
            }
            Entity {
                GoochMaterial {
                    id: goochMaterial
                    diffuse: Qt.rgba( 1, 1, 1, 1 )
                }
                Mesh {
                    id: pyramidMesh
                    source: "qrc:/src/pyramid.obj"
                }
                Transform {
                    id: pyramidTransform
                    property real myRotation: 0
                    matrix: {
                        var mat = Qt.matrix4x4();
                        mat.rotate( myRotation, Qt.vector3d(1, 1, 1) );
                        mat.scale(Qt.vector3d( 10, 10, 10 ));
                        return mat;
                    }
                }
                components: [ pyramidMesh, goochMaterial, pyramidTransform ]
                NumberAnimation {
                    target: pyramidTransform
                    property: "myRotation"
                    duration: 10000
                    from: 0
                    to: 360
                    loops: Animation.Infinite
                    running: true
                }
            }
        }
    }
}
