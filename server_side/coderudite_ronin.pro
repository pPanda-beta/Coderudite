TEMPLATE = subdirs

SUBDIRS += lib/qhttp
SUBDIRS += coderudite_ronin

coderudite_ronin.depends = lib/qhttp
