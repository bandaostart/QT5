import QtQuick 1.1

//动画 QML Animation关键字


//1,动画作为属性值的来源
//一个动画被应用作为属性值源(property value source)，要使用"动画on属性"语法
//这里在Rectangle的x和y属性上应用来PropertyAnimation来使他们从当前值(0)在1000毫秒中使用动画变化到50
//Rectangle一旦加载完成就会开启该动画，
//要指定一个自定义的值而不是使用当前值作为起始值，可以设置PropertyAnimation的from属性，这里的loops属性
//指定为Animation.Infinite表明该动画是无线循环的
//Rectangle{
//    width: 100; height: 100

//    color: "red"

//    PropertyAnimation on x{to: 50; duration: 1000; loops: Animation.Infinite}
//    PropertyAnimation on y{to: 50; duration: 1000; loops: Animation.Infinite}
//}



//2,行为动画
//经常在一个特定的属性值改变时要应用一个动画，在这种情况下可以使用一个Behavior为一个属性改变指定一个默认的动画
//这里Rectangle拥有一个Behavior对象应用到了它的x和y属性，每当这些属性改变，在Behavior中的PropertyAnimation
//对象就会应用到这些属性上，从而使Rectangle使用动画效果移动到一个新的位置
//Item{
//    width: 500; height: 500
//    Rectangle{
//        id: rect
//        width: 100; height: 100
//        color: "red"

//        Behavior on x{PropertyAnimation{duration: 500}}
//        Behavior on y{PropertyAnimation{duration: 500}}
//    }

//    MouseArea{
//        anchors.fill: parent
//        onClicked: {rect.x = mouse.x; rect.y=mouse.y}
//    }
//}




//3,在信号中处理动画
//当MouseArea被单击时，则触发PropertyAnimation，在1000毫秒内使用动画将x和y的属性改变为50
//因为动画没有绑定到一个特定的对象或者属性，所以必须制定target和property属性的值，而且需要使用
//to属性来指定新的x和y的值
//Rectangle{
//    id: rect
//    width: 100; height: 100
//    color: "red"

//    MouseArea{
//        anchors.fill: parent
//        onClicked: PropertyAnimation{target: rect; properties: "x,y"; to: 50; duration: 1000}
//    }
//}



//4，独立动画
//一个独立的动画对象默认是没有运行的，必须使用running属性或者start()和stop()函数来明确地运行它，因为动画没有绑定
//到一个特殊的对象或属性上，所以必须定义target和property属性的值,也需要使用to属性来指定新的x和y的值
//Rectangle{
//    id: rect

//    width: 100; height: 100
//    color: "red"

//    PropertyAnimation{
//        id: animation
//        target: rect
//        properties: "x,y"
//        duration: 1000
//    }

//    MouseArea{
//        anchors.fill: parent
//        onClicked: {
//            animation.to = 50;
//            animation.running = true;
//        }
//    }
//}


//5，切换
//切换用来设置当前状态改变时的动画，要创建一个切换，需要定义一个Transition对象,然后将其添加到项目的transitions属性
//moved状态中的PropertyChanges对象定义了当Rectangle在该状态时其位置应该为(50, 50),当Rectangle改变到moved状态
//时，Transition将被触发，切换的PropertyAnimation将会使用动画将x和y属性改变到他们的新值
//Rectangle{
//    id: rect
//    width: 100; height: 100
//    color: "red"

//    MouseArea{
//        anchors.fill: parent
//        onClicked: rect.state = "moved"
//    }

//    states: State{
//        name: "moved"
//        PropertyChanges{target:rect; x: 50; y:50}
//    }
//    transitions: Transition{
//        PropertyAnimation{properties: "x,y"; duration: 1000}
//    }
//}


//6，属性动画元素
//PropertyAnimation是用来为属性提供动画的最基本的动画元素，可以用来为real,int,color,rect,point,size,Vector3d
//等属性设置动画，被NumberAnimaton, ColorAnimation, RotationAnimation和Vector3dAnimation等元素继承

//<1>，colorAnimation允许颜色值设置from和to属性
//Rectangle{
//    width: 100; height: 100
//    ColorAnimation on color{from: "red"; to: "yellow"; duration: 1000}
//}

//<2>，RotationAnimation允许设定旋转的方向;SmoothedAnimation当目标值改变时在动画中提供一个平滑的变化;
//     SpringAnimation：提供一个像弹簧一样的动画，可以是设置mass damping epsilon等属性
//     ParentAnimation: 用来在改变父项目是产生动画
//     AnchorAnimation: 用来在改变锚时产生动画
//Item{
//    width: 300; height: 300

//    Rectangle{
//        width: 100; height: 100; anchors.centerIn: parent
//        color: "red"

//        RotationAnimation on rotation{
//            to: 360;
//            direction: RotationAnimation.Clockwise
//        }
//    }
//}

//Rectangle{
//    width: 100; height:100
//    color: "red"
//    PropertyAnimation on x{to: 50; duration: 1000; easing.type: Easing.OutBounce}
//    PropertyAnimation on y{to: 50; duration: 1000; easing.type: Easing.OutBounce}
//}



//7,组合动画
//可以使用ParallelAnimation或则SequentialAnimation动画组元素中的一个来实现
//Rectangle{
//    id: rect
//    width: 120; height: 200

//    Image{
//        id: img
//        source: "IMAG0014.gif"
//        anchors.horizontalCenter: parent.horizontalCenter
//        y: 0
//    }

//    SequentialAnimation on y{
//        loops: Animation.Infinite
//        NumberAnimation {
//            to: rect.height-img.height
//            easing.type: Easing.OutBounce; duration: 2000
//        }

//        PauseAnimation {duration: 1000}

//        NumberAnimation{
//            to: 0;
//            easing.type: Easing.OutQuad;
//            duration: 1000
//        }
//    }
//}

Rectangle{
    id: redRect
    width: 100; height: 100
    color: "red"

    MouseArea{
        id: mouseArea; anchors.fill: parent
    }

    states: State{
        name: "pressed"; when: mouseArea.pressed
        PropertyChanges{
            target: redRect
            color: "blue"
            y: mouseArea.mouseY
            width: mouseArea.mouseX
        }
    }

    transitions: Transition{
        SequentialAnimation{
            ColorAnimation{duration: 200}
            PauseAnimation{duration: 100}

            ParallelAnimation{
                NumberAnimation{
                    duration: 500
                    easing.type: Easing.OutBounce
                    targets:redRect
                    properties: "y"
                }


                NumberAnimation{
                    duration: 800
                    easing.type: Easing.InOutQuad
                    targets: redRect
                    properties: "width"
                }
            }
        }
    }
}

































































































































































































