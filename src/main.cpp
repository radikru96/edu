#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont f = a.font();
    f.setItalic(true);
    a.setFont(f);
    MyWidget wgt;
    wgt.show();
    return a.exec();
}
