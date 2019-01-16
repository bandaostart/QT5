import QtQuick 1.1

//滚动效果
//QML中Flickable元素，它可以将其子项目设置在一个可以用来拖拽和动弹的界面上，使得子项目的视图可以滚动
//contentHeight contentWidth用来设置拖拽的内容的大小
//<1>
//Flickable{
//    width: 200; height: 200
//    contentWidth: image.width; contentHeight: image.height

//    Image{
//        id: image
//        source: "IMAG0014.gif"
//    }
//}

//clip属性：设置Flickable是否只在一个区域中显示Flickable元素，这是为了不让其在指定区域以外显示
//<2>
//Rectangle{
//    width: 360; height: 360
//    color: "blue"

//    Flickable{
//        width: 200; height: 200
//        contentWidth: image.width; contentHeight: image.height

//        clip: true

//        Image{
//            id: image
//            source: "IMAG0014.gif"
//        }
//    }
//}


//
//<3>
//在Flickable中显示一个滚动条，这可以通过visibleArea属性来实现
//这个属性分别为：visibleArea.xPosition, visibleArea.widthRatio, visibleArea.yPosition, visibleArea.heightRadio
//他们都是只读属性，描述了当前可视区域的位置和大小；大小被定义为当前可视窗口占整个视图的百分比，从0.0~1.0，页面位置一般是从0.0~1.0
//减去大小比，例如yPosition的范围时0.0~1.0-heightRadio
//Rectangle{
//    width: 300; height: 300

//    Flickable{
//        id: flickable
//        width: 300; height: 300

//        contentWidth: image.width; contentHeight: image.height

//        clip: true

//        Image{
//            id: image
//            source: "IMAG0014.gif"
//        }
//    }

//    Rectangle{
//        id: scrollbar

//        anchors.right: flickable.right

//        y: flickable.visibleArea.yPosition*flickable.height
//        width: 10
//        height: flickable.visibleArea.heightRatio*flickable.height

//        color: "black"
//    }
//}






//翻转效果
//Flipable是一个可以明显在其正面和反面之间进行翻转的项目，就像一张卡片
//这是通过同时使用Rotation,State和Transition等元素来产生翻转效果的，front和back属性分别用来保存
//要显示在Flipable项目正面和反面的项目
Flipable{
    id: flipable
    width: 240; height: 240

    property bool flipped: false

    front: Image{
        source: "IMAG0014.gif";
        anchors.centerIn: parent
    }

    back: Image{
        source: "IMAG0014.gif"
        anchors.centerIn: parent
    }

    transform: Rotation{

        id: rotation

        origin.x: flipable.width/2
        origin.y: flipable.height/2
        axis.x: 0; axis.y: 1; axis.z: 0
        angle: 0
    }

    states: State{

        name: "back"
        PropertyChanges {
            target: rotation;
            angle: 180
        }
        when: flipable.flipped
    }

    transitions: Transition {
        NumberAnimation{
            target: rotation;
            property: "angle"
            duration: 4000
        }
    }

    MouseArea{
        anchors.fill: parent
        onClicked: flipable.flipped = ! flipable.flipped
    }
}






















































































































































































