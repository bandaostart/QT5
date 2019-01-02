import QtQuick 1.1
/*--------------《1》-----------------*/
//1,import语句并不会包含任何代码到文件中，只是提示QML运行环境怎么来解析在文件中发现的类型引用
//2,在QML文件中的任何类型引用，例如Rectangle Text 都是完全基于import语句进行解析的

/*--------------《2》-----------------*/
//1,QML文件中的每一个id值都必须是唯一的,但是在不同的文件中可以有相同的id值，因为id值是在文件作用域进行解析的

/*--------------《3》-----------------*/
//1,一个QML组件就是一个模版，被QML运行环境解释来创建一个带有一些预定义行为的对象,因为它是一个模板，所以一个独立
//1,的QML组件可以运行多次来产生多个对象，每一个对象都可以称为该组件的实例

/*--------------《4》-----------------*/
//1,这里可以直接使用Button组件，而不需要包含任何的文件及进行任何的设置，项目文件已经将该目录设置为默认的QML文件目录

/*--------------《5》-----------------*/
//1,为组件添加属性：一个属性就是QML组件中的一个值，可以被其他对象读取和修改，例如Rectangle拥有width height color属性
//2,属性可以用于属性绑定，这样属性的值可以使用其他属性的值来自动更新
//3,一个组件中不可以出现相同名称的属性
//4,格式：[default]property <type> <name> [:defaultValue]


/*--------------《6》-----------------*/
//1,QML类型默认值； int 0;  bool false;  double 0.0;  real 0.0;  string ""; url ""; color #000000(黑色); date; variant;


/*--------------《7》-----------------*/
//1,属性别名：[default]property alias<name>:<alias reference>

/*--------------《8》-----------------*/
//1,添加函数  格式：function <name> ([<parameter name>[, ...]]){<body>}
//2,添加信号  格式：signal<name>[([<type><parameter name>[,...]])]
//3,信号和函数关联


/*--------------《9》-----------------*/
//1,集成JavaScript
//2,搜索Intergrating JavaScript关键字


Column{
    spacing: 10

    //QML文件作为组件定义
    Button{text: "Apple"}
    Button{text: "Orange"}
    Button{text: "Pear"}
    Button{text: "Grape"}



    //内联组件；文件中也可以包含内联组件，内联组件使用Component元素声明,他们包含了常规顶级组件的所有特性
    //例如ListView元素使用delegate组件作为模版来实例化列表条目，每一个列表条目都是该组件的一个新的实例
    InlineComponent {
        id: inline
        width:  200
        height: 50
    }



    //添加新属性
    ImageViewer{
        id: viewer
        width:  200
        height: 50

        currentImage: "www.baidu.com"
        Text{
            text :viewer.currentImage
        }
    }
    //添加新string属性
    property string name: "15_Chapter_2_Com"



    //属性别名
    //属性别名对于允许外部对象直接修改和访问一个组件中的子对象是很有用的
    //Button.qml中使用了text别名属性，它关联到了textItem对象的text属性，外外部修改Button组件的text属性，就会
    //直接修改textItem.text的值
    Button {}
    Button {text: "world"}



    //添加函数
    Rectangle{
        id : rect
        width: 100; height: 50
        color: "blue"

        property bool  rectTextFlag: true

        property alias recText: idText.text
        Text {
            id : idText
            color: "white"
            text : "Function Rect"
        }

        function say(sayText){
            recText = sayText
            rectTextFlag = rectTextFlag ? false : true
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {if(rect.rectTextFlag) rect.say("Mouse clicked"); else rect.say("Function Rect")}
        }
    }

    //添加信号
    //向一个组件中添加一个信号，便会自动添加一个信号处理器，它使用“on<SignalName>”来命名
    //这里需要将信号名的第一个字母大写
    Button{
        id : signalButton

        width:100; height:50
        text: "Signal Button"
        property bool  buttonTextFlag: true

        function say(sayText){
            signalButton.text = sayText
            buttonTextFlag = buttonTextFlag ? false : true
        }

        onButtonClicked: {if(signalButton.buttonTextFlag) signalButton.say("Mouse clicked"); else signalButton.say("Signal Button")}
    }
    //带参数信号
    Button{
        id: doubleButton
        width:100; height:50
        text: "Double Click"

        function say(xpos, ypos){
            doubleButton.text = "Xpos=" + xpos + " Ypos=" + ypos;
        }

        onPosButtonClicked: {say(xPos, yPos)}
    }
    //信号和函数相关联
    Button{
        id : connectButton
        width: 100; height: 50
        text: "Connect Button"

        function say(xpos, ypos)
        {
            connectButton.text = "Xpos=" + xpos + " Ypos=" + ypos;
        }

        Component.onCompleted: posButtonClicked.connect(connectButton.say)
    }
}













































































































































