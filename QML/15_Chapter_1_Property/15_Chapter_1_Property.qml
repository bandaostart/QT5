import QtQuick 1.1

/*QML Basic Types查看属性类型*/
/*-----------------------------------QT属性类型-----------------------------------*/
/*action:      action类型拥有的QAction的所有属性                                     */
/*bool:        布尔类型有true和false两个值                                           */
/*color:       一个color就是一个标准的颜色名称加上引号，例如"red"                        */
/*date:        一个date被指定为"YYYY-MM-DD"                                         */
/*double:      一个双精度浮点数                                                      */
/*enumeration: 一个枚举类型包含一组已命名的值                                          */
/*font:        font类型包含QFont的属性 Ctrl+Alt+Space调出工具框                       */
/*int:         整型                                                               */
/*list:        对象是一个列表                                                       */
/*point:       一个point类型，包含了一个x和一个y属性                                   */
/*rect:        一个rect类型包含了x y width height属性                                */
/*size:        一个size类型包含了width和height属性                                    */
/*string:      一个string是一个在引号中的任意格式的文本                                 */
/*time:        一个time被指定为hh:mm:ss                                             */
/*url:         一个URL是一个资源定位器，像一个文件名                                    */
/*variant:     一个variant类型是一个通用的属性类型                                     */
/*vector3d:    一个vector3d类型包含x y 和 z属性                                      */
/*-------------------------------------------------------------------------------*/

/*QML Basic Elements自带一些元素*/
/*------------------------------------QT元素列表-----------------------------------*/
/*itme:                                                                          */
/*Rectangle:                                                                     */
/*image:                                                                         */
/*Text:                                                                          */
/*Textinput:                                                                     */
/*TextEdit:                                                                      */
/*FocusScope:                                                                    */
/*Component:                                                                     */
/*MouseArea:                                                                     */
/*-------------------------------------------------------------------------------*/



//1,属性安全：属性只允许分配一个匹配该属性类型的值，如item属性为real类型，再为其分配一个strng类型是允许的
//2,属性列表
//3,默认属性
//4,分组属性
//5,附加属性
//6,属性绑定

Rectangle {                                                              //Rectangle对象拥有width height 和color属性
    //1,属性类型
    width:  500
    height: 300

    //使用console.log()来输出调试信息,类似的还有console.debug()相当于qDebug()
    onWidthChanged:  console.log("Width has changed to:", width);
    onHeightChanged: console.log("Color has changed to:", height);


    //2,属性列表
    Item{
        children: [
            Item{id: child1},
            Rectangle{id:child2; width:200},
            Text{id:child3}
        ]
    }
    Component.onCompleted: {
        console.log("Width of child rectangle:", children[1].width)
    }


    //3,默认属性
    //每个对象类型都可以指定它的列表中的一项或者一个对象属性作为它的默认属性
    State {
        changes:[
            PropertyChanges{},
            PropertyChanges{}
        ]
    }

    //4,分组属性
    //在某些情况下，属性可以形成一个逻辑组，使用"."或者分组符号来表示
    Text{
        text : "hello"

        //pixelSize bold都是对字体设置的所以他们分为一组
        font.pixelSize: 18
        font.bold:      true
    }

    //5,附加属性:附加属性使用Type.property格式
    Component{
        id: myDelegate
        Text{
            text: "hello world"
            color: ListView.isCurrentItem ? "red" : "blue"
        }
    }
    //delegate:委托
    ListView{
        delegate: myDelegate
    }

    //6,属性绑定：通过绑定可以使用一个JavaScript表达式作为属性，或则可以使用其他属性的值
    //tempRectangle {
    //    width : otherItem.widht
    //    height: ohterItem.height
    //}

    function calculateMyHeight()
    {
        //其它属性只
        return Math.max(this.height, this.width);
    }
    anchors.centerIn: parent
    //表达式
    color: {if (width > 10) "blue"; else "red"}
}














































































