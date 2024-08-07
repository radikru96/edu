#include <QGuiApplication>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView view;
    view.resize( 300, 300 );
    view.setResizeMode( QQuickView::SizeRootObjectToView );
    view.setSource( QUrl( "qrc:/src/main.qml" ) );
    view.show();
    return app.exec();
}
