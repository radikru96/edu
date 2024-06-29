#include <QtCore>
#include <QJSEngine>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QJSEngine scriptEngine;
    QJSValue value = scriptEngine.evaluate( "2 * 8" );
    qDebug() << value.toInt();
    return 0;
}
