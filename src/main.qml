import QtQuick

Rectangle{
    width: 200
    height: 100
    Text {
        x: 20;
        y: 20;
        text: "Move this text<br>(use the cursor - keys)"
        horizontalAlignment: Text.AlignHCenter
        Keys.onPressed: {
            if ( event.key === Qt.Key_Left ) {
                x -= 3;
            }
            else if ( event.key === Qt.Key_Right ) {
                x += 3;
            }
            else if ( event.key === Qt.Key_Down ) {
                y += 3;
            }
            else if ( event.key === Qt.Key_Up ) {
                y -= 3;
            }
            else if ( event.key === Qt.Key_Plus ) {
                font.pixelSize++;
            }
            else if ( event.key === Qt.Key_Minus ) {
                font.pixelSize--;
            }
        }
        focus: true
    }
}
