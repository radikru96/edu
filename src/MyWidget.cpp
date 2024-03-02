#include "MyWidget.h"

MyWidget::MyWidget() {}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRect r(0, 0, 200, 120);
    QLinearGradient gra(80, 0, 120, 120);
    gra.setColorAt(0, Qt::red);
    gra.setColorAt(0.5, Qt::green);
    gra.setColorAt(1, Qt::blue);
    painter.setPen(QPen(gra, 0));
    painter.setFont(QFont("Times", 25, QFont::Normal));
    painter.drawRect(r);
    painter.drawText(r, Qt::AlignCenter | Qt::TextWordWrap, "DrawText" );
}
