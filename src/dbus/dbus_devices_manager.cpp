#include <QDebug>
#include <QtDBus/QtDBus>

#include "dbus_devices_manager.h"
#include "arduino/arduino_service.h"
#include "webcam/webcam_service.h"
#include "accelerometer/accelerometer_service.h"
#include "gps/gps_service.h"

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
  
  if(m_settings.value("dbus.arduino.enable").toBool())
	m_devices.push_back(new arduino_service());
  if(m_settings.value("dbus.webcam.enable").toBool())
	m_devices.push_back(new webcam_service());
  if(m_settings.value("dbus.accelerometer1.enable").toBool())
	m_devices.push_back(new accelerometer_service("1", m_settings.value("dbus.accelerometer1.device").toByteArray()));
  if(m_settings.value("dbus.accelerometer2.enable").toBool())
	m_devices.push_back(new accelerometer_service("2", m_settings.value("dbus.accelerometer2.device").toByteArray()));
  if(m_settings.value("dbus.gps.enable").toBool())
	m_devices.push_back(new gps_service());

  for(int i=0; i<m_devices.size(); i++)
    {
      if(m_devices[i]->initialize())
	qDebug() << "OK";
      else
	qDebug() << "Fail";
    }
}

void dbus_devices_manager::start()
{
  qDebug() << "Starting D-Bus devices manager";

  for(int i=0; i<m_devices.size(); i++)
    {
      m_devices[i]->start();
    }
}

