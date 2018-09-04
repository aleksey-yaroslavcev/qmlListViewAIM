import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    ColumnLayout{
        Button {
            text: "Add"
            onClicked: testModel.addNew()
        }
        Button {
            text: "Remove"
            onClicked: testModel.removeLast()
        }
        ListView{
            width: 180; height: 200
            contentWidth: 320
            model: testModel
            delegate: Text {
                id: name
                text: TextRole
                ListView.onRemove: console.debug("ListView.onRemove")
                ListView.onAdd: console.debug("ListView.onAdd")
            }
        }
    }
}
