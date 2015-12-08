import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQml.Models 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import "../qml"
////import QuickIOS 0.1

Window {
    visible: true
    width: Screen.width
    height: Screen.height
    StackView {
        id: stack
        focus: true
        anchors.fill:parent
        initialItem: (Qt.resolvedUrl("login.qml"))
    }


//    MouseArea {
//        anchors.fill: parent
//        onClicked: {
//            Qt.quit();
//        }
//    }



}


