import QtQuick 1.1

//如果width和height属性没有被指定，那么Image元素自动使用加载的图片大小
//如果指定了Image的大小，那么图片会缩放到这个大小,可以通过设置fillMode属性来改变，它允许图片进行拉伸
//或者平铺
//Image{
////    width: 450; height: 450

//    fillMode: Image.Tile
//    source: "IMAG0010.jpg"
//}







//边界图片BorderImage
//BorderImage元素通过缩放或者平铺图片的各个部分来创建超出图片的边界
//   1    2    3
//
//   4    5    6
//
//   7    8    9
//4个角(1，3， 7，9)
//区域 2 和 8通过horizontalTileMode属性设置的模式进行缩放
//区域 4 和 6通过verticalTileMode属性设置的模式进行缩放
//中间部分5 会结合horizontaltileMode属性和verticalTileMode属性设置的模式进行缩放

//1,将水平方向和垂直方向的平铺模式都设置为拉伸，这样2、8和4、6区域会被垂直拉伸
//BorderImage{
//    width: 180; height: 180
//    border{ left: 30; top: 30; right: 30; bottom: 30}
//    horizontalTileMode: BorderImage.Stretch
//    verticalTileMode: BorderImage.Stretch

//    source: "IMAG0014.gif"
//}

//2,使用平铺方式来显示
//BorderImage{
//    width: 180; height: 180
//    border{ left: 30; top: 30; right: 30; bottom: 30}
//    horizontalTileMode: BorderImage.Repeat
//    verticalTileMode: BorderImage.Repeat

//    source: "IMAG0014.gif"
//}





//动态图片AnimatedImage
//可以用来播放包含了一系列帧的图片动画，比如GIF文件，当前帧和动画总长度等信息可以使用CurrentFrame和FrameCount属性来获取
//可以通过改变playing和paused属性的值来开始、暂停和停止动画
Rectangle{
    width: animatin.width; height: animatin.height+8

    AnimatedImage{
        id: animatin
        source: "IMAG0014.gif"
    }

    Rectangle{
        property int  frames: animatin.frameCount

        width: 4; height: 8

        x:(animatin.width-width)*animatin.currentFrame/frames
        y:animatin.height

        color: "red"
    }
}




























































































