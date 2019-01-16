import QtQuick 1.1

Item{
    width: 400; height: 100
    Timer{
        interval: 500; running: true; repeat: true
        onTriggered: time.text = Date().toString()
    }

    Text{
        id: time
    }
}
