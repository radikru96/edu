#include <QtWidgets>
#include <QApplication>
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window wnd;
    wnd.setAttribute(Qt::WA_TranslucentBackground);
    wnd.setPixmap(QPixmap(":/images/Linux_old.png").scaled(300, 300, Qt::KeepAspectRatio));
    QPushButton *pcmdQuit = new QPushButton("X");
    pcmdQuit->setFixedSize(16,16);
    QObject::connect(pcmdQuit, SIGNAL(clicked()), &a, SLOT(quit()));
    QVBoxLayout *pvbx = new QVBoxLayout;
    pvbx->addWidget(pcmdQuit);
    pvbx->addStretch(1);
    wnd.setLayout(pvbx);
    wnd.show();
    return a.exec();
}
