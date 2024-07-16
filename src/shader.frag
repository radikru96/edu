// #version 440
// uniform sampler2D qt_Texture0;
// varying vec4 qt_TexCoord0;

// void main(void)
// {
//     gl_FragColor = texture2D(qt_Texture0, qt_TexCoord0.st);
// }

// layout( binding = 1 ) uniform sampler2D source;
// precision mediump int;
// precision highp float;
// uniform lowp float qt_Opacity;
// varying highp vec2 qt_TexCoord0;
// void main( void ) {
//     gl_FragColor = abs(texture2D(source, qt_TexCoord0) * qt_Opacity - 1.0);
// }

#version 440

layout(location = 0) in vec2 v_texcoord;
layout(location = 0) out vec4 fragColor;
layout(binding = 1) uniform sampler2D tex;

layout(std140, binding = 0) uniform buf {
    float uAlpha;
};

void main()
{
    vec4 c = texture(tex, v_texcoord);
    fragColor = vec4(c.rgb, uAlpha);
}
