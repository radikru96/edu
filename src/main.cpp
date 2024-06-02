#include <QtWidgets>
#include <QApplication>
#include <QStateMachine>
#include <QSignalTransition>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;
    wgt.setFixedSize(300, 50);
    wgt.show();
    QLabel *plblOff = new QLabel("Off");
    QLabel *plblOn = new QLabel("On");
    QHBoxLayout *phbx = new QHBoxLayout;
    phbx->addWidget(plblOn);
    phbx->addStretch(1);
    phbx->addWidget(plblOff);
    wgt.setLayout(phbx);
    QPushButton *pcmd = new QPushButton("Push", &wgt);
    pcmd->setAutoFillBackground(true);
    pcmd->show();
    int nButtonWidth = wgt.width() / 2;
    QStateMachine *psm = new QStateMachine;
    QState *pStateOff = new QState(psm);
    QRect rect1(0, 0, nButtonWidth, wgt.height());

//  The StateMachine set's properties certain widgets for off state
    pStateOff->assignProperty(pcmd, "geometry", rect1);
    pStateOff->assignProperty(plblOff, "visible", true);
    pStateOff->assignProperty(plblOn, "visible", false);

//  The StateMachine set's StateOff how initial
    psm->setInitialState(pStateOff);

    QState *pStateOn = new QState(psm);
    QRect rect2(nButtonWidth, 0, nButtonWidth, wgt.height());

    pStateOn->assignProperty(pcmd, "geometry", rect2);
    pStateOn->assignProperty(plblOff, "visible", false);
    pStateOn->assignProperty(plblOn, "visible", true);

//  Signals to switch the StateMachine
    QSignalTransition *ptrans1 = pStateOff->addTransition(pcmd, SIGNAL(clicked(bool)), pStateOn);
    QSignalTransition *ptrans2 = pStateOn->addTransition(pcmd, SIGNAL(clicked(bool)), pStateOff);

    QPropertyAnimation *panim1 = new QPropertyAnimation(pcmd, "geometry");
    ptrans1->addAnimation(panim1);
    QPropertyAnimation *panim2 = new QPropertyAnimation(pcmd, "geometry");
    ptrans2->addAnimation(panim2);

//  Start to work the StateMachine
    psm->start();
    return a.exec();
}
