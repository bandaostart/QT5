import QtQuick 1.1

//Item有Scale和Rotation
//缩放(Scale)、旋转(Rotation)和平移(Translate)
//Topleft    Top      TopRight
//
//Left       Center   Right
//
//BottomLeft Bottom   BottomRight
//

//将红色矩形放大1.6倍进行显示
//1,缩放是以transformOrigin属性指定的点为原点进行的
//Rectangle{
//    color: "blue"
//    width: 100; height: 100

//    Rectangle{
//        color: "green"
//        width: 25; height: 25
//    }

//    Rectangle{
//        color: "red"

//        x: 25; y:25; width:25; height: 25

//        scale: 1.6
//    }
//}

//2,使用TopLeft为原点
//Rectangle{
//    color: "blue"
//    width: 100; height: 100

//    Rectangle{
//        color: "green"
//        width: 25; height: 25
//    }

//    Rectangle{
//        color: "red"

//        x: 25; y:25; width:25; height: 25

//        scale: 1.6
//        transformOrigin: "TopLeft"
//    }
//}

//3,rotation属性来指定项目顺时针旋转的度数，默认值为0，旋转也是以transformorigin属性指定的点为原点进行的
//Rectangle{
//    color: "blue"
//    width: 100; height: 100

//    Rectangle{
//        color: "red"
//        x: 25; y: 25; width: 50; height: 50

//        rotation: 30
//    }
//}



//Item还有一个transform属性，需要指定一个Transform元素的列表，Transform类型有:Rotation Scale Transition
//来实现更高级的设置,其中Rotation提供了坐标轴和原点属性，坐标轴有axis.x axis.y axis.z分别代表X轴，Y轴，Z轴
//原点由origin.x和origin.y来指定,
//1,以Y轴为旋转轴进行了旋转
//Rectangle{
//    width: 100; height: 100
//    color: "blue"

//    transform: Rotation{origin.x: 50; origin.y: 50
//                        axis{x: 0; y: 1; z: 0}
//                        angle: 72
//    }
//}



//Scale中提供origin.x和origin.y属性来设置原点，另外还可以使用xScale和yScale来分别设置X轴和Y轴的比例因子
//就是X轴方向和Y轴方向的缩放值
//Rectangle{
//    width: 100; height: 100
//    color: "blue"

//    Rectangle{
//        width: 50; height: 50; x: 20; y:20
//        color: "red"
//        transform: Scale{origin.x: 25; origin.y: 25; xScale: 3}
//    }
//}



//Translate中提供了x和y属性来分别设置在X轴和Y轴方向的偏移量;在下面的例子中分别将两个矩形在
//Y轴方向进行了向上和向下的偏移
Row{
    Rectangle{
        width: 100; height: 100
        color: "blue"
        transform: Translate{y: 20}
    }

    Rectangle{
        width: 100; height: 100
        color: "red"
        transform: Translate{y: -20}
    }
}
















