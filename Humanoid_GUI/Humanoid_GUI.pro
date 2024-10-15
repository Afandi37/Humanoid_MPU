# Humanoid_GUI.pro
QT += core gui widgets quick quickwidgets serialport bluetooth quick3d

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Humanoid_GUI
TEMPLATE = app

SOURCES += \
           Main3D.cpp \
           dialog.cpp

HEADERS += dialog.h

FORMS += dialog.ui

# Jika Anda menggunakan file QML yang disertakan sebagai resource
RESOURCES += resources.qrc

DISTFILES += \
    Main3D.qml
