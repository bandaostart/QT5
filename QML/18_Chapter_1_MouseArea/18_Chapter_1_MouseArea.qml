import QtQuick 1.1



//MouseArea是一个不可见的项目，通常用来和一个可见的项目配合使用来为其提供鼠标处理
//鼠标处理的逻辑可以包含在一个MouseArea项目中;具体鼠标操作可看详细的说明
//Rectangle{
//    width: 100; height: 100
//    color: "green"

//    MouseArea{
//        anchors.fill: parent
//        onClicked: {parent.color = "red"}
//        onDoubleClicked: {parent.color = "green"}
//    }
//}


//MouseEvent
//在MouseEvent对象中，可以通过x和y属性获取鼠标的位置；通过button属性可以获取按下的按键;
//通过modifiers属性可以获取按下的键盘修饰符
//Rectangle{
//    width: 100; height: 100
//    color: "green"

//    MouseArea{
//        anchors.fill: parent

//        acceptedButtons: Qt.LeftButton | Qt.RightButton

//        onClicked: {
//            if (mouse.button == Qt.RightButton)
//            {
//                parent.color = "blue"
//            }
//            else
//            {
//                if ((mouse.button == Qt.LeftButton) && (mouse.modifiers & Qt.ShiftModifier))
//                {
//                    parent.color = "green"
//                }
//                else
//                {
//                    parent.color = "red";
//                }
//            }
//        }
//    }
//}


//拖拽
//drag.target属性用来指定拖动的项目的id; drag.active属性获取项目当前是否正在被拖动的信息
//drag.axis属性用来指定属性拖动的方向,可以是水平方向(drag.XAxis)，垂直方向(Drag.YAxis)
Rectangle{
    id: container

    width: 600; height: 200

    Rectangle{
        id: rect
        width: 50; height: 50
        color: "red"
        opacity: (600.0-rect.x)/600

        MouseArea{
            anchors.fill: parent

            drag.target: rect
            drag.axis: Drag.XAxis
            drag.minimumX: 0
            drag.maximumX: container.width-rect.width
        }
    }

}













































































































