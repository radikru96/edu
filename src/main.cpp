#include <QApplication>
#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQuickView>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQuickView view;
    QUrl urlAssetsPath;
#if defined( Q_OS_ANDROID)
    urlAssetsPath = QUrl("assets:/Resources/");
#endif
    QFileInfo fi( app.applicationFilePath() );
    app.setApplicationName( fi.baseName() );
    view.connect( view.engine(), SIGNAL(quit()), &app, SLOT(quit()) );
    view.setSource( QUrl( "qrc:/src/main.qml" ) );
    view.setResizeMode( QQuickView::SizeRootObjectToView );
    view.show();
    return app.exec();
}
