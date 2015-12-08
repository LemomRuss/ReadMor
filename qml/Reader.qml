import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQml.Models 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import BookView 1.0
Item {
    Rectangle {
        id:navBar
        width: parent.width
        height: 60
        color: "orange"
        Button {
            x:30
            y:parent.height/4
            height:parent.height/2
            width:parent.height/2
            style: ButtonStyle {
                background:BorderImage {
                    id: backButton
                    anchors.fill:parent
                    source: "back.png"
                }
            }
            onClicked:stack.pop()
        }
        Rectangle {
            x:navBar.width/2
            y:navBar.height/2 + 5
            Text {
                anchors.centerIn: parent
                font.pixelSize: 40
                font.family: "Helvetica"
                font.bold: true
                color: "black"
                text: "Reader"
            }
        }
    }
    Rectangle {
        x : 10
        id: myBook
        width : parent.width - 20
        height: parent.height - navBar.height - 20
        y: navBar.height + 10
        Row {
            anchors.fill: parent
            spacing: 20
            Image {
                width:parent.width/2 - 10
                height: parent.height
                source: "Book.jpg"
            }

            Image {
                anchors.top:myBook.Top
                anchors.right: myBook.Right
                width:parent.width/2 - 10
                height: parent.height
                source: "Book.jpg"
            }

        }
    }
}


