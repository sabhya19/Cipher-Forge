QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    encode_menu.cpp \
    help_decode.cpp \
    help_encode.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    about.h \
    encode_menu.h \
    help_decode.h \
    help_encode.h \
    mainwindow.h \
    toold.h \
    toole.h

FORMS += \
    about.ui \
    encode_menu.ui \
    help_decode.ui \
    help_encode.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
