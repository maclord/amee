#include <QDebug>
#include <QtDBus/QtDBus>

#include "dbus_devices_manager.h"
#include "arduino/arduino_service.h"
#include "webcam/webcam_service.h"
#include "accelerometer/accelerometer_service.h"
#include "gps/gps_service.h"

dbus_devices_manager::dbus_devices_manager()
{

}

void dbus_devices_manager::initialize()
{
  qDebug() << "Initializing D-Bus devices manager";

  qDebug() << "  Connecting to the D-Bus session bus";

  if (!QDBusConnection::sessionBus().isConnected()) {
    fprintf(stderr, "Cannot connect to the D-Bus session bus.\n"
	    "To start it, run:\n"
	    "\teval `dbus-launch --auto-syntax`\n");
    exit(1);
  }
  
  devices.push_back(new arduino_service());
  devices.push_back(new webcam_service());
  devices.push_back(new accelerometer_service("1", "/dev/input/event2"));
  devices.push_back(new accelerometer_service("2", "/dev/input/event3"));
  devices.push_back(new gps_service());

  for(int i=0; i<devices.size(); i++)
    {
      devices[i]->initialize();
    }
}

void dbus_devices_manager::start()
{
  qDebug() << "Starting D-Bus devices manager";

  for(int i=0; i<devices.size(); i++)
    {
      devices[i]->start();
    }
}

