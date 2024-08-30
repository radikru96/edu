QT += quick qml widgets sensors multimedia

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
resources.files += \
    src/main.qml
    media/InfoButton.png
resources.prefix = /

RESOURCES = resources

APP_FILES.files += media/alarm.mp3
android {
    DISTFILES += \
        android/AndroidManifest.xml \
        android/build.gradle \
        android/gradle.properties \
        android/gradle/wrapper/gradle-wrapper.jar \
        android/gradle/wrapper/gradle-wrapper.properties \
        android/gradlew \
        android/gradlew.bat \
        android/res/values/libs.xml

    contains(ANDROID_TARGET_ARCH,arm64-v8a) {
        ANDROID_PACKAGE_SOURCE_DIR = \
            $$PWD/android
    }

    APP_FILES.path = /assets/Resources
    APP_FILES.Depends += FORCE
    INSTALLS += APP_FILES
}
