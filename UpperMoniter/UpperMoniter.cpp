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
	int BaudRate = ui.baudRateComboBox->currentText().toInt();
	if (m_serialPort == nullptr)
		m_serialPort = new QSerialPort(); //实例化串口类一个对象
	m_serialPort->setPortName(Serial);
	
	if (ui.openSerialPushButton->isCheckable())
	{
		//打开串口
		if (ui.openSerialPushButton->isChecked())
		{
			/*插入代码*/
			if(!m_serialPort->open(QIODevice::ReadWrite))//用ReadWrite 的模式尝试打开串口
			{
				qDebug()<<m_serialPortName[0]<<"打开失败!";
				return;
			}
			m_serialPort->setBaudRate(BaudRate,QSerialPort::AllDirections);//设置波特率和读写方向
			m_serialPort->setDataBits(QSerialPort::Data8);      //数据位为8位
			m_serialPort->setFlowControl(QSerialPort::NoFlowControl);//无流控制
			m_serialPort->setParity(QSerialPort::NoParity); //无校验位
			m_serialPort->setStopBits(QSerialPort::OneStop); //一位停止位

			connect(m_serialPort,SIGNAL(readyRead()),this,SLOT(serial_read()));

			ui.openSerialPushButton->setText(QStringLiteral("打开串口"));
		}
		//关闭串口
		else
		{
			/*插入代码*/
			m_serialPort->close();
			ui.openSerialPushButton->setText(QStringLiteral("关闭串口"));
		}

	}
	
	//QMessageBox::about(NULL, "tip", "ok");
}

void UpperMoniter::serial_read()
{
	QByteArray info = m_serialPort->readAll();
	hexData += info.toHex();
	for (int i = 0; i < hexData.size(); ++i)      //去除'\0'
		if (hexData[i] == 0x00)
			hexData[i] = 0xff;
	std::string strbuf((char *)(hexData));

	QString qstr = QString::fromStdString(strbuf);
	QStringList qsl = qstr.split("\r\n");		//划分数据白  ‘0x0d 0x0a’
	
	for(int i = 0; i< qsl.size();++i)	
	{
		QString data = qsl.at(i);
		qDebug()<<"data ="<< data<<"\r\n"; 
	}
	parse_ascii(data.toStdString())


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
