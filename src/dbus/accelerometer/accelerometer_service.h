#ifndef ACCELEROMETER_SERVICE_H
#define ACCELEROMETER_SERVICE_H

#include "../dbus_device_service.h"

#define ACCELEROMETER_SERVICE_NAME "Accelerometer"

class accelerometer_service: public dbus_device_service
{

 private:
  QString instance_name;
  QString device_path;

 public:
  accelerometer_service(const QString &_instance_name, const QString &_device_path) : instance_name(_instance_name), device_path(_device_path) {};
  QString name();
  void register_instance();

};

#endif
