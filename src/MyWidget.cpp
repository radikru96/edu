#include "MyWidget.h"

MyWidget::MyWidget() {}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRect r(0, 0, 200, 120);
    painter.setFont(QFont("Times", 25, QFont::Normal));
    painter.drawRect(r);
    painter.drawText(r, Qt::AlignCenter | Qt::TextWordWrap, "DrawText" );
}
