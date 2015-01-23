#-------------------------------------------------
#
# Project created by QtCreator 2015-01-22T17:11:28
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MindWave
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    epilepsy.cpp

HEADERS  += mainwindow.h \
    epilepsy.h

FORMS    += mainwindow.ui

linux {
QMAKE_CXXFLAGS += -std=c++11
}
