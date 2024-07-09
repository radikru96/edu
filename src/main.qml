import QtQuick

Item {
    width: 400
    height: 400
    Canvas {
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d");
            function drawFantasy() {
                ctx.beginPath()
                ctx.translate( parent.width / 2, parent.height / 2 )
                var fAngle = 91 * Math.PI / 180
                for ( var i = 0; i < 360; ++i ) {
                    var n = i * 2
                    ctx.moveTo( 0, 0 )
                    ctx.lineTo( n, 0 )
                    ctx.translate( n, 0 )
                    ctx.rotate( fAngle )
                }
                ctx.closePath()
            }
            ctx.clearRect( 0, 0, parent.width, parent.height )
            ctx.save()
            ctx.fillStyle = "#272933"
            ctx.fillRect( 0, 0, parent.width, parent.height )
            ctx.shadowColor = "#60B0F0"
            ctx.shadowBlur = 4
            ctx.strokeStyle = "darkGray"
            ctx.lineWidth = 0.4

            drawFantasy();

            ctx.stroke();
            ctx.restore();
        }
    }
}
