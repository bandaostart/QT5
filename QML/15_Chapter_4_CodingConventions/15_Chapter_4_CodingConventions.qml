import QtQuick 1.1
//QML编码约定 可以查看QML Coding Conventions关键字
//1,id;
//2,属性声明;
//3,信号声明;
//4，JavaScript函数
//5,对象属性
//6,子对象
//7,状态
//8,状态切换




Rectangle {
    id: photo                                   //id放在第一行

    property bool  thumbnail: false             //属性声明
    property alias image: photoImage.source

    signal clicked                              //信号声明

    function doSomething(x)                     //javaScript函数
    {
        return x+photoImage.width
    }

    x:20; y:20; width:200; height:150           //对象属性
    color: "gray"

    Rectangle                                   //子对象
    {
        id: border

        anchors.centerIn: parent; color: "white"

        Image{id:photoImage; anchors.centerIn: parent}
    }

    states:State                                 //状态
    {
        name: "selected"
        PropertyChanges{target:border; color:"red"}
    }

    transitions: Transition                       //切换
    {
        from: ""; to: "selected"
        ColorAnimation{target:border; duration: 200}
    }


    Rectangle                                     //分组属性
    {
        anchors{left: parent.left; top: parent.top; right: parent.right; leftMargin: 20}
    }

    Text                                          //分组属性书写方式
    {
        text: "hello"
        font{bold: true; italic: true; pixelSize: 20; capitalization: Font.AllUppercase }
    }


    Item                                          //私有属性
    {
        id: component

        width: 40; height: 50

        property real __area: width*height*0.5    //并不是作为外部使用
    }


}



















































































