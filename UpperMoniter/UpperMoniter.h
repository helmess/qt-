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
	void serial_connect();//��������
	string get_device_ascii(string query_code);
	DeviceStatus parse_ascii(string str);//���ݽ������������յ�����Ϊһ���豸ʵ��
	string parse_Event(string str);
	string parse_EventDescription(string str);
	string parse_Netaddress(string str);
	string parse_Loop(string str);
	string parse_DeviceAddres(string str);
	string parse_DeviceCoding(string str);
	string parse_Date(string str);
	string parse_Time(string str);
	void export_all_device();//��������
	void display_all_device();//��ʾ�����豸����

public:
	DeviceVec dvec;


private:
    Ui::UpperMoniterClass ui;
};
