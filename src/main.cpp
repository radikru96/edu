#include <QtWidgets>
#include <QApplication>
#include "MyWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget wgt;
    wgt.show();
    return a.exec();
}
