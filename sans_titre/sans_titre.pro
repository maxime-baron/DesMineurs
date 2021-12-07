#-------------------------------------------------
#
# Project created by QtCreator 2021-12-01T17:10:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sans_titre
TEMPLATE = app


SOURCES += main.cpp\
        jeu.cpp \
    Joueur.cpp \
    UIgagne.cpp

HEADERS  += jeu.h \
    Joueur.h \
    UIgagne.h

FORMS    += jeu.ui
