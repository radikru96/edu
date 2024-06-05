#ifndef OGLPYRAMID_H
#define OGLPYRAMID_H

#include <QOpenGLWidget>
#include <QtOpenGL>

class OGLPyramid : public QOpenGLWidget
{
private:
    GLuint m_nPyramid;
    GLfloat m_xRotate;
    GLfloat m_yRotate;
    QPoint m_ptPosition;
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    virtual void mousePressEvent(QMouseEvent *pe);
    virtual void mouseMoveEvent(QMouseEvent *pe);
    GLuint createPyramid(GLfloat fSize = 1.0f);
public:
    OGLPyramid(QWidget *pwgt = 0);
};

#endif // OGLPYRAMID_H
