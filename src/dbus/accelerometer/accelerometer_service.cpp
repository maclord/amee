#include <QDebug>

#include "accelerometer_service.h"

struct input_event {
    struct timeval time;
    uint16_t type;
    uint16_t code;
    int32_t value;
};

bool accelerometer_service::initialize()
{
	qDebug() << "Initializing" << name();
	qDebug() << "Checking device type";
	if(!check_device_type())
		return false;
	qDebug() << "Opening device" << m_device_path;

/*	ifstream file (m_device_path, ios::in|ios::binary);
	while(1) {
	char *memblock = new char [16];
	file.seekg (0, ios::beg);
	file.read (memblock, 16);
	}
*/
QFile file(m_device_path);
if ( file.open(QIODevice::ReadOnly) ) {


while(1) {
char *memblock = new char [16];
//    QByteArray array = file.readAll();
qDebug() << "avant";
struct input_event ev;
//	file.read(reinterpret_cast<char*>ev, 16);
/**qint32 val = memblock[13];
val += (memblock[14] << 8);
val += (memblock[15] << 16);
val += (memblock[16] << 24);*

qDebug() << val;**/

qDebug() << "apres";
sleep(1);
}
//qDebug() << array;
    file.close();
//    for ( int i = 0; i < array.size(); i++ ) {
        // etc.
//    }

}

	return true;
}

bool accelerometer_service::check_device_type()
{
	QFile file(m_sys_file);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return false;
	QString line = file.readLine();
	line = line.replace(QRegExp("\n$"), QString::null);
	qDebug() << line;
	return line == m_sys_name;
}

QString accelerometer_service::name()
{
	return ACCELEROMETER_SERVICE_NAME+m_instance_name;
}

