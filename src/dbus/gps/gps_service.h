#ifndef GPS_SERVICE_H
#define ACCELEROMETER_SERVICE_H

#include "../dbus_device_service.h"

#define GPS_SERVICE_NAME "GPS"

class gps_service: public dbus_device_service
{

 public:
  QString name();
  void register_instance();

};

#endif
