import QtQuick 2.15

Rectangle {
    property string nota: ""
    property string nome: ""
    property bool selecionado: false
    signal clicked()

    width: 72; height: 52; radius: 8
    gradient: Gradient {
        GradientStop { position: 0; color: selecionado ? "#C77DFF" : "#7B2CBF" }
        GradientStop { position: 1; color: "#9D4EDD" }
    }
    border.width: 2
    border.color: selecionado ? "#FFFFFF" : "#C77DFF"

    Text { anchors.centerIn: parent; text: nome; color: "white"; font.pixelSize: 15; font.bold: true }
    MouseArea { anchors.fill: parent; onClicked: parent.clicked() }
}
