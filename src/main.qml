import QtQuick

Rectangle{
    color: "black"
    width: sourceImage.width
    height: sourceImage.height
    ShaderEffect {
        Image {
            id: sourceImage
            // width: sourceWidth
            // height: sourceHeight
            visible: false
            source: "qrc:/images/Linux_old.png"
        }
        width: sourceImage.width
        height: sourceImage.height
        property variant source: sourceImage
        fragmentShader: "
            uniform sampler2D source;
            uniform lowp float qt_Opacity;
            varying highp vec2 qt_TexCoord0;
            void main() {
                gl_FragColor = abs( texture2D( source, qt_TexCoord0 ) * qt_Opacity - 1.0 );
            }"
    }

}
