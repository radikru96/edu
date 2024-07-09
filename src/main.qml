import QtQuick

Canvas {
    id: canv
    width: 400
    height: 400
    onPaint: {
        var ctx = getContext("2d");
        ctx.strokeStyle = "black"
        ctx.lineWidth = 15
        var gradient = ctx.createLinearGradient( canv.width, canv.height, 0, 0 )
        gradient.addColorStop( 0, "Indigo" )
        gradient.addColorStop( 0.5, "Bisque" )
        gradient.addColorStop( 1, "ForestGreen" )
        ctx.fillStyle = gradient
        ctx.fillRect( 0, 0, canv.width, canv.height )
        ctx.fillRect( 0, 0, canv.width, canv.height )
    }
}
