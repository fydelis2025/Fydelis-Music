import QtQuick 2.15

Rectangle {
    property int figura: 0
    property string nome: ""
    signal clicked()

    width: 86
    height: 84
    radius: 8
    color: mouse.containsMouse ? "#3A1A6B" : "#2A1050"
    border.width: 2
    border.color: "#5E35B1"

    MouseArea { id: mouse; anchors.fill: parent; hoverEnabled: true; onClicked: parent.clicked() }

    FiguraNota {
        id: desenho
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 4
        figura: parent.figura
        temPonto: false
        ePausa: false
        cor: "#E0D7FF"
    }
    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 4
        text: nome
        color: "#E0D7FF"
        font.pixelSize: 11
    }
}
