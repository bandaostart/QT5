import QtQuick 1.1
//查看例程Text Selection example

//TextEdit{
//    width: 240

//    text: "<b>Hello</b><i>World!</i>"

//    font.family: "Helvetica"
//    font.pointSize: 20

//    color: "blue"

//    focus: true
//}


//focus设置为true，这样可以是TextEdit项目来接收键盘焦点,TextEdit没有为用户界面提供滚动，光标跟随或者
//其他的行为，一般是使用Flickable元素来提供滚动实现光标跟随

Flickable{
    id: flick

    width: 300; height: 200

    contentWidth: edit.paintedWidth
    contentHeight: edit.paintedHeight
    clip: true

    function ensureVisile(r)
    {
        if (contentX >= r.x)
        {
            contentX = r.x;
        }
        else
        {
            if (contentX+width <= r.x+r.width)
            {
                contentX = r.x+r.width-width;
            }
        }

        if (contentY >= r.y)
        {
            contentY = r.y
        }
        else
        {
            if (contentY+height <= r.y+r.height)
            {
                contentY = r.y+r.height-height;
            }
        }
    }

    TextEdit
    {
        id: edit

        color: "blue"
        font.pointSize: 20

        width:  flick.width
        height: flick.height
        focus:  true
        wrapMode: TextEdit.Wrap
        onCursorRectangleChanged: flick.ensureVisile(cursorRectangle)
    }

}









































































































































































