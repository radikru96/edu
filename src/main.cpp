#include <QtWidgets>
#include <QApplication>
#include "myview.h"
#include "simpleitem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;
    QGraphicsScene scene(QRectF(-100, -100, 640, 480));
    MyView *pView = new MyView(&scene);
    QPushButton *pcmdZoomIn = new QPushButton("Zoom In");
    QPushButton *pcmdZoomOut = new QPushButton("Zoom Out");
    QPushButton *pcmdRotateLeft = new QPushButton("Rotate Left");
    QPushButton *pcmdRotateRight = new QPushButton("Rotate Right");
    pView->setRenderHint(QPainter::Antialiasing, true);
    SimpleItem *pSimpleItem = new SimpleItem;
    scene.addItem(pSimpleItem);
    pSimpleItem->setPos(0, 0);
    pSimpleItem->setFlags(QGraphicsItem::ItemIsMovable);
    QGraphicsPixmapItem *pPixmapItem = scene.addPixmap(QPixmap(":/images/MacOS.png"));
    pPixmapItem->setParentItem(pSimpleItem);
    pPixmapItem->setFlags(QGraphicsItem::ItemIsMovable);
    QObject::connect(pcmdZoomIn, SIGNAL(clicked()), pView, SLOT(slotZoomIn()));
    QObject::connect(pcmdZoomOut, SIGNAL(clicked()), pView, SLOT(slotZoomOut()));
    QObject::connect(pcmdRotateLeft, SIGNAL(clicked()), pView, SLOT(slotRotateLeft()));
    QObject::connect(pcmdRotateRight, SIGNAL(clicked()), pView, SLOT(slotRotateRight()));

    QVBoxLayout *pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pView);
    pvbxLayout->addWidget(pcmdZoomIn);
    pvbxLayout->addWidget(pcmdZoomOut);
    pvbxLayout->addWidget(pcmdRotateLeft);
    pvbxLayout->addWidget(pcmdRotateRight);
    wgt.setLayout(pvbxLayout);
    wgt.show();
    return a.exec();
}
