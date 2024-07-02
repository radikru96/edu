#ifndef TURTLEWORKAREA_H
#define TURTLEWORKAREA_H

#include <QJSEngine>
#include <QtWidgets>

class QTextEdit;
class Turtle;

class TurtleWorkArea : public QWidget
{
    Q_OBJECT
private:
    QTextEdit *m_ptxt;
    QJSEngine m_scriptEngine;
    Turtle *m_pTurtle;

public:
    TurtleWorkArea(QWidget *parent = nullptr);

public slots:
    void slotEvaluate();
    void slotApplyCode( int );
};

#endif // TURTLEWORKAREA_H
