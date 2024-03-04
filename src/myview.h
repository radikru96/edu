#pragma once

#include <QGraphicsView>

class MyView : public QGraphicsView
{
    Q_OBJECT
public:
    MyView(QGraphicsScene *pScene, QWidget *pwgt = 0);
public slots:
    void slotZoomIn();
    void slotZoomOut();
    void slotRotateLeft();
    void slotRotateRight();
};
