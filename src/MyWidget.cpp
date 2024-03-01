#include "MyWidget.h"

MyWidget::MyWidget() {}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setFont(QFont("Times", 25, QFont::Normal));
    painter.drawText(10, 40, "DrawText" );
}
