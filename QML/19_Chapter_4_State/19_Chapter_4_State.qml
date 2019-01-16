import QtQuick 1.1


//所有Item的对象都有一个默认状态，还可以使用项目的states属性通过添加新的State对象来为其指定附加状态
//每一个状态都有一个在本项目中唯一的名称，默认状态的状态名称为空字符串，要改变一个项目的当前状态，可以
//将state属性设置为要改变到的状态的名称; 可以在Qt帮助中查看QML State关键字

//在下面的例子中Rectangle初始时被放在默认的(0,0)的位置，这里定义了一个附加的moved状态，在这个状态中
//使用了PropertyChanges对象将矩形的位置更改为了(50, 50)
Rectangle{
    id: myRect
    width: 200; height: 200
    color: "red"

    MouseArea{
        anchors.fill: parent
        onClicked: myRect.state = "moved"
    }

    states:[
        State{
            name: "moved"
            PropertyChanges{target: myRect; x: 50; y: 50}
        }
    ]
}











































































































