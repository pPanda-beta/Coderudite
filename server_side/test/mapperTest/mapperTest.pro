#-------------------------------------------------
#
# Project created by QtCreator 2017-05-13T14:47:26
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_mappertest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


PRJDIR       = ../..
include($$PRJDIR/commondir.pri)

HEADERS += ../../coderudite_ronin/model/user.h

SOURCES += tst_mappertest.cpp \
	../../coderudite_ronin/model/user.cpp \
	../../coderudite_ronin/mapper/qobjecthelper.cpp \

DEFINES += SRCDIR=\\\"$$PWD/\\\"
