#include <QtWidgets>
#include <QApplication>

//#include <QListView>
//#include <QTableView>
#include "MyWidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget wgt;
    wgt.show();
//    wgt.resize(300, 20);
    return a.exec();
}
