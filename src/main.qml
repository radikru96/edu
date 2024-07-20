import QtQuick

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
                    source: cover
                    smooth: true
                }
                Column {
                    Text {color: "white"
                        text: artist
                        font.pointSize: 12
                    }
                    Text {color: "lightblue"
                        text: album
                        font.pointSize: 10
                    }
                    Text {color: "yellow"
                        text: year
                        font.pointSize: 8
                    }
                }
            }
        }
    }
    ListView {
        focus:  true
        anchors.fill: parent
        model: CDs{}
        delegate: delegate
    }
}

