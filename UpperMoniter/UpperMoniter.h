#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UpperMoniter.h"
#include<vector>
#include"DeviceStatus.h"
#include"DeviceData.h"
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>

using namespace std;




class UpperMoniter : public QMainWindow
{
    Q_OBJECT

public:
    UpperMoniter(QWidget *parent = Q_NULLPTR);
public slots:
	void serial_connect();//��������
	void getFileName();
	void serial_read();
public :
	
	

	DeviceStatus parse_ascii(string data);//���ݽ������������յ�����Ϊһ���豸ʵ��
	
	void export_all_device();//��������
	void display_all_device();//��ʾ�����豸����

public:
	DeviceVec m_dvec;
	unsigned char *m_serial_data;
	QSerialPort     *m_serialPort = nullptr; 
private:
    Ui::UpperMoniterClass ui;
};
