#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene(QRectF(-100, -100, 300, 300));
    QGraphicsView view(&scene );
    QGraphicsRectItem *pRectItem = scene.addRect(QRectF( -30, -30, 120, 80),
                                                 QPen(Qt::black),
                                                 QBrush(Qt::green));
    pRectItem->setFlags(QGraphicsItem::ItemIsMovable);
    QGraphicsTextItem *pTextItem = scene.addText("Move us with your mouse");
    pTextItem->setFlags(QGraphicsItem::ItemIsMovable);
    QGraphicsLineItem *pLineItem = scene.addLine(QLineF(-10, -10, -80, -80), QPen(Qt::red, 2));
    pLineItem->setParentItem(pRectItem);
    pLineItem->setFlags(QGraphicsItem::ItemIsMovable);
    pLineItem->setTransform(QTransform().shear( -0.5, 0.0 ), true);
    QGraphicsPixmapItem *pPixmapItem = scene.addPixmap(QPixmap(":/images/Windows.png"));
    pPixmapItem->setFlags(QGraphicsItem::ItemIsMovable);

    view.show();
    return a.exec();
}
