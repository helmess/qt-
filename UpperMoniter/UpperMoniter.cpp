#include "UpperMoniter.h"
#include<qmessagebox.h>
#include<qfiledialog.h>
UpperMoniter::UpperMoniter(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	QStringList tableHead;
	tableHead << u8"����" << u8"ʱ��" << u8"�¼�" << u8"�¼�����" << u8"�����ַ" << u8"��·" << u8"�豸��ַ";
	ui.deviceStatusTableWidget->setColumnCount(7);
	ui.deviceStatusTableWidget->setHorizontalHeaderLabels(tableHead);
	ui.baudRateComboBox->addItems(QStringList() << tr("115200") << tr("9600"));
	ui.openSerialPushButton->setCheckable(true);
	ui.openSerialPushButton->setChecked(false);
	ui.openSerialPushButton->setText(QStringLiteral("�رմ���"));
	connect(ui.openSerialPushButton, SIGNAL(clicked()), this, SLOT(serial_connect()));//�򿪴���
	connect(ui.queryPushButton, SIGNAL(clicked()), this, SLOT());//�����ѯ��ť
	connect(ui.exportPushButton, SIGNAL(clicked()), this, SLOT(getFileName()) );//���������ť

}
void UpperMoniter::getFileName() {
	QString curPath = QCoreApplication::applicationDirPath();
	QString aFileName = QFileDialog::getOpenFileName(this, u8"ѡ���ļ�", curPath, tr(";;All file(*.*)"));
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
		//�򿪴���
		if (ui.openSerialPushButton->isChecked())
		{
			/*�������*/
			ui.openSerialPushButton->setText(QStringLiteral("�򿪴���"));
		}
		//�رմ���
		else
		{
			/*�������*/
			ui.openSerialPushButton->setText(QStringLiteral("�رմ���"));
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
	for (int i = 0; i < sizeof(data); ++i)      //ȥ��'\0'
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
