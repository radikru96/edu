#include <QApplication>
#include "mywidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget wgt;
    wgt.show();
    return app.exec();
}
