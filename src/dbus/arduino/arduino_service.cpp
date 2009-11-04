#include <QDebug>

#include "arduino_service.h"

arduino_service::arduino_service()
{

}

QString arduino_service::name()
{
  return ARDUINO_SERVICE_NAME;
}

/**void arduino_service::register_instance()
{
  // TODO : factorise
  QDBusConnection::sessionBus().registerObject("/", this, QDBusConnection::ExportAllSlots);
  }**/

/**
void arduino_service::set_xpos(const int &xpos)
{
  qDebug() << "xpos updated to" << xpos;
}
**/
