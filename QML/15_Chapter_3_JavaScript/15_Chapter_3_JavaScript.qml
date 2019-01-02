import QtQuick 1.1
import "factorial.js" as MathFunctions
import "script.js" as MyScript

/*-------------------《1》---------------------*/
//1,集成JavaScript
//2,内联JavaScript


/*-------------------《2》---------------------*/
//1,分离JavaScript
//2,大的JavaScript可以写在一个独立的文件中，通过import语句导入到QML文件中


/*-------------------《3》---------------------*/
//1,在JavaScript中接收QML信号
//2,可以使用信号的connect()函数将它关联到一个JavaScript函数上



Rectangle{

    width: 300
    height: 300

    //内联JavaScript程序
    Item{
            function factorial(a){
                a = parseInt(a);
                if (a <= 0)
                {
                    return 1;
                }
                else
                {
                    return a*factorial(a-1);
                }
            }
    }

    //分离JavaScript程序
    Item{
        MouseArea{
            anchors.fill: parent
            onClicked: console.log(MathFunctions.factorial(10))
        }
    }

    //在JavaScript中接收QML信号
    Item{
        id: item
        width:200; height:200

        MouseArea{
            id: mouseArea
            anchors.fill: parent
        }

        Component.onCompleted: {
            mouseArea.clicked.connect(MyScript.jsFunction)
        }
    }
}






























































































































































































































