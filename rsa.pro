TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++0x -pthread
LIBS += -pthread -L/usr/boost

SOURCES += \
        RSA.cpp \
        converter.cpp \
        main.cpp \
        prime.cpp

HEADERS += \
    RSA.h \
    common.h \
    converter.h \
    prime.h
