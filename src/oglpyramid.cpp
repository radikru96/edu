#include "oglpyramid.h"

void OGLPyramid::initializeGL()
{
    QOpenGLFunctions *pFunc = QOpenGLContext::currentContext()->functions();
    pFunc->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    pFunc->glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    m_nPyramid = createPyramid(1.2f);
}

void OGLPyramid::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
}

void OGLPyramid::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0);
    glRotatef(m_xRotate, 1.0, 0.0, 0.0);
    glRotatef(m_yRotate, 0.0, 1.0, 0.0);
    glCallList(m_nPyramid);
}

void OGLPyramid::mousePressEvent(QMouseEvent *pe)
{
    m_ptPosition = pe->pos();
}

void OGLPyramid::mouseMoveEvent(QMouseEvent *pe)
{
    m_xRotate += 180 * (GLfloat)(pe->position().y() - m_ptPosition.y()) / height();
    m_yRotate += 180 * (GLfloat)(pe->position().x() - m_ptPosition.x()) / width();
    update();
    m_ptPosition = pe->pos();
}

GLuint OGLPyramid::createPyramid(GLfloat fSize /* = 1.0f*/)
{
    GLuint n = glGenLists(1);
    glNewList(n, GL_COMPILE);
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
    glVertex3f(0.0, fSize, 0.0);
    glVertex3f(-fSize, -fSize, fSize);
    glVertex3f(fSize, -fSize, fSize);
    glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
    glVertex3f(fSize, -fSize, -fSize);
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    glVertex3f(-fSize, -fSize, -fSize);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glVertex3f(-fSize, -fSize, fSize);
    glEnd();
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    glVertex3f(-fSize, -fSize, fSize);
    glVertex3f(fSize, -fSize, fSize);
    glVertex3f(fSize, -fSize, -fSize);
    glVertex3f(-fSize, -fSize, -fSize);
    glEnd();
    glEndList();
    return n;
}

OGLPyramid::OGLPyramid(QWidget *pwgt /* = 0*/) : QOpenGLWidget(pwgt), m_xRotate(0), m_yRotate(0) {}
