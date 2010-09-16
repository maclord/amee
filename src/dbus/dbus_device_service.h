#ifndef DBUS_DEVICE_SERVICE_H
#define DBUS_DEVICE_SERVICE_H

#include <QObject>
#include <QtDBus/QtDBus>

#define DBUS_SERVICE_PREFIX "net.taora.amee.DBus."

class dbus_device_service: public QObject
{

  Q_OBJECT

 public:
  dbus_device_service();
  virtual void start();
  virtual bool initialize();
  virtual QString name() = 0;
  virtual QString service_name();
  //  virtual void register_instance() = 0;

  public slots:
  Q_SCRIPTABLE void set_xpos(const int &xpos);

};

#endif
