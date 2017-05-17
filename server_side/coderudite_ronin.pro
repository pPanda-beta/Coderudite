TEMPLATE = subdirs

SUBDIRS += lib/qhttp \
	lib/sqlite3	\
	lib/sqlite_modern_cpp

SUBDIRS += coderudite_ronin

SUBDIRS += test

coderudite_ronin.depends = lib/qhttp
coderudite_ronin.depends = lib/sqlite3
coderudite_ronin.depends = lib/sqlite_modern_cpp
