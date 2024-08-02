#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "imageprovider.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.addImageProvider( QLatin1String("brightness"), new ImageProvider );
    engine.load( QUrl( "qrc:/src/main.qml" ) );
    return app.exec();
}
