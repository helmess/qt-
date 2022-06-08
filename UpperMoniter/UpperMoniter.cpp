#include "UpperMoniter.h"
#include<qmessagebox.h>
UpperMoniter::UpperMoniter(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	QStringList tableHead;
	tableHead << u8"日期" << u8"时间" << u8"事件" << u8"事件描述" << u8"网络地址" << u8"回路" << u8"设备地址";
	ui.deviceStatusTableWidget->setColumnCount(7);
	ui.deviceStatusTableWidget->setHorizontalHeaderLabels(tableHead);
	connect(ui.openSerialPushButton, SIGNAL(clicked()), this, SLOT(serial_connect()));//打开串口
	connect(ui.queryPushButton, SIGNAL(clicked()), this, SLOT());//点击查询按钮
	connect(ui.exportPushButton, SIGNAL(clicked()), this, SLOT());//点击导出按钮

}

void UpperMoniter::serial_connect()
{
	//QMessageBox::about(NULL, "tip", "ok");
}

unsigned char * UpperMoniter::serial_read()
{
	return nullptr;
}

DeviceStatus UpperMoniter::parse_ascii(unsigned char * data)
{
	for (int i = 0; i < sizeof(data); ++i)      //去除'\0'
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
