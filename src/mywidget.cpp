#include <QVBoxLayout>
#include <QQuickWidget>
#include <QQuickItem>
#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget{parent}
{
    QQuickWidget *pv = new QQuickWidget( QUrl( "qrc:/src/main.qml" ) );
    QVBoxLayout *pvbx = new QVBoxLayout;
    pvbx->addWidget(pv);
    setLayout(pvbx);
    QQuickItem *pqiRoot = pv->rootObject();
    if (pqiRoot) {
        pqiRoot->setProperty( "color", "yellow" );
        QObject *pObjText = pqiRoot->findChild<QObject *>( "text" );
        if ( pObjText ) {
            pObjText->setProperty( "text", "C++" );
            pObjText->setProperty( "color", "blue" );
            QVariant varRet;
            QMetaObject::invokeMethod( pObjText, "setFontSize", Q_RETURN_ARG( QVariant, varRet ), Q_ARG( QVariant, 52 ) );
            qDebug() << varRet;
        }
    }
}
