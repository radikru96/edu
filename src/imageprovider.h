#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QImage>
#include <QObject>
#include <QQuickImageProvider>

class ImageProvider
 : public QQuickImageProvider
{
private:
    QImage brightness( const QImage *imgOrig, int n );
public:
    ImageProvider();
    QImage requestImage( const QString &, QSize *, const QSize & );
};

#endif // IMAGEPROVIDER_H
