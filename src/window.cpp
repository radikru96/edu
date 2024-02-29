#include "window.h"

void Window::mousePressEvent(QMouseEvent *ev)
{
    m_ptPosition = ev->pos();
}

void Window::mouseMoveEvent(QMouseEvent *ev)
{
    move(ev->globalPos() - m_ptPosition);
}

Window::Window(QWidget *pwgt) : QLabel(pwgt, Qt::FramelessWindowHint | Qt::Window) {}
