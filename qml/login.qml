import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQml.Models 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
Item {
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
    }
    Column {
        spacing: 20
        anchors.centerIn: parent
        TextField {
            horizontalAlignment: Text.AlignHCenter
            anchors.margins: 20
            width: logoView.width
            text: "Login"
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
            anchors.margins: 20
            width: logoView.width
            text: "Password"
            horizontalAlignment: Text.AlignHCenter
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
        Row {
            spacing : parent.width/2
            Button {
                width : logoView.width/4
                text : "Sign In"
                id: signIn
                onClicked: stack.push((Qt.resolvedUrl("LibraryPage.qml")))
            }
            Button {
                width : logoView.width/4
                text : "Sign Up"
                id: signUp
                onClicked: stack.push((Qt.resolvedUrl("Register.qml")))
            }
        }
    }
}
