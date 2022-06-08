#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UpperMoniter.h"
#include<vector>
#include"DeviceStatus.h"
using namespace std;




class UpperMoniter : public QMainWindow
{
    Q_OBJECT

public:
    UpperMoniter(QWidget *parent = Q_NULLPTR);


public :
	void serial_connect();//串口链接
	string get_device_ascii(string query_code);
	DeviceStatus parse_ascii(string str);//数据解析，解析接收的数据为一个设备实例
	string parse_Event(string str);
	string parse_EventDescription(string str);
	string parse_Netaddress(string str);
	string parse_Loop(string str);
	string parse_DeviceAddres(string str);
	string parse_DeviceCoding(string str);
	string parse_Date(string str);
	string parse_Time(string str);
	void export_all_device();//导出数据
	void display_all_device();//显示所有设备数据

public:
	DeviceVec dvec;


private:
    Ui::UpperMoniterClass ui;
};
