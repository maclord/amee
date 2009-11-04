#ifndef WEBCAM_SERVICE_H
#define WEBCAM_SERVICE_H

#include "../dbus_device_service.h"

#define WEBCAM_SERVICE_NAME "Webcam"

class webcam_service: public dbus_device_service
{
      
 public:
  QString name();
  void register_instance();

};

#endif
