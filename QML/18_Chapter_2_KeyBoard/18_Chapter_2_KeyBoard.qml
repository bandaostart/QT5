import QtQuick 1.1
//可以在Qt中参考Keyboard Focus in QML

//onPressed和onReleased
//Rectangle{
//    width: 100; height: 100
//    focus: true

//    Text{
//        id: textID
//        text: "hello world"
//    }

//    Keys.onPressed: {
//        if(event.key == Qt.Key_A)
//        {
//            textID.text = "Key A was pressed"
//            event.accepted = true;
//        }
//        else
//        {
//            textID.text = "Hello world"
//        }
//    }
//}



//KeyNavigation元素，它是一个附加属性，可以用来实现使用方向键或者Tab键来进行项目的导航
//Grid{
//    width: 100; height: 100
//    columns: 2

//    Rectangle{
//        id: topLeft
//        width: 50; height: 50
//        color: focus ? "red" : "lightgray"
//        focus: true

//        KeyNavigation.right: topRight
//        KeyNavigation.down:  bottomLeft
//    }

//    Rectangle{
//        id: topRight
//        width: 50; height: 50
//        color: focus ? "red" : "lightgray"

//        KeyNavigation.left:  topLeft
//        KeyNavigation.down:  bottomRight
//    }

//    Rectangle{
//        id: bottomLeft
//        width: 50; height: 50
//        color: focus ? "red" : "lightgray"

//        KeyNavigation.right:  bottomRight
//        KeyNavigation.up:     topLeft
//    }

//    Rectangle{
//        id: bottomRight
//        width: 50; height: 50
//        color: focus ? "red" : "lightgray"

//        KeyNavigation.left:   bottomLeft
//        KeyNavigation.up:     topRight
//    }
//}


//获取焦点和焦点作用域
//一个项目可以通过设置其focus属性为true来使其获得焦点，一般情况下，使用focus属性就足够了
Rectangle{
    id: widget

    color: "lightsteelblue"; width: 175; height: 25; radius: 10; smooth: true

    Text{
        id: label;
        anchors.centerIn: parent
    }

    focus: true

    Keys.onPressed: {
        if (event.key == Qt.Key_A)
        {
            label.text = "Key A was pressed"
        }
        else if(event.key == Qt.Key_B)
        {
            label.text = "Key B was pressed"
        }
        else if (event.key == Qt.Key_C)
        {
            label.text = "Key C was pressed"
        }
    }

}





















































































































