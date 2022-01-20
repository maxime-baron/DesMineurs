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
    Jeu.cpp \
    UIgagne.cpp \
    Joueur.cpp \
    Demineur.cpp \
    Grille.cpp \
    Case.cpp

HEADERS  += \
    Jeu.h \
    Demineur.h \
    Joueur.h \
    UIgagne.h \
    Grille.h \
    Case.h

FORMS    += \
    jeu.ui

RESOURCES += \
    Images.qrc
