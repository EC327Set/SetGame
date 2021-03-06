#-------------------------------------------------
#
# Project created by QtCreator 2014-05-01T11:51:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EC_327_Final
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Board.cpp \
    Game.cpp \
    Player.cpp \
    Card.cpp

HEADERS  += mainwindow.h \
    Board.h \
    Game.h \
    Player.h \
    Card.h

FORMS    += mainwindow.ui

RESOURCES += \
    Picture.qrc
