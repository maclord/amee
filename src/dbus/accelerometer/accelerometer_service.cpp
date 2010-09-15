#include <QDebug>

#include "accelerometer_service.h"

void accelerometer_service::register_instance()
{

}

QString accelerometer_service::name()
{
  return ACCELEROMETER_SERVICE_NAME+instance_name;
}

