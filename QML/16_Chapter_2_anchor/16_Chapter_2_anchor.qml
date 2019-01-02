import QtQuick 1.1

//QML提供一种锚(anchor)的概念来进行项目布局的方法;可以查Anchor-based Layout in QML关键字
//每一个项目都可以认为有一组无形的锚线:left,horizontalCenter,right,top,verticalCenter,baseline,bottom
//这些锚线分别对应了Item元素的anchors.left等属性
//锚系统也允许为一个项目的锚指定边距(margin)和偏移(offset)
//一个项目可以通过leftMargin,rightMargin,topMargin,bottomMargin来独立的指定锚边距
//通常使用anchors.fill来将一个项目充满另一个项目

Rectangle{
    width: 300; height: 300

    Image{
        id: pic;
    }

    Text{
        id: label

        text: "hello world"

        anchors.horizontalCenter: pic.horizontalCenter
        anchors.top: pic.bottom
        anchors.topMargin: 5
    }
}
