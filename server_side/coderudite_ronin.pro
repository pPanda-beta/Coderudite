TEMPLATE = subdirs

SUBDIRS += lib/qhttp \
	lib/sqlite3	\
	lib/sqlite_modern_cpp_3_1

SUBDIRS += coderudite_ronin

coderudite_ronin.depends = lib/qhttp
