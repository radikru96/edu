#include <QApplication>
#include <QQmlApplicationEngine>
#include "calculation.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<Calculation>( "com.myinc.Calculation", 1, 0, "Calculation" );
    QQmlApplicationEngine engine;
    engine.load( QUrl( "qrc:/src/main.qml" ) );
    return app.exec();
}
