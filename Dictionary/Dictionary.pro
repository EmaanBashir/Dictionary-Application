QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT += sql

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Data.cpp \
    Trie.cpp \
    UserDatabase.cpp \
    create.cpp \
    insert_certified.cpp \
    insert_main.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    search_certified.cpp \
    search_main.cpp \
    search_user.cpp \
    sortingalgorithm.cpp \
    update_certified.cpp \
    update_main.cpp

HEADERS += \
    Data.h \
    Trie.h \
    UserDatabase.h \
    create.h \
    insert_certified.h \
    insert_main.h \
    login.h \
    mainwindow.h \
    search_certified.h \
    search_main.h \
    search_user.h \
    sortingalgorithm.h \
    update_certified.h \
    update_main.h

FORMS += \
    create.ui \
    insert_certified.ui \
    insert_main.ui \
    login.ui \
    mainwindow.ui \
    search_certified.ui \
    search_main.ui \
    search_user.ui \
    update_certified.ui \
    update_main.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    logo.png
