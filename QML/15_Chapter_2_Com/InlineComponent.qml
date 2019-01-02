import QtQuick 1.1

//内联组件
Rectangle{
    width  :240
    height :320

    ListView{
        anchors.fill: parent
        //model: contactModel
        delegate: Component{
            Text{
                text:modelData.firstName + " " + modelData.lastName
            }
        }

    }
}














































































































