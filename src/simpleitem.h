#pragma once

#include <QApplication>
#include <QPainter>
#include <QGraphicsItem>

class SimpleItem : public QGraphicsItem
{
    enum { nPenWidth = 3 };
public:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *ppainter, const QStyleOptionGraphicsItem *, QWidget *);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *pe);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *pe);
};
