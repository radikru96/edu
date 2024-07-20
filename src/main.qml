import QtQuick

Rectangle{
    id: mainrect
    color:  "gray"
    width: 450
    height: 170
    Component {
        id: delegate
        Item {
            width: item.width
            height: item.height
            Column {
                id: item
                Image {
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
    Path {
        id: itemsPath
        startX: 0
        startY: 80
        PathLine {
            x: 500
            y: 80
        }
    }
    PathView {
        id: itemsView
        anchors.fill: parent
        model: CDs{}
        delegate: delegate
        path: itemsPath
        pathItemCount: 4
    }
}

