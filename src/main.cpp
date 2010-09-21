#include <QDebug>
#include <QCoreApplication>

#include "dbus/dbus_devices_manager.h"

#define VERSION "0.1"
#define CONFIG_FILE "amee.conf"

 void myMessageOutput(QtMsgType type, const char *msg)
 {
     switch (type) {
     case QtDebugMsg:
         fprintf(stderr, "Debug: %s\n", msg);
         break;
     case QtWarningMsg:
         fprintf(stderr, "Warning: %s\n", msg);
         break;
     case QtCriticalMsg:
         fprintf(stderr, "Critical: %s\n", msg);
         break;
     case QtFatalMsg:
         fprintf(stderr, "Fatal: %s\n", msg);
         abort();
     }
 }

int main(int argc, char * argv[])
{
	qInstallMsgHandler(myMessageOutput);

	qDebug() << "Starting AMEE - version" << VERSION << "compiled" << __DATE__ << __TIME__;

  QCoreApplication app(argc, argv);
  QSettings settings(CONFIG_FILE, QSettings::IniFormat);

  dbus_devices_manager manager(settings);
  manager.initialize();
  manager.start();

  app.exec();
  return 0;
}
