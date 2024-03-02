#include "MyWidget.h"

MyWidget::MyWidget() {}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRect r(0, 0, width() - 1, height() - 1);
    QLinearGradient gra(80, 0, width() - 1 - 80, height() - 1);
    QString str = "This is a long text. Please, resize the window";
    QString strElided;
    gra.setColorAt(0, Qt::red);
    gra.setColorAt(0.5, Qt::green);
    gra.setColorAt(1, Qt::blue);
    painter.setPen(QPen(gra, 0));
    painter.setFont(QFont("Times", 25, QFont::Normal));
    strElided = painter.fontMetrics().elidedText(str, Qt::ElideMiddle, width()-3);
    painter.drawRect(r);
    painter.drawText(r, Qt::AlignCenter, strElided);
}
