var component;
var sprite;

function createSpriteObjects()
{
    //调用函数创建一个组件
    component = Qt.createComponent("Sprite.qml");

    //有了component就可以调用它的createObject()函数来创建该组件的一个实例
    //createObject()函数需要指定新对象的父对象,这个函数需要指定新对象的父对象，因为图形项目没有父对象是无法显示在场景上的
    sprite = component.createObject(appWindow);

    if (sprite == null)
    {

    }
    else
    {
        sprite.x = 100;
        sprite.y = 100;
    }
}









































