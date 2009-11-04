#include <QDebug>
#include <QtCore/QCoreApplication>

#include "dbus/dbus_devices_manager.h"

int main(int argc, char * argv[])
{
  qDebug() << "Starting AMEE";

  QCoreApplication app(argc, argv);

  dbus_devices_manager manager;
  manager.initialize();
  manager.start();

  app.exec();
  return 0;
}
