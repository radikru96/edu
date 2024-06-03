#include <QtWidgets>
#include <QApplication>
#include "oglquad.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OGLQuad oglQuad;
    oglQuad.resize(200, 200);
    oglQuad.showFullScreen();
    return a.exec();
}
