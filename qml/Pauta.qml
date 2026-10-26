import QtQuick 2.15

Rectangle {
    id: pauta
    property var modelo: []
    property int destaque: -1
    color: "#120824"
    radius: 6
    border.color: "#3C1E70"
    border.width: 1

    readonly property int espacoLinha: 14
    readonly property int yPrimeiraLinha: 30

    function yDaNota(nome) {
        var passos = {
            "C4": -2, "D4": -1,
            "E4": 0, "F4": 1, "G4": 2, "A4": 3, "B4": 4,
            "C5": 5, "D5": 6, "E5": 7, "F5": 8,
            "G5": 9, "A5": 10, "B5": 11, "C6": 12
        }
        var p = passos[nome] !== undefined ? passos[nome] : 2
        return yPrimeiraLinha + 4 * espacoLinha - p * (espacoLinha / 2)
    }

    // 5 linhas
    Repeater {
        model: 5
        Rectangle {
            y: pauta.yPrimeiraLinha + index * pauta.espacoLinha
            width: pauta.width
            height: 1
            color: "#4A2680"
        }
    }

    Text {
        anchors.centerIn: parent
        text: "← Escolha as notas e figuras acima"
        color: "#6B5291"
        font.italic: true
        visible: pauta.modelo.length === 0
    }

    // Notas lado a lado, dentro de um Flickable interno
    Flickable {
        anchors.fill: parent
        anchors.leftMargin: 60
        contentWidth: fileira.width + 20
        contentHeight: height
        clip: true

        Row {
            id: fileira
            x: 10
            y: 0
            height: parent.height
            spacing: 8

            Repeater {
                model: pauta.modelo

                delegate: Item {
                    width: 30
                    height: pauta.height

                    FiguraNota {
                        x: 2
                        y: pauta.yDaNota(modelData.ePausa ? "A4" : modelData.nome) - 40
                        figura: modelData.figura
                        temPonto: modelData.temPonto
                        ePausa: modelData.ePausa
                        cor: index === pauta.destaque ? "#FFD166" : "#F0E6FF"
                    }

                    Text {
                        visible: !modelData.ePausa
                        x: 18
                        y: pauta.yDaNota(modelData.nome) - 6
                        text: modelData.nome
                        color: "#8B6FBF"
                        font.pixelSize: 9
                    }

                    Canvas {
                        visible: modelData.ligadura
                        x: 0
                        y: pauta.yDaNota(modelData.nome) - 52
                        width: 28; height: 10
                        onPaint: {
                            var ctx = getContext("2d")
                            ctx.reset()
                            ctx.strokeStyle = "#C77DFF"
                            ctx.lineWidth = 2
                            ctx.beginPath()
                            ctx.moveTo(2, height - 2)
                            ctx.quadraticCurveTo(width / 2, -4, width - 2, height - 2)
                            ctx.stroke()
                        }
                    }
                }
            }
        }
    }
}
