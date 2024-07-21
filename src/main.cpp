#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include "myconnections.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlComponent component( &engine, QUrl("qrc:/src/main.qml") );
    MyConnections mc;
    QObject *pobj = component.create();
    QObject *pcmdQuitButton = pobj->findChild<QObject *>( "QuitButton" );
    if ( pcmdQuitButton )
        QObject::connect( pcmdQuitButton, SIGNAL(quitClicked()), &mc, SLOT(slotQuit()) );
    QObject *pcmdInfoButton = pobj->findChild<QObject *>( "InfoButton" );
    if ( pcmdInfoButton )
        QObject::connect( pcmdInfoButton, SIGNAL(infoClicked()), &mc, SLOT(slotInfo(QString)) );
    return app.exec();
}
