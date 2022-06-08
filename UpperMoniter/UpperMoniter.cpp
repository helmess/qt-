#include "UpperMoniter.h"

UpperMoniter::UpperMoniter(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void UpperMoniter::serial_connect()
{
}

string UpperMoniter::get_device_ascii(string query_code)
{
	return string();
}

DeviceStatus UpperMoniter::parse_ascii(string str)
{
	DeviceStatus device;
	device.setDate(parse_Date("32 30 32 32 2E 30 35 2E 32 30 20 20 20 31 34 3A \
		32 36 3A 33 37 20 20 20 30 31 30 30 31 30 30 30"));

	return device;
}

string UpperMoniter::parse_Event(string str)
{
	return string();
}

string UpperMoniter::parse_EventDescription(string str)
{
	return string();
}

string UpperMoniter::parse_Netaddress(string str)
{
	return string();
}

string UpperMoniter::parse_Loop(string str)
{
	return string();
}

string UpperMoniter::parse_DeviceAddres(string str)
{
	return string();
}

string UpperMoniter::parse_DeviceCoding(string str)
{
	return string();
}

string UpperMoniter::parse_Date(string str)
{


	return string();
}

string UpperMoniter::parse_Time(string str)
{
	return string();
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
