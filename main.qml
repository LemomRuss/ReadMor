import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQml.Models 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
//import QuickIOS 0.1

Window {
    visible: true
    width: Screen.width
    height: Screen.height

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Rectangle {
        property int logoWidth: parent.width/4
        width: logoWidth
        y:parent.height/3
        x:parent.width/2 - logoWidth/2

        Text {
            id: logoView
            anchors.centerIn: parent
            font.pixelSize: 80
            font.family: "Helvetica"
            font.bold: true
            color: "green"
            text: "ReadMore"
        }
        TextField {
            width:logoView.width
            y:logoView.baseline.y + logoView.height + 40
            x:logoView.x
            style: TextFieldStyle {
                textColor: "black"
                background: Rectangle {
                    radius: 2
                    implicitWidth: 100
                    implicitHeight: 24
                    border.color: "#333"
                    border.width: 1
                }
            }
        }
        TextField {
            width:logoView.width
            y:logoView.baseline.y + logoView.height + 40
            x:logoView.x
            style: TextFieldStyle {
                textColor: "black"
                background: Rectangle {
                    radius: 2
                    implicitWidth: 100
                    implicitHeight: 24
                    border.color: "#333"
                    border.width: 1
                }
            }
        }
    }
    StackView {
        id: stackView
        anchors.fill: parent
        // Implements back key navigation
        focus: true
        Keys.onReleased: if (event.key === Qt.Key_Back && stackView.depth > 1) {
                             stackView.pop();
                             event.accepted = true;
                         }

        initialItem: Item {
            width: parent.width
            height: parent.height
            ListView {
                model: pageModel
                anchors.fill: parent
                delegate: AndroidDelegate {
                    text: title
                    onClicked: stackView.push(Qt.resolvedUrl(page))
                }
            }
        }
    }
}

