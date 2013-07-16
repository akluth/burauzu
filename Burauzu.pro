#-------------------------------------------------
#
# Project created by QtCreator 2013-07-15T11:31:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets

TARGET = Burauzu
TEMPLATE = app


SOURCES += main.cpp\
        burauzu.cpp \
    webview.cpp

HEADERS  += burauzu.h \
    webview.h

FORMS    +=

OTHER_FILES += \
    .gitignore \
    README.md
