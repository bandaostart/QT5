import QtQuick 1.1

//<1> ListView
//ListView可以显示一个水平或者垂直放置条目的条目列表，ListView拥有一个模型model属性，用来定义要显示的数据
//还有一个委托delegate属性，用来定义数据显示的方式；ListView默认具有谈动效果，因为它继承自Flickable项目
//Rectangle{

//    width: 180; height: 200

//    Component{
//        id: contactDelegate

//        Item{
//            width: 180; height: 40
//            Column{
//                Text{text: "<b>Name:</b>"+name}
//                Text{text: "<b>Number:</b>"+number}
//            }
//        }
//    }

//    ListView{
//        anchors.fill: parent
//        model: ContactModel{}
//        delegate: contactDelegate
//        highlight: Rectangle{color: "lightsteelblue"; radius: 5}
//        focus: true
//    }
//}


//ListView{
//    width: 180; height: 200

//    Component{
//        id: contactsDelegate

//        Rectangle{
//            id: wrapper
//            width: 180
//            height: contactInfo.height
//            color: ListView.isCurrentItem ? "black" : "red"

//            Text{
//                id: contactInfo
//                text: name+":"+ number
//                color: wrapper.ListView.isCurrentItem ? "red" : "black"
//            }
//        }
//    }

//    model: ContactModel{}
//    delegate: contactsDelegate
//    focus: true
//}


//<1> GridView
//GridView：是将条目排列成网格
//Rectangle{
//    width: 300; height: 400
//    color: "white"

//    ListModel{
//        id: appModel

//        ListElement{name: "Music1"; icon: "xbee_loading1.png"}
//        ListElement{name: "Music2"; icon: "xbee_loading2.png"}
//        ListElement{name: "Music3"; icon: "xbee_loading3.png"}
//        ListElement{name: "Music4"; icon: "xbee_loading4.png"}
//        ListElement{name: "Music4"; icon: "xbee_loading5.png"}
//        ListElement{name: "Music4"; icon: "xbee_loading6.png"}
//        ListElement{name: "Music5"; icon: "xbee_loading7.png"}
//    }

//    Component{
//        id: appDelegate

//        Item{
//            width: 100; height: 100
//            Image{
//                id: myIcon
//                y: 20; anchors.horizontalCenter: parent.horizontalCenter
//                source: icon
//            }

//            Text{
//                anchors{
//                    top: myIcon.bottom
//                    horizontalCenter: parent.horizontalCenter
//                }
//                text: name
//            }
//        }
//    }

//    Component{
//        id: appHightlight
//        Rectangle{
//            width: 80; height: 80
//            color: "lightsteelblue"
//        }
//    }

//    GridView{
//        anchors.fill: parent
//        cellWidth: 100; cellHeight: 100

//        highlight: appHightlight
//        focus: true
//        model: appModel
//        delegate: appDelegate
//    }
//}


//<3>PathView
Rectangle{
    width: 400; height: 240
    color: "white"

    ListModel{
        id: appModel

        ListElement{name: "Music1"; icon: "xbee_loading1.png"}
        ListElement{name: "Music2"; icon: "xbee_loading2.png"}
        ListElement{name: "Music3"; icon: "xbee_loading3.png"}
        ListElement{name: "Music4"; icon: "xbee_loading4.png"}
        ListElement{name: "Music4"; icon: "xbee_loading5.png"}
        ListElement{name: "Music4"; icon: "xbee_loading6.png"}
        ListElement{name: "Music5"; icon: "xbee_loading7.png"}
    }

    Component{
        id: appDelegate

        Item{
            width: 100; height: 100
            scale: PathView.iconScale

            Image{
                id: myIcon
                y: 20; anchors.horizontalCenter: parent.horizontalCenter
                source: icon
                smooth: true
            }

            Text{
                anchors{top: myIcon.bottom; horizontalCenter: parent.horizontalCenter}
                text: name
                smooth: true
            }

            MouseArea{
                anchors.fill: parent
                onClicked: view.currentIndex = index

            }
        }
    }

    Component{
        id: appHighlight
        Rectangle{width: 80; height: 80; color: "lightsteelblue"}
    }

    PathView{
        id: view
        anchors.fill: parent

        highlight: appHighlight

        preferredHighlightBegin: 0.5
        preferredHighlightEnd: 0.5

        focus: true

        model: appModel

        delegate: appDelegate

        path: Path{
            startX: 10
            startY: 50

            PathAttribute{name: "iconScale"; value: 0.5}
            PathQuad{x: 200; y: 150; controlX: 50; controlY: 200}
            PathAttribute{name: "iconScale"; value: 1.0}
            PathQuad{x: 390; y: 50; controlX: 350; controlY: 200}
            PathAttribute{name: "iconScale"; value: 0.5}
        }
    }
}































































































