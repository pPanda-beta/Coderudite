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
    qhttpserver/src/qhttpconnection.cpp \
    qhttpserver/src/qhttprequest.cpp \
    qhttpserver/src/qhttpresponse.cpp \
    qhttpserver/src/qhttpserver.cpp \
    qhttpserver/http-parser/http_parser.c \
    cdnview.cpp \
    abstractserver.cpp \
    cdn.cpp \
    model/solution.cpp \
    model/runresult.cpp \
    model/run.cpp \
    dedicatedrunserver.cpp \
    run_server_view.cpp

HEADERS  += mainwindow.h \
    qhttpserver/src/qhttpconnection.h \
    qhttpserver/src/qhttprequest.h \
    qhttpserver/src/qhttpresponse.h \
    qhttpserver/src/qhttpserver.h \
    qhttpserver/src/qhttpserverapi.h \
    qhttpserver/src/qhttpserverfwd.h \
    qhttpserver/http-parser/http_parser.h \
    cdnview.h \
    abstractserver.h \
    cdn.h \
    model/solution.h \
    model/runresult.h \
    model/run.h \
    dedicatedrunserver.h \
    run_server_view.h \
    helpers.hxx

INCLUDEPATH += qhttpserver/src \
	qhttpserver/http-parser

#We dont need dll files hence this hack
DEFINES += Q_HTTP_SERVER_API
DEFINES += "QHTTPSERVER_API=\"\""
##


LIBS      += -lqhttp


FORMS    += mainwindow.ui \
    cdnview.ui \
    run_server_view.ui

CONFIG -= c++11 -frtti -fexceptions
CONFIG += thread warn_off
QMAKE_CXXFLAGS += -std=c++1y
QMAKE_LFLAGS += -shared-libgcc
QMAKE_LINK += -shared-libgcc



#QMAKE_POST_LINK += $(COPY_DIR) $$system_path($$PWD/data) $$system_path($$OUT_PWD/)


#DEFINES += "SITEROOT=\"../../..\""
DEFINES += "SITEROOT=\"$$PRJDIR\""

#ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
