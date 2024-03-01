#pragma once
#include <QtWidgets>
#include <QEvent>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    MyWidget();
    void paintEvent(QPaintEvent *);
};
