#include <QtWidgets>
#include <QApplication>
#include "MyWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget wgt;
    wgt.setAttribute(Qt::WA_TranslucentBackground);
    wgt.show();
    wgt.resize(200, 20);
    return a.exec();
}
