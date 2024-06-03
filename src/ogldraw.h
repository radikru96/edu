#ifndef OGLDRAW_H
#define OGLDRAW_H

#include <QtOpenGL>
#include <QOpenGLWidget>

class OGLDraw : public QOpenGLWidget
{
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
public:
    OGLDraw(QWidget *pwgt = 0);
    void draw(int yOffset, int xOffset, GLenum type);
};

#endif // OGLDRAW_H
