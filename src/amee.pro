######################################################################
# Automatically generated by qmake (2.01a) jeu. sept. 16 00:17:41 2010
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . dbus dbus/accelerometer dbus/arduino dbus/gps dbus/webcam
INCLUDEPATH += . dbus dbus/arduino dbus/webcam dbus/accelerometer dbus/gps
QT += dbus

# Input
HEADERS += dbus/dbus_device_service.h \
           dbus/dbus_devices_manager.h \
           dbus/accelerometer/accelerometer_service.h \
           dbus/arduino/arduino_service.h \
           dbus/gps/gps_service.h \
           dbus/webcam/webcam_service.h
SOURCES += main.cpp \
           dbus/dbus_device_service.cpp \
           dbus/dbus_devices_manager.cpp \
           dbus/accelerometer/accelerometer_service.cpp \
           dbus/arduino/arduino_service.cpp \
           dbus/gps/gps_service.cpp \
           dbus/webcam/webcam_service.cpp