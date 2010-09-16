#ifndef DBUS_DEVICES_MANAGER_H
#define DBUS_DEVICES_MANAGER_H

#include <QList>
#include <QtDBus/QtDBus>

#include "dbus_device_service.h"

class dbus_devices_manager
{

 private:
  QList<dbus_device_service *> m_devices;
  const QSettings &m_settings;

 public:
  dbus_devices_manager(const QSettings &settings) : m_settings(settings) {}
  void start();
  void initialize();
};

#endif
