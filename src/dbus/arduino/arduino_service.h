#ifndef ARDUINO_SERVICE_H
#define ARDUINO_SERVICE_H

#include "../dbus_device_service.h"

#define ARDUINO_SERVICE_NAME "Arduino"

class arduino_service: public dbus_device_service
{
      
 public:
  arduino_service();
  QString name();
  //  void register_instance();
  /**
  public slots:
  Q_SCRIPTABLE void set_xpos(const int &xpos);
  **/
};

#endif
