QT = core widgets

CONFIG += qt object warn_on debug_and_release

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#DESTDIR = bin

VPATH += ./src
SOURCES += main.cpp \
        MyWidget.cpp \
        renderarea.cpp

HEADERS += \
        MyWidget.h \
        renderarea.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

resources.files = \
    images/Linux.jpg \
    images/Linux.png \
    images/Linux_old.png \
    images/MacOS.jpg \
    images/MacOS.png \
    images/MacOS_old.png \
    images/OS2.jpg \
    images/OS2.png \
    images/OS2_old.png \
    images/Windows.jpg \
    images/Windows.png \
    images/Windows_old.png
resources.prefix = /

RESOURCES = resources
