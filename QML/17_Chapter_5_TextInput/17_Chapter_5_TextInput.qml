import QtQuick 1.1

//TextInput元素用来显示单行的可编辑的纯文本;对应于QT的QLineEdit
TextInput{
    validator: IntValidator{bottom: 11; top:31;}
    focus: true
}
