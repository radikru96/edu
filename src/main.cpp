#include <QtWidgets>
#include <QApplication>
#include "hexlineedit.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HexLineEdit hle;
    hle.show();
    return a.exec();
}
