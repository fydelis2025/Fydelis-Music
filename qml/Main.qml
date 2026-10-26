import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import FydelisMusic 1.0

ApplicationWindow {
    visible: true
    title: "FydelisMusic"
    width: 960
    height: 680
    color: "#0F051F"

    property string notaEscolhida: ""
    property int indiceTocado: -1

    FydMusic {
        id: music
        onNotaTocada: indiceTocado = indice
        onSequenciaTerminada: { indiceTocado = -1; statusText.text = "Pronto!" }
        onEstaTocandoChanged: if (music.estaTocando) statusText.text = "Tocando..."
    }

    property var notas: [
        { nome: "C4", texto: "Dó"  }, { nome: "D4",  texto: "Ré"  },
        { nome: "E4", texto: "Mi"  }, { nome: "F4",  texto: "Fá"  },
        { nome: "G4", texto: "Sol" }, { nome: "A4",  texto: "Lá"  },
        { nome: "B4", texto: "Si"  }, { nome: "C5",  texto: "Dó⁺" },
        { nome: "D5", texto: "Ré⁺" }, { nome: "E5",  texto: "Mi⁺" },
        { nome: "F5", texto: "Fá⁺" }, { nome: "G5",  texto: "Sol⁺"},
        { nome: "A5", texto: "Lá⁺" }, { nome: "B5",  texto: "Si⁺" }
    ]
    property var figuras: [
        { figura: 1,  nome: "Semibreve" },
        { figura: 2,  nome: "Mínima" },
        { figura: 4,  nome: "Semínima" },
        { figura: 8,  nome: "Colcheia" },
        { figura: 16, nome: "Semicolcheia" }
    ]

    function adicionarFigura(f) {
        if (notaEscolhida !== "")
            music.adicionarNota(notaEscolhida, f, pontoAtivo.checked)
        else
            music.adicionarPausa(f)
        statusText.text = "Adicionado!"
        notaEscolhida = ""
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 56
            gradient: Gradient {
                GradientStop { position: 0; color: "#2A1050" }
                GradientStop { position: 1; color: "#5E35B1" }
            }
            Text {
                anchors.centerIn: parent
                text: "🎵 FydelisMusic — Montador de Partitura"
                font.pixelSize: 20
                font.bold: true
                color: "#FFFFFF"
            }
        }

        // ---- Partitura (sempre visível, altura fixa) ----
        Pauta {
            id: pautaVisual
            Layout.fillWidth: true
            Layout.preferredHeight: 130
            modelo: music.partitura
            destaque: indiceTocado
        }

        // ---- Notas ----
        GroupBox {
            Layout.fillWidth: true
            label: Text { text: "🎹 Notas"; color: "#C77DFF"; font.bold: true }
            background: Rectangle { color: "#1A0B30"; radius: 8 }

            implicitHeight: 140

            Flow {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 8
                Repeater {
                    model: notas
                    delegate: BotaoNota {
                        nota: modelData.nome
                        nome: modelData.texto
                        selecionado: notaEscolhida === nota
                        onClicked: {
                            notaEscolhida = nota
                            music.tocarNotaAvulsa(nota)
                        }
                    }
                }
            }
        }

        // ---- Figuras ----
        GroupBox {
            Layout.fillWidth: true
            label: Text { text: "🎵 Figuras Rítmicas"; color: "#C77DFF"; font.bold: true }
            background: Rectangle { color: "#1A0B30"; radius: 8 }

            implicitHeight: 130

            Flow {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 8
                Repeater {
                    model: figuras
                    delegate: BotaoFigura {
                        figura: modelData.figura
                        nome: modelData.nome
                        onClicked: adicionarFigura(modelData.figura)
                    }
                }

                CheckBox {
                    id: pontoAtivo
                    text: "Ponto (.)"
                    contentItem: Text { text: pontoAtivo.text; color: "#E0D7FF"; verticalAlignment: Text.AlignVCenter }
                    indicator: Rectangle {
                        implicitWidth: 18; implicitHeight: 18
                        radius: 4
                        color: pontoAtivo.checked ? "#9D4EDD" : "#120824"
                        border.color: "#C77DFF"
                        Text { visible: pontoAtivo.checked; anchors.centerIn: parent; text: "✓"; color: "white" }
                    }
                }

                Button { text: "⏸️ Pausa"; onClicked: adicionarFigura(4) }
                Button { text: "🔗 Ligadura"; onClicked: music.aplicarLigadura() }
                Button { text: "↩️ Desfazer"; onClicked: music.removerUltima() }
            }
        }

        // ---- BPM ----
        RowLayout {
            Layout.fillWidth: true
            Text { text: "BPM:"; color: "#C77DFF"; font.bold: true }
            Slider {
                id: bpmSlider
                Layout.fillWidth: true
                from: 40; to: 240
                value: music.andamento
                onValueChanged: music.andamento = value
            }
            Text { text: music.andamento + " BPM"; color: "#E0D7FF"; font.bold: true }
        }

        // ---- Botões ----
        RowLayout {
            Layout.fillWidth: true
            spacing: 15

            Button {
                text: music.estaTocando ? "⏹️ Parar" : "▶️ Tocar"
                Layout.fillWidth: true
                Layout.preferredHeight: 55
                background: Rectangle { color: music.estaTocando ? "#C0392B" : "#27AE60"; radius: 8 }
                contentItem: Text { text: parent.text; color: "white"; font.bold: true; horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter }
                onClicked: music.estaTocando ? music.parar() : music.tocarSequencia()
            }

            Button {
                text: "🗑️ Limpar"
                Layout.fillWidth: true
                Layout.preferredHeight: 55
                background: Rectangle { color: "#8623B0"; radius: 8 }
                contentItem: Text { text: parent.text; color: "white"; horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter }
                onClicked: music.limparPartitura()
            }
        }

        Label {
            id: statusText
            text: "Pronto — comece montando sua partitura!"
            color: "#9D4EDD"
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignHCenter
        }
    }
}
