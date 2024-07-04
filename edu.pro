QT += core widgets

CONFIG += qt object warn_on debug_and_release

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#DESTDIR = bin

branch_name = $$system("git branch --show-current")
TARGET = $$branch_name

VPATH += ./src
SOURCES += main.cpp \

HEADERS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#DISTFILES += \
# resources.files += \
# resources.prefix = /

# RESOURCES = resources

