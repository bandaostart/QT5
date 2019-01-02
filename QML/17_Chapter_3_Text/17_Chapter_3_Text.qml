import QtQuick 1.1

//可以显示纯文本或者富文本
//Column{
//    Text{
//        text: "Hello World!"
//        font.family: "Helvetica";
//        font.pointSize: 24
//        color: "red"
//    }

//    Text{
//        text: {
//            text: "<b>Hello</b><i>World!</i>"
//        }
//    }
//}



//文本省略
//Text中的elide属性可以设置省略文本的部分内容来适合Text项目的宽度，如果没有对Text明确设置width值，那么elide属性将不起作用
//Column{
//    spacing: 20

//    Text{
//        width: 200

//        text: "使文本在单行中对于超出部分不要进行省略"
//    }

//    Text{
//        width: 200; elide: Text.ElideLeft;

//        text: "使文本在单行中对于超出部分从左边进行省略"
//    }

//    Text{
//        width: 200; elide: Text.ElideMiddle;

//        text: "使文本在单行中对于超出部分从中间进行省略"
//    }

//    Text{
//        width: 200; elide: Text.ElideRight;

//        text: "使文本在单行中对于超出部分从右边进行省略"
//    }
//}



//字体
//font.capitalization：大写策略(Font.MixedCase不改变大小写；Font.AllUppercase全部大写；Font.AllLowercase全部小写；Font.Capitalize将首字母大写)
//font.family:         字体族
//font.italic:         是否斜体
//font.letterSpacing:  字符间距
//font.pixelSize:      字体大小
//font.pointSize:      字体大小
//font.strikeout:      是否有删除线(true false)
//font.underline:      是否有下划线(true false)
//font.weight:         字体重量(Font.light,Font.Normal,Font.DemiBold,Font.Bold,Font.Black)
//font.wordSpacing:    单词间距(正值加大间距，负值减少间距)
//Column{
//    width: 200; height: 200
//    spacing: 10

//    FontLoader{id: fixedFont; name: "Courier"}
//    FontLoader{id: webFont;   source:"http://www.mysite.com/myfont.ttf"}
//    Text{text: "Fixe-size font"; font.family: fixedFont.name}
//    Text{text: "Fancy font"; font.family: webFont.name}
//}





//对齐方式
//horizontalAlignment和verticalAlignment分别用来设置文本在Text项目区域中的水平对齐方式和垂直对齐方式
//Rectangle{
//    width: 200; height: 200; color: "red"

//    Text{
//        width: 200; height: 200

//        horizontalAlignment: Text.AlignHCenter
//        verticalAlignment:   Text.AlignVCenter

//        text: "中心"
//    }
//}



//文本样式
//使用Text的style属性可以设置文本的样式
//Row{
//    Text{font.pointSize: 24; text: "Normal"}
//    Text{font.pointSize: 24; text: "Raised";  style: Text.Raised;  styleColor: "#AAAAAA"}
//    Text{font.pointSize: 24; text: "Outline"; style: Text.Outline; styleColor: "red"}
//    Text{font.pointSize: 24; text: "Sunken";  style: Text.Sunken;  styleColor: "#AAAAAA"}
//}



//文本换行
//Text的wrapMode属性可以实现文本的自动换行，只有明确设置了Text的width属性时换行才会起作用
//Text.NoWrap(默认)：不进行换行
//Text.WordWrap:在单词边界进行换行
//Text.WrapAnyWhere:只要达到边界，则会在任意点进行换行，甚至是在一个单词的中间
//Text.Wrap:如果可能，会尽量在单词边界进行换行，否则，会在任意点换行
Column{
    spacing: 10

    Text{width: 100; font.pointSize: 24; Text.wrapMode: "WordWrap"; text: "Normal"}
}






















































































































































































