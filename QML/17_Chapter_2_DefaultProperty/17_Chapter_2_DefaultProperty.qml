import QtQuick 1.1

CustomButton{
    anchors.centerIn: parent
    width:  30
    height: 20

    text: "Hello, the world!"

    content:[
        Rectangle{ anchors.fill: parent ; color:"red"}
    ]
}

