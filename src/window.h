#ifndef WINDOW_H
#define WINDOW_H

#include <QLabel>
#include <QPoint>
#include <QMouseEvent>

class Window : public QLabel
{
    QPoint m_ptPosition;
protected:
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseMoveEvent(QMouseEvent *ev);
public:
    Window(QWidget *pwgt = 0);
};

#endif // WINDOW_H
