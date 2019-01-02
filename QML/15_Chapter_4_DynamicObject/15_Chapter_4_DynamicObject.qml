import QtQuick 1.1
import "componentCreation.js" as MyScript
/*--------------------《1》---------------------*/
//QML动态对象管理(Dynamic Object Management in QML)关键字
//1,调用Qt.createQmlObject()从QML字符串来创建对象



Rectangle {
    id : appWindow
    width:240; height:200

    //通过Qt.creatQmlObject()创建
    Component.onCompleted: MyScript.createSpriteObjects();

    //通过QML字符串创建
    //var newObject = Qt.createQmlObject: Rectangle{color:"red"; width:20; height:20}, parentItem, "dynamicSnippet1";
}
