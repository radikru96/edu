#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "imageprovider.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<Ellipse>( "com.myinc.Ellipse", 1, 0, "Ellipse" );
    QQmlApplicationEngine engine;
    engine.load( QUrl( "qrc:/src/main.qml" ) );
    return app.exec();
}
