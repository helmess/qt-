#include "UpperMoniter.h"
#include<qmessagebox.h>
#include<qfiledialog.h>
UpperMoniter::UpperMoniter(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	QStringList tableHead;
	tableHead << u8"日期" << u8"时间" << u8"事件" << u8"事件描述" << u8"网络地址" << u8"回路" << u8"设备地址";
	ui.deviceStatusTableWidget->setColumnCount(7);
	ui.deviceStatusTableWidget->setHorizontalHeaderLabels(tableHead);
	ui.baudRateComboBox->addItems(QStringList() << tr("115200") << tr("9600"));
	ui.openSerialPushButton->setCheckable(true);
	ui.openSerialPushButton->setChecked(false);
	ui.openSerialPushButton->setText(QStringLiteral("关闭串口"));
	connect(ui.openSerialPushButton, SIGNAL(clicked()), this, SLOT(serial_connect()));//打开串口
	connect(ui.queryPushButton, SIGNAL(clicked()), this, SLOT());//点击查询按钮
	connect(ui.exportPushButton, SIGNAL(clicked()), this, SLOT(getFileName()) );//点击导出按钮

}
void UpperMoniter::getFileName() {
	QString curPath = QCoreApplication::applicationDirPath();
	QString aFileName = QFileDialog::getOpenFileName(this, u8"选择文件", curPath, tr(";;All file(*.*)"));
	for (size_t i = 0; i < m_dvec.size(); i++)
	{
		m_dvec[i].save2Excel(aFileName.toStdString());
	}
}

void UpperMoniter::serial_connect()
{
	QString Serial = ui.serialComboBox->currentText();
	QString BaudRate = ui.baudRateComboBox->currentText();
	if (ui.openSerialPushButton->isCheckable())
	{
		//打开串口
		if (ui.openSerialPushButton->isChecked())
		{
			/*插入代码*/
			ui.openSerialPushButton->setText(QStringLiteral("打开串口"));
		}
		//关闭串口
		else
		{
			/*插入代码*/
			ui.openSerialPushButton->setText(QStringLiteral("关闭串口"));
		}

	}
	
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
