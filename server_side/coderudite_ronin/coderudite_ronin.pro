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
	model/user.cpp	\
    mapper/qobjecthelper.cpp \
    model/qstringex.cpp \
    service/userservice.cpp \
    servlet/loginservlet.cpp \
    servlet/abstractjsonservlet.cpp \
    mapper/sessionmapper.cpp \
    model/session.cpp \
    service/sessionservice.cpp \
    service/fileservice.cpp \
    servlet/problemservlet.cpp \
    service/eventservice.cpp \
    servlet/sseservlet.cpp \
    model/submission.cpp

HEADERS  += mainwindow.h \
    cdnview.h \
    abstractserver.h \
    cdn.h \
    model/solution.h \
    model/runresult.h \
    model/run.h \
    dedicatedrunserver.h \
    run_server_view.h \
#    helpers.hxx \
    servlet/abstractServlet.hpp \
    contesthostserver.h \
    servlet/errorservlet.hpp \
	contesthost_server_view.h \
    mapper/abstractmapper.h \
#    constants.hxx \
    mapper/usermapper.h \
	model/user.h	\
    mapper/qobjecthelper.h \
    model/qstringex.h \
#    model/bean.hxx \
    service/userservice.h \
    servlet/loginservlet.hpp \
    servlet/abstractjsonservlet.hpp \
    mapper/sessionmapper.h \
    model/session.h \
    service/sessionservice.h \
    service/fileservice.h \
    servlet/problemservlet.hpp \
    service/eventservice.h \
    servlet/sseservlet.hpp \
    model/submission.h

PRECOMPILED_HEADER +=     model/bean.hxx \
	constants.hxx \
	helpers.hxx \
	$$PRJDIR/lib/sqlite3/sqlite3.h	\
	$$PRJDIR/lib/sqlite_modern_cpp/sqlite_modern_cpp.h	\
	$$PRJDIR/lib/sqlite_modern_cpp/collectors.h


INCLUDEPATH += qhttpserver/src \
	qhttpserver/http-parser

#We dont need dll files hence this hack
DEFINES += Q_HTTP_SERVER_API
DEFINES += "QHTTPSERVER_API=\"\""
##


LIBS      += -lqhttp -lsqlite3 -shared-libgcc


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
#ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

DEFINES += "APPROOT=\"$$PRJDIR\""
