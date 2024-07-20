import QtQuick
import QtQml.XmlListModel

XmlListModel {
    source: "qrc:/src/CDs.xml"
    query: "/CDs/CD"
    XmlListModelRole {
        name: "artist";
        elementName: "artist"
    }
    XmlListModelRole {
        name: "album";
        elementName: "album"
    }
    XmlListModelRole {
        name: "year";
        elementName: "year"
    }
    XmlListModelRole {
        name: "cover";
        elementName: "cover"
    }
}
