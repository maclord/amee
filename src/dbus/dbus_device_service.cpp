#include <QDebug>
#include <QtDBus/QtDBus>

#include "dbus_device_service.h"

dbus_device_service::dbus_device_service()
{

}

QString dbus_device_service::name()
{
  return "undefined device name";
}

QString dbus_device_service::service_name()
{
  return DBUS_SERVICE_PREFIX + name();
}

bool dbus_device_service::initialize()
{
	qDebug() << "  Initializing" << name();
	return true;
}

void dbus_device_service::start()
{
  qDebug() << "  Starting" << name();

  qDebug() << "    Registering service" << service_name();
  if (!QDBusConnection::sessionBus().registerService(service_name())) {
    fprintf(stderr, "%s\n",
	    qPrintable(QDBusConnection::sessionBus().lastError().message()));
  }
  
  qDebug() << "    Registering service instance";
  // register_instance();
  QDBusConnection::sessionBus().registerObject("/", this, QDBusConnection::ExportAllSlots);
}

void dbus_device_service::set_xpos(const int &xpos)
{
  qDebug() << "xpos updated to" << xpos;
}
