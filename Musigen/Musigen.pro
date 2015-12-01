#-------------------------------------------------
#
# Project created by QtCreator 2015-10-29T00:39:02
#
#-------------------------------------------------

QT      += core gui
CONFIG  += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET  = Musigen
TEMPLATE = app

#include(Interface/include.pri)

PLUGINS = Resources/Plugins

SOURCES += main.cpp \
        mainwindow.cpp \
        notefield.cpp \
    musicplayer.cpp \
    timer.cpp \
    recorder.cpp \
    Melody/instrument.cpp \
    Melody/melody.cpp \
    Melody/note.cpp

HEADERS += mainwindow.h \
        notefield.h \
    musicplayer.h \
    timer.h \
    recorder.h \
    Melody/instrument.h \
    Melody/melody.h \
    Melody/note.h

FORMS   += mainwindow.ui

INCLUDEPATH += $$PLUGINS/irrKlang-1.5.0/include
LIBS    += -L$$PLUGINS/irrKlang-1.5.0/bin/win32-gcc
LIBS    += -lirrKlang -likpMP3

#INCLUDEPATH += $$PLUGINS/jdksmidi-master/include
#LIBS    += -L$$PLUGINS/jdksmidi-master/build/vs2013/Release
#LIBS    += -ljdksmidi

