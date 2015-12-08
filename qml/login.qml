import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQml.Models 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
Item {
    id:page
    property real ratio: width / 320 < height / 440 ? width / 320 : height / 440
    property int elementSpacing: 20 * ratio
    Rectangle {
        id:logoRect
        width: 300 * ratio
        height: 80 * ratio
        anchors {
            verticalCenter: parent
            leftMargin: page.width /100
            top: parent.top
            topMargin: page.height / 48
            bottomMargin: page.height / 20
            rightMargin: page.width /100
        }
//        anchors {horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter}
        Text {
            id: logoView
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            anchors.centerIn: parent
            font.pixelSize: 80
            fontSizeMode: Text.Fit
            font.family: "Helvetica"
            font.bold: true
            color: "green"
            text: "ReadMore"
        }
    }
    Column {
        spacing: elementSpacing
        anchors.top: logoRect.bottom
        anchors.left: logoRect.left
        TextField {
            width: 300 * ratio
            anchors.leftMargin: page.width /100
            anchors.topMargin: page.height / 48
            anchors.rightMargin: page.width /100
            anchors.bottomMargin: page.height / 48
            anchors.verticalCenter: parent
            horizontalAlignment: Text.AlignHCenter
            text: "Login"
            style: TextFieldStyle {
                textColor: "black"
                background: Rectangle {
                    radius: 2
                    implicitHeight: 24
                    border.color: "#333"
                    border.width: 1
                }
            }
        }
        TextField {
            width: 300 * ratio
            anchors.leftMargin: page.width /100
            anchors.topMargin: page.height / 48
            anchors.rightMargin: page.width /100
            anchors.bottomMargin: page.height / 48
            anchors.verticalCenter: parent
            text: "Password"
            horizontalAlignment: Text.AlignHCenter
            style: TextFieldStyle {
                textColor: "black"
                background: Rectangle {
                    radius: 2
                    implicitHeight: 24
                    border.color: "#333"
                    border.width: 1
                }
            }
        }
        Row {
            spacing : parent.width/2
            Button {
                anchors.leftMargin: page.width /100
                anchors.topMargin: page.height / 48
                anchors.rightMargin: page.width /100
                anchors.bottomMargin: page.height / 48
                width: 80 * ratio
                text : "Sign In"
                id: signIn
                onClicked: stack.push((Qt.resolvedUrl("LibraryPage.qml")))
            }
            Button {
                anchors.leftMargin: page.width /100
                anchors.topMargin: page.height / 48
                anchors.rightMargin: page.width /100
                anchors.bottomMargin: page.height / 48
                width: 80 * ratio
                text : "Sign Up"
                id: signUp
                onClicked: stack.push((Qt.resolvedUrl("Register.qml")))
            }
        }
    }
}
