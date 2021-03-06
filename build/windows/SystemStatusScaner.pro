# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = SystemStatusScaner
DESTDIR = ./Win32/Debug
QT += core widgets gui
CONFIG += debug
DEFINES += WIN64 QT_DLL QT_WIDGETS_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug \
    $(ProjectDir)../../src/include
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
HEADERS += ../../src/include/gui/main_widget.h \
    ../../src/include/gui/mygraphicsview.h \
    ../../src/include/core/data_calculator.h \
    ../../src/include/core/test_perfomance_interface.h \
    ../../src/include/core/calculator_cpu.h \
    ../../src/include/core/calculator_ram.h \
    ../../src/include/core/bds_test.h \
    ../../src/include/core/checker.h \
    ../../src/include/core/data_storage.h \
    ../../src/include/core/linear_difference_test.h
SOURCES += ../../src/src/main.cpp \
    ../../src/src/gui/main_widget.cpp \
    ../../src/src/gui/mygraphicsview.cpp \
    ../../src/src/core/bds_test.cpp \
    ../../src/src/core/calculator_cpu.cpp \
    ../../src/src/core/calculator_ram.cpp \
    ../../src/src/core/checker.cpp \
    ../../src/src/core/data_storage.cpp \
    ../../src/src/core/linear_difference_test.cpp
FORMS += ../../design/main_window_widget.ui
RESOURCES += ../../etc/resources.qrc
