import QtQuick 1.1

Item{

    id: root

    property  string text: "lable"

    width: 100; height: 30

    Item{
        id: container

        anchors.fill: parent
    }

    Column{
        anchors.centerIn: parent
        spacing: 2

        Text{
            id: label
            text:root.text
        }
    }
}
