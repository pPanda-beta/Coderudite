#-------------------------------------------------
#
# Project created by QtCreator 2017-05-19T14:38:56
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_servicetest
CONFIG   += console
CONFIG += warn_off
CONFIG   -= app_bundle

TEMPLATE = app



PRJDIR       = ../..
include($$PRJDIR/commondir.pri)

HEADERS += $$PRJDIR/coderudite_ronin/model/user.h \
	$$PRJDIR/coderudite_ronin/model/submission.h

SOURCES += tst_servicetest.cpp \
	$$PRJDIR/coderudite_ronin/model/qstringex.cpp \
	$$PRJDIR/coderudite_ronin/model/user.cpp \
	$$PRJDIR/coderudite_ronin/model/submission.cpp \
	$$PRJDIR/coderudite_ronin/model/session.cpp \
	$$PRJDIR/coderudite_ronin/mapper/qobjecthelper.cpp \
	$$PRJDIR/coderudite_ronin/mapper/abstractmapper.cpp	\
	$$PRJDIR/coderudite_ronin/mapper/usermapper.cpp	\
	$$PRJDIR/coderudite_ronin/mapper/userinfomapper.cpp	\
	$$PRJDIR/coderudite_ronin/mapper/sessionmapper.cpp	\
	$$PRJDIR/coderudite_ronin/mapper/submissionmapper.cpp	\
	$$PRJDIR/coderudite_ronin/service/userservice.cpp	\
	$$PRJDIR/coderudite_ronin/service/sessionservice.cpp \
	$$PRJDIR/coderudite_ronin/service/leaderboardservice.cpp

LIBS      +=  -lsqlite3


DEFINES += SRCDIR=\\\"$$PWD/\\\"
