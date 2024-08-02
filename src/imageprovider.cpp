#include "imageprovider.h"
#include <QPainter>

ImageProvider
    ::ImageProvider
    (QQuickItem *parent)
    : QQuickPaintedItem{parent}, m_color(Qt::black) {}

void ImageProvider
    ::paint(QPainter *ppainter)
{
    ppainter->setRenderHint( QPainter::Antialiasing, true );
    ppainter->setBrush( QBrush( colorValue()) );
    ppainter->setPen( Qt::NoPen );
    ppainter->drawEllipse( boundingRect() );
}

QColor ImageProvider
    ::colorValue() const
{
    return m_color;
}

void ImageProvider
    ::setColorValue(const QColor &col)
{
    m_color = col;
}
