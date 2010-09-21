#ifndef ACCELEROMETER_SERVICE_H
#define ACCELEROMETER_SERVICE_H

#include "../dbus_device_service.h"

#define ACCELEROMETER_SERVICE_NAME "Accelerometer"

class accelerometer_service: public dbus_device_service
{

 private:
  QString m_instance_name;
  QString m_device_path;
  QString m_sys_file;
  QString m_sys_name;
  bool check_device_type();

 public:
  accelerometer_service(const QString &instance_name, const QString &device_path, const QString &sys_file, const QString &sys_name) : 
	m_instance_name(instance_name), m_device_path(device_path), m_sys_file(sys_file), m_sys_name(sys_name) {};
  QString name();
  bool initialize();
};

#endif
