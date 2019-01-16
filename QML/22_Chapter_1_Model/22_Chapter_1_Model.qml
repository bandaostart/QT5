import QtQuick 1.1

//QML中的一些视图项目，需要使用数据模型来为其提供数据进行显示，这些项目通常也需要一个委托组件来为模型
//中的每一个条目创建一个实例;模型可以是静态的，也可以进行动态的修改，插入，移除或者移动项目
//参考QML Data Models
//<1>ListModel
//Item{
//    width: 200; height: 250

//    ListModel{
//        id: myModel
//        ListElement{type: "Dog"; age: 8}
//        ListElement{type: "Cat"; age: 5}
//    }

//    Component{
//        id: myDelegate
//        Text{text: type+", "+age}
//    }

//    ListView{
//        anchors.fill: parent
//        model: myModel
//        delegate: myDelegate
//    }

//}


//<2>VisualItemModel
Item{
    width: 100; height: 200

    VisualItemModel{
        id: itemModel
        Rectangle{height: 30; width: 80; color: "red"}
        Rectangle{height: 30; width: 80; color: "green"}
        Rectangle{height: 30; width: 80; color: "blue"}
    }


    ListView{
        anchors.fill: parent
        model: itemModel
    }

}
































































































































































































