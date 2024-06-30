#include <QJSEngine>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel *plbl = new QLabel;
    QJSEngine scriptEngine;

    QJSValue scriptLbl = scriptEngine.newQObject(plbl);             //QLabel's object insert to JSEngine
    scriptEngine.globalObject().setProperty( "lbl", scriptLbl );    //Object's declaration for JSEngine

    scriptEngine.evaluate( "lbl.text = 'Hello, JavaCreep!'" );
    scriptEngine.evaluate( "lbl.show()" );
    return a.exec();
}
