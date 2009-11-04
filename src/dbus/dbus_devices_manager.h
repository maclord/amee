#ifndef DBUS_DEVICES_MANAGER_H
#define DBUS_DEVICES_MANAGER_H

#include <QList>
#include <QtDBus/QtDBus>

#include "dbus_device_service.h"

class dbus_devices_manager
{

 private:
  QList<dbus_device_service *> devices;

 public:
  dbus_devices_manager();
  void start();
  void initialize();
};

#endif
