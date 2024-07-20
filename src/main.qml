import QtQuick

Rectangle{
    id: mainrect
    color:  "gray"
    width: 380
    height: 420
    Component {
        id: delegate
        Item {
            width: 120
            height: 120
            Column {
                anchors.centerIn: parent
                Image {
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: 64
                    height: 64
                    source: cover
                    smooth: true
                }
                Text {color: "white"
                    text: artist
                    font.pointSize: 12
                }
                Text {color: "lightblue"
                    text: album
                    font.pointSize: 10
                }
                Text {color: "lightGray"
                    text: year
                    font.pointSize: 8
                }
            }
        }
    }
    GridView {
        cellHeight: 120
        cellWidth: 120
        focus:  true
        highlight: Rectangle {
            width: parent.width
            gradient: Gradient {
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
        model: CDs{}
        delegate: delegate
    }
}

