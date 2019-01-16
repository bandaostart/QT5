// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QtQuick 1.0

Rectangle {
    id: page
    width: 360
    height: 360
    color: "#343434"
    Rectangle {
        id: topLeftRect
        x: 10
        y: 20
        width: 64
        height: 64
        color: "#00000000"
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 20
        border.color: "#808080"

        MouseArea {
            id: mousearea1
            anchors.fill: parent
            onClicked: {
                Qt.quit();
            }
        }
    }

    Image {
        id: icon
        x: 10
        y: 20
        source: "qt-logo.png"
    }
}
