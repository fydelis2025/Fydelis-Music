import QtQuick 2.15

Canvas {
    id: fig

    property int figura: 4
    property bool temPonto: false
    property bool ePausa: false
    property color cor: "#F0E6FF"

    width: 30
    height: 80

    onCorChanged: requestPaint()
    onFiguraChanged: requestPaint()
    onEPausaChanged: requestPaint()
    onTemPontoChanged: requestPaint()

    onPaint: {
        var ctx = getContext("2d")
        ctx.reset()
        ctx.strokeStyle = cor
        ctx.fillStyle = cor
        ctx.lineWidth = 2

        if (!ePausa) {
            ctx.save()
            ctx.rotate(-0.35)
            ctx.beginPath()
            ctx.ellipse(11, 62, 8, 5.5, 0, 0, 2 * Math.PI)
            if (figura === 1 || figura === 2)
                ctx.stroke()
            else
                ctx.fill()
            ctx.restore()

            if (figura !== 1) {
                ctx.beginPath()
                ctx.moveTo(18, 60)
                ctx.lineTo(18, 6)
                ctx.stroke()
            }

            if (figura === 8 || figura === 16) {
                var nFlags = (figura === 8) ? 1 : 2
                for (var f = 0; f < nFlags; f++) {
                    var yBase = 6 + f * 11
                    ctx.beginPath()
                    ctx.moveTo(18, yBase)
                    ctx.bezierCurveTo(28, yBase + 2, 30, yBase + 8, 24, yBase + 14)
                    ctx.bezierCurveTo(28, yBase + 8, 26, yBase + 4, 18, yBase + 6)
                    ctx.fill()
                }
            }

            if (temPonto) {
                ctx.beginPath()
                ctx.arc(25, 60, 2.5, 0, 2 * Math.PI)
                ctx.fill()
            }
        } else {
            var y0 = 30
            if (figura === 1) {
                ctx.fillRect(8, y0, 14, 6)
            } else if (figura === 2) {
                ctx.fillRect(8, y0 + 24, 14, 6)
            } else {
                ctx.beginPath()
                ctx.moveTo(16, y0 + 4)
                ctx.lineTo(16, y0 + 30)
                ctx.lineTo(8, y0 + 30)
                ctx.lineTo(8, y0 + 23)
                ctx.lineTo(16, y0 + 16)
                ctx.lineTo(8, y0 + 12)
                ctx.lineTo(16, y0 + 8)
                ctx.closePath()
                ctx.fill()
                if (figura === 8) {
                    ctx.beginPath()
                    ctx.moveTo(16, y0 + 6)
                    ctx.bezierCurveTo(26, y0 + 10, 26, y0 + 20, 19, y0 + 25)
                    ctx.bezierCurveTo(24, y0 + 18, 23, y0 + 10, 16, y0 + 12)
                    ctx.fill()
                }
                if (figura === 16) {
                    ctx.beginPath()
                    ctx.moveTo(16, y0 + 14)
                    ctx.bezierCurveTo(26, y0 + 18, 26, y0 + 28, 19, y0 + 33)
                    ctx.bezierCurveTo(24, y0 + 26, 23, y0 + 18, 16, y0 + 20)
                    ctx.fill()
                }
            }
        }
    }
}
