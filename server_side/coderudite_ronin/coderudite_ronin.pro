#-------------------------------------------------
#
# Project created by QtCreator 2017-01-02T15:17:56
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = coderudite_ronin
TEMPLATE = app

PRJDIR       = ..
include($$PRJDIR/commondir.pri)


SOURCES += main.cpp\
        mainwindow.cpp \
    cdnview.cpp \
    abstractserver.cpp \
    cdn.cpp \
    model/solution.cpp \
    model/runresult.cpp \
    model/run.cpp \
    dedicatedrunserver.cpp \
    run_server_view.cpp \
    servlet/abstractServlet.cpp \
    contesthostserver.cpp \
    servlet/errorservlet.cpp \
    contesthost_server_view.cpp \
    mapper/abstractmapper.cpp \
    mapper/usermapper.cpp \
    model/user.cpp

HEADERS  += mainwindow.h \
    cdnview.h \
    abstractserver.h \
    cdn.h \
    model/solution.h \
    model/runresult.h \
    model/run.h \
    dedicatedrunserver.h \
    run_server_view.h \
    helpers.hxx \
    servlet/abstractServlet.hpp \
    contesthostserver.h \
    servlet/errorservlet.hpp \
	contesthost_server_view.h \
    mapper/abstractmapper.h \
    constants.hxx \
    mapper/usermapper.h \
    model/user.h

INCLUDEPATH += qhttpserver/src \
	qhttpserver/http-parser

#We dont need dll files hence this hack
DEFINES += Q_HTTP_SERVER_API
DEFINES += "QHTTPSERVER_API=\"\""
##


LIBS      += -lqhttp -lsqlite3


FORMS    += mainwindow.ui \
    cdnview.ui \
    run_server_view.ui \
    contesthost_server_view.ui

CONFIG -= c++11 -frtti -fexceptions
CONFIG += thread warn_off
QMAKE_CXXFLAGS += -std=c++1y
QMAKE_LFLAGS += -shared-libgcc
QMAKE_LINK += -shared-libgcc



#QMAKE_POST_LINK += $(COPY_DIR) $$system_path($$PWD/data) $$system_path($$OUT_PWD/)


#DEFINES += "APPROOT=\"../../..\""
DEFINES += "APPROOT=\"$$PRJDIR\""

#ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
