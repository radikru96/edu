#include <QtWidgets>
#include <QApplication>
#include "ogldraw.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OGLDraw oglDraw;
    oglDraw.resize(400, 200);
    oglDraw.show();
    return a.exec();
}
