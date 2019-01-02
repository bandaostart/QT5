import QtQuick 1.1

Rectangle {
    id: rect
    property alias text: textItem.text

    width : 100; height: 62

    color : "blue"

    signal buttonClicked
    signal posButtonClicked(int xPos, int yPos)

    Text{
        id: textItem
        color: "white"
        text:  "hello"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: rect.buttonClicked()
        onDoubleClicked: rect.posButtonClicked(mouse.x, mouse.y)
    }
}


































