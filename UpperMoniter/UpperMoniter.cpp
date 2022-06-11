#include "UpperMoniter.h"
#include<qmessagebox.h>
#include<qfiledialog.h>

QStringList get_avail_sp_() noexcept
{
	QStringList list_avail_sp;

	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
	{
		QSerialPort serial;
		serial.setPort(info);
		if (serial.open(QIODevice::ReadWrite))
		{
			list_avail_sp.append(serial.portName());
			serial.close();
		}
	}

	return list_avail_sp;
}


void printdevice(DeviceStatus device)
{
	cout << device.getDate() << endl;
	cout << device.getDeviceAddress() << endl;
	cout << device.getDeviceCoding() << endl;
	cout << device.getEvent() << endl;
	cout << device.getEventDescription() << endl;
	cout << device.getLoop() << endl;
	cout << device.getNetaddress() << endl;
	cout << device.getTime() << endl;

}
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
	ui.openSerialPushButton->setText(QStringLiteral("打开串口"));
	m_serialPort = new QSerialPort(); //实例化串口类一个对象
	connect(ui.openSerialPushButton, SIGNAL(clicked()), this, SLOT(serial_connect()));//打开串口
	connect(ui.queryPushButton, SIGNAL(clicked()), this, SLOT());//点击查询按钮
	connect(ui.exportPushButton, SIGNAL(clicked()), this, SLOT(getFileName()) );//点击导出按钮
	connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(serial_read()));

	ui.serialComboBox->addItems(get_avail_sp_());

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
	int BaudRate = ui.baudRateComboBox->currentText().toInt();

	
	m_serialPort->setPortName(Serial);
	
	if (ui.openSerialPushButton->isCheckable())
	{
		//打开串口
		if (ui.openSerialPushButton->isChecked())
		{
			/*插入代码*/
			if(!m_serialPort->open(QIODevice::ReadWrite))//用ReadWrite 的模式尝试打开串口
			{
				qDebug()<<Serial<<"打开失败!";
				return;
			}
			m_serialPort->setBaudRate(BaudRate,QSerialPort::AllDirections);//设置波特率和读写方向
			m_serialPort->setDataBits(QSerialPort::Data8);      //数据位为8位
			m_serialPort->setFlowControl(QSerialPort::NoFlowControl);//无流控制
			m_serialPort->setParity(QSerialPort::NoParity); //无校验位
			m_serialPort->setStopBits(QSerialPort::OneStop); //一位停止位
			
			

			ui.openSerialPushButton->setText(QStringLiteral("关闭串口"));
		}
		//关闭串口
		else
		{
			/*插入代码*/
			m_serialPort->close();
			ui.openSerialPushButton->setText(QStringLiteral("打开串口"));
		}

	}
	
	//QMessageBox::about(NULL, "tip", "ok");
}

void UpperMoniter::serial_read()
{
	QByteArray hexData = m_serialPort->readAll();
	
	cout << hexData.toStdString() << endl;
	for (int i = 0; i < hexData.size(); ++i)      //去除'\0'
		if (char(hexData[i]) == 0x00)
			hexData[i] = 0xff;
	std::string strbuf=hexData.toStdString();

	QString qstr = QString::fromStdString(strbuf);
	QStringList qsl = qstr.split("\r\n");		//划分数据白  ‘0x0d 0x0a’
	
	for(int i = 0; i< qsl.size();++i)	
	{
		QString data = qsl.at(i);
		parse_ascii(data.toStdString());
		qDebug()<<"data ="<< data<<"\r\n"; 
	}
	
}

DeviceStatus UpperMoniter::parse_ascii(string data)
{
	// for (int i = 0; i < sizeof(data); ++i)      //去除'\0'
	// 	if (data[i] == 0x00)
	// 		data[i] = 0xff;

	// std::string b((char *)(data));
	DeviceData a(data);
	DeviceStatus device;
	device.setDate(a.Date);
	device.setDeviceAddres(a.DeviceAddress);
	device.setEvent(a.Event);
	device.setEventDescription(a.EventDescription);
	device.setLoop(a.Loop);
	device.setNetaddress(a.NetAddress);
	device.setTime(a.Time);
	printdevice(device);
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
