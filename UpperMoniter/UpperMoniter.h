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
	void serial_connect();//串口链接
	void getFileName();
	void serial_read();
public :
	
	

	DeviceStatus parse_ascii(string data);//数据解析，解析接收的数据为一个设备实例
	
	void export_all_device();//导出数据
	void display_all_device();//显示所有设备数据

public:
	DeviceVec m_dvec;
	unsigned char *m_serial_data;
	QSerialPort     *m_serialPort = nullptr; 
private:
    Ui::UpperMoniterClass ui;
};
