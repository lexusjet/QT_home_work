import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 200
    height: 135
    title: qsTr("Add task")

    Rectangle{
        id: inputName
        width: 200
        height: 30
        color: "lightGrey"
        border.color: "grey"
        border.width: 2
        TextField{
            id: textfield1
            placeholderText: qsTr("Enter name")
        }
    }

    Rectangle{
        id: inputDeadLine
        width: 200
        height: 30
        color: "lightGrey"
        border.color: "grey"
        border.width: 2
        anchors.top: inputName.bottom
        TextField{
            id: textfield2
            placeholderText: qsTr("Enter finish date")
        }
    }

    Rectangle{
        id: inputProgress
        width: 200
        height: 30
        color: "lightGrey"
        anchors.top: inputDeadLine.bottom
        border.color: "grey"
        border.width: 2
        TextField{
            id: textfield3
            placeholderText: qsTr("Progress from 0 to 10")
        }
    }

    Button{
        id: canceleAdding
        text: "Canncele"
        anchors.top: inputProgress.bottom
        onClicked: {
            close()
        }
    }
    Button{
        id: addTask
        text: "Add Task"
        anchors.left: canceleAdding.right
        anchors.verticalCenter:  canceleAdding.verticalCenter
        onClicked: {
            taskcontroler.addTask(textfield1.text + " "
                                  + textfield2.text + " "
                                  + textfield3.text)
        }
    }
}
