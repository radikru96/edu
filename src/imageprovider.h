#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QQuickPaintedItem>

class Ellipse : public QQuickPaintedItem
{
    Q_OBJECT
private:
    Q_PROPERTY( QColor color WRITE setColorValue READ colorValue )
    QColor m_color;
public:
    Ellipse( QQuickItem *parent = nullptr );
    void paint( QPainter *ppainter);
    QColor colorValue() const;
    void setColorValue( const QColor & );
};

#endif // IMAGEPROVIDER_H
