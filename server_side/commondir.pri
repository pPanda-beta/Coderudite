# specifying common dirs

# comment following line to build the lib as static library
DEFINES *= QHTTP_DYNAMIC_LIB
# comment following line to trim client classes from build
DEFINES *= QHTTP_HAS_CLIENT

DEFINES *= SQLITE_OMIT_LOAD_EXTENSION

# Qt5.5.1 on OSX needs both c++11 and c++14!! the c++14 is not enough
CONFIG  += c++11 c++14

unix {
    TEMPDIR      = $$PRJDIR/tmp/unix/$$TARGET
    macx:TEMPDIR = $$PRJDIR/tmp/osx/$$TARGET
}

win32 {
    TEMPDIR  = $$PRJDIR/tmp/win32/$$TARGET
    DEFINES += _WINDOWS WIN32_LEAN_AND_MEAN NOMINMAX
}


DESTDIR      = $$PRJDIR/xbin
MOC_DIR      = $$TEMPDIR
OBJECTS_DIR  = $$TEMPDIR
RCC_DIR      = $$TEMPDIR
UI_DIR       = $$TEMPDIR/Ui
LIBS        += -L$$PRJDIR/xbin

INCLUDEPATH += . \
	$$PRJDIR/lib $$PRJDIR/lib/qhttp \
	$$PRJDIR/lib/sqlite3 \
	$$PRJDIR/lib/sqlite_modern_cpp_3_1
#INCLUDEPATH +=  . $$PRJDIR/lib/qhttp $$PRJDIR/lib/http-parser ..

