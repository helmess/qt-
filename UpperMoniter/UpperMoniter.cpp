#include "UpperMoniter.h"

UpperMoniter::UpperMoniter(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void UpperMoniter::serial_connect()
{
}

unsigned char * UpperMoniter::serial_read()
{
	return nullptr;
}

DeviceStatus UpperMoniter::parse_ascii(unsigned char * data)
{
	for (int i = 0; i < sizeof(data); ++i)      //È¥³ý'\0'
		if (data[i] == 0x00)
			data[i] = 0xff;

	std::string b((char *)(data));
	DeviceData a(b);
	DeviceStatus device;
	device.setDate(a.Date);
	device.setDeviceAddres(a.DeviceAddress);
	device.setEvent(a.Event);
	device.setEventDescription(a.EventDescription);
	device.setLoop(a.Loop);
	device.setNetaddress(a.NetAddress);
	device.setTime(a.Time);

	m_dvec.push_back(device);

	return device;
}


void UpperMoniter::export_all_device()
{
}

void UpperMoniter::display_all_device()
{
}

string string2ascii(string str)
{
	QString qstr = QString::fromStdString(str);
	QStringList qsl = qstr.split(" ");
	

	return string();
}
