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
//            anchors.horizontalCenter: navBar.width/2
//            anchors.top: navBar.top - 40
            Text {
                anchors.centerIn: parent
                font.pixelSize: 40
                font.family: "Helvetica"
                font.bold: true
                color: "black"
                text: "Library"
            }
        }
        Button {
            x:parent.width - 30 - parent.height/2
            y:parent.height/4
            height:parent.height/2
            width:parent.height/2
            style: ButtonStyle {
                background:BorderImage {
                    id: addButton
                    anchors.fill:parent
                    source: "addBook.png"
                }
            }
//            onClicked:stack.pop()
        }
    }
    GridView {
        clip: true
        width: parent.width
        height:parent.height - navBar.height
        anchors.top: navBar.bottom
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;

        id: myLibrary
        model: booksModel
        delegate: libraryDelegate
        cellWidth: parent.width/4;
        cellHeight: cellHeight * 4
    }
    Component {
        id: libraryDelegate
        Item {
            width: myLibrary.cellWidth
            height: myLibrary.cellHeight
            MouseArea {
                      anchors.fill: parent;
                      onReleased:{
                          stack.push(Qt.resolvedUrl("Reader.qml"));
                      }
            }
            Column {
                anchors.fill : parent
                Image {
                    source: model.modelData.artBook
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    text: model.modelData.title
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }
}

