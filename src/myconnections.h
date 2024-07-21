#ifndef MYCONNECTIONS_H
#define MYCONNECTIONS_H

#include <QtCore>

class MyConnections : public QObject
{
    Q_OBJECT
public:
    MyConnections( QObject *parent = nullptr ) : QObject(parent) {}
public slots:
    void slotQuit() { qApp->quit(); }
    void slotInfo( const QString &str ) { qDebug() << str; }
};

#endif // MYCONNECTIONS_H
