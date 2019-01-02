import QtQuick 1.1

//QML中所有可视项目都继承自Item,虽然Item本身没有可视化的外观，但是它定义了可视化项目的所有属性
//例如关于位置的x和y属性; 关于大小的width和height属性; 关于布局的anchors相关属性; 关于按键
//处理的Keys属性; visible属性

//1,作为容器
//Item{
//    width: 510; height: 500

//    Image{
//        source: "IMAG0014.gif"
//    }

//    Image{
//        x:0; y:356; width:100; height: 100; source: "IMAG0014.gif"
//    }

//    Image{
//        x:110; y:356; width:100; height:100; source: "IMAG0014.gif"
//    }
//}


//默认属性
//Item中有一个children属性和一个resources属性；前者包含了可见的孩子的列表，后者包含了不可见的资源
//Item{
//    children: [
//        Text{},
//        Rectangle{}
//    ]

//    resources: [
//        Timer{}
//    ]
//}


//透明度
//Item有一个opacity属性，可以用来设置透明度,该属性可以设置为在(0.0~1.0),opacity是一个继承属性，
//可以应用到子项目上
//Item{
//    width: 200; height: 200

//    Rectangle{
//        opacity: 0.5                                    //设置透明度0~1
//        color: "red"
//        width: 100; height: 100

//        Rectangle{
//            color: "blue"
//            x: 50; y: 50; width: 100; height: 100
//        }
//    }
//}



//堆叠顺序
//Item拥有一个Z属性，可以用来设置兄弟项目的堆叠顺序，默认的堆叠顺序为0；
//拥有较大Z属性值的项目会绘制在比其Z属性值小的兄弟项目之上，拥有相同的Z
//属性值的项目会以出现的顺序由下向上绘制，如果项目的Z属性值为负值，那么会被绘制在父项目内容的下面
//Item{

//    width: 300; height: 300

//    Rectangle{
//        z: 1
//        color: "green"
//        width: 100; height: 100
//    }

//    Rectangle{
//        z: 0
//        color: "red"

//        x: 50; y:50; width: 100; height: 100
//    }

//    Rectangle{
//        z: 2
//        color: "blue"
//        x: 100; y: 100; width: 100; height: 100
//    }
//}


//定位子项目和坐标映射
//childAt(real x, real y)函数来返回在点(x, y)处的子项目，如果没有这样的项目则返回null
//而mapFromItem(Item item, real x, real y)函数会将item坐标系统中的点(x, y)映射到该项目的坐标系统上
//返回一个包含映射后的x和y属性的对象，如果item被指定为null值，那么会从根QML视图坐标系统上的点进行映射
//对应的还有一个maptoItem(Item item, real x, real y)函数，从当前项目坐标的(x, y)点映射到item的坐标系统
Item{
    width: 300; height: 300

    Rectangle{
        z: 1

        property string text: idText.text

        color: "green"
        width: 100; height: 100

        Text {
            id: idText

            text: "hello world"
            x: 20; y: 45

            color: "white"
        }
    }

    Rectangle{
        z: 0
        color: "red"

        x: 50; y:50; width: 100; height: 100
    }

    Rectangle{
        z: 2
        color: "blue"
        x: 100; y: 100; width: 100; height: 100
    }
}


















































































































