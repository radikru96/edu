#include <QtWidgets>
#include <QApplication>

//#include <QListView>
//#include <QTableView>
#include "MyWidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont f = a.font();
    f.setItalic(true);
    a.setFont(f);
    MyWidget wgt;
    wgt.show();
//    wgt.resize(300, 20);
    return a.exec();
}
