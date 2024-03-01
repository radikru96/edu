#include <QtWidgets>
#include <QApplication>
#include "MyWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget wgt;
    wgt.show();
    wgt.resize(201, 121);
    return a.exec();
}
