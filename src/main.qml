import QtQuick
import "qrc:/src/CDs.js" as CDs

Rectangle{
    id: mainrect
    color:  "gray"
    width: 200
    height: 360
    Component {
        id: delegate
        Item {
            width: mainrect.width
            height: 70
            Row {
                anchors.verticalCenter: parent.verticalCenter
                Image {
                    width: 64
                    height: 64
                    source: modelData.cover
                    smooth: true
                }
                Column {
                    Text {color: "white"
                        text: modelData.artist
                        font.pointSize: 12
                    }
                    Text {color: "lightblue"
                        text: modelData.album
                        font.pointSize: 10
                    }
                    Text {color: "lightGray"
                        text: modelData.year
                        font.pointSize: 8
                    }
                }
            }
        }
    }
    ListView {
        focus:  true
        highlight: Rectangle {
            width: parent.width
            gradient: Gradient{
                orientation: Gradient.Horizontal
                GradientStop {
                    position: 0.50;
                    color: mainrect.color;
                }
                GradientStop {
                    position: 1.00;
                    color: "darkGray";
                }
            }
        }

        anchors.fill: parent
        model: CDs.jsonModel
        delegate: delegate
    }
}

