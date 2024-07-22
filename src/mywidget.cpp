#include <QtWidgets>
#include <QQuickWidget>
#include <QQmlContext>
#include <QQuickItem>
#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget{parent}
{
    QQuickWidget *pv = new QQuickWidget( QUrl( "qrc:/src/main.qml" ) );
    QVBoxLayout *pvbx = new QVBoxLayout;
    pvbx->addWidget(pv);
    setLayout(pvbx);

    QQmlContext *pContext = pv->rootContext();
    QStringList lst;
    for ( int i = 0; i < 100; ++i )
        lst << "Item " + QString::number(i);
    QStringListModel *pModel = new QStringListModel(this);
    pModel->setStringList(lst);
    pContext->setContextProperty( "myModel", pModel );
    pContext->setContextProperty( "myText", "It's my text" );
    pContext->setContextProperty( "myWidget", this );
    QQuickItem *pqiRoot = pv->rootObject();
    pqiRoot->setProperty( "color", QColor( Qt::gray ) );
}

void MyWidget::slotDisplayDialog()
{
    QMessageBox::information( 0, "Message", "It's my message");
}
