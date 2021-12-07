#-------------------------------------------------
#
# Project created by QtCreator 2021-12-07T10:50:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DesMineurs
TEMPLATE = app


SOURCES += main.cpp\
        Mainwindow.cpp \
    Jeu.cpp \
    UIgagne.cpp \
    Joueur.cpp \
    Demineur.cpp

HEADERS  += Mainwindow.h \
    Jeu.h \
    Demineur.h \
    Joueur.h \
    UIgagne.h

FORMS    += mainwindow.ui
