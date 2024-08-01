#include "ellipse.h"
#include <QPainter>

Ellipse::Ellipse(QQuickItem *parent)
    : QObject{parent}, m_color(Qt::black) {}

void Ellipse::paint(QPainter *ppainter)
{
    ppainter->setRenderHint( QPainter::Antialiasing, true );
    ppainter->setBrush( QBrush( colorValue()) );
    ppainter->setPen( Qt::NoPen );
    ppainter->drawEllipse( boundingRect() );
}

QColor Ellipse::inputValue() const
{
    return m_color;
}

void Ellipse::setInputValue(const QColor &col)
{
    m_color = col;
}
