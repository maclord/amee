#include <QDebug>

#include "accelerometer_service.h"

bool accelerometer_service::initialize()
{
	qDebug() << "Initializing" << name();
	qDebug() << "Checking device type";
	check_device_type();
	qDebug() << "Opening device" << device_path;
	return true;
}

bool accelerometer_service::check_device_type()
{
	
	return true;
}

QString accelerometer_service::name()
{
	return ACCELEROMETER_SERVICE_NAME+instance_name;
}

