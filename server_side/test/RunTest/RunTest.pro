#-------------------------------------------------
#
# Project created by QtCreator 2017-04-02T21:43:35
#
#-------------------------------------------------

QT       += network testlib core gui network

TARGET = tst_runteststest
CONFIG   += console
CONFIG += warn_off
CONFIG   -= app_bundle

TEMPLATE = app



PRJDIR       = ../..
include($$PRJDIR/commondir.pri)


SOURCES += tst_runteststest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH += $$PRJDIR/coderudite_ronin
SOURCES += $$PRJDIR/coderudite_ronin/model/run.cpp \
	$$PRJDIR/coderudite_ronin/model/solution.cpp \
	$$PRJDIR/coderudite_ronin/model/runresult.cpp


PRECOMPILED_HEADER +=     \
#	model/bean.hxx \
#	constants.hxx \
	$$PRJDIR/coderudite_ronin/helpers.hxx \
#	$$PRJDIR/sqlite3/sqlite3.h	\
#	$$PRJDIR/sqlite_modern_cpp/sqlite_modern_cpp.h	\
#	$$PRJDIR/sqlite_modern_cpp/collectors.hpp



DEFINES += "APPROOT=\"..\""
