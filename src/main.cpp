#include <QDebug>
#include <QCoreApplication>

#include "dbus/dbus_devices_manager.h"

#define VERSION "0.1"
#define CONFIG_FILE "amee.conf"

int main(int argc, char * argv[])
{
  qDebug() << "Starting AMEE - version" << VERSION << "compiled" << __DATE__ << __TIME__;

  QCoreApplication app(argc, argv);
  QSettings settings(CONFIG_FILE, QSettings::IniFormat);

  dbus_devices_manager manager(settings);
  manager.initialize();
  manager.start();

  app.exec();
  return 0;
}
