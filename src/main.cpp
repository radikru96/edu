#include <QApplication>
#include "turtleworkarea.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TurtleWorkArea turtleWorkArea;
    turtleWorkArea.show();
    return a.exec();
}
