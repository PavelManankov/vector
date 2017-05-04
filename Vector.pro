TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

QMAKE_CXXFLAGS_DEBUG += -fsanitize=address,undefined
QMAKE_LFLAGS_DEBUG += -fsanitize=address,undefined
