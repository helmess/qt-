/****************************************************************
*	�ļ����ƣ�DeviceStatus.h
*	���ܣ��ṩ�ַ����������ݷ�װ������
*	������ڣ�
******************************************************************/
#pragma once

#ifndef __DeviceStatus__
#define __DeviceStatus__


#include<stdexcept>
#include<string>
#include<unordered_set>
#include<fstream>
#include<iostream>
#include<streambuf>


	class DeviceStatus
	{
	public:
		DeviceStatus();
		~DeviceStatus();

		std::string getDate(void);
		std::string getTime(void);
		std::string getDeviceAddress(void);
		std::string getEvent(void);
		std::string getEventDescription(void);
		std::string getNetaddress(void);
		std::string getLoop(void);
		std::string getDeviceCoding(void);	//�豸���

		void setDate(std::string str);
		void setTime(std::string str);
		void setEvent(std::string str);
		void setEventDescription(std::string str);
		void setNetaddress(std::string str);
		void setLoop(std::string str);
		void setDeviceAddres(std::string str);
		bool save2Excel(std::string address);

	private:

	public:
		std::string Date;	//����
		std::string Time;	//ʱ��
		std::string Event;	//�¼�
		std::string EventDescription;	//�¼�����
		std::string Netaddress;	//�����ַ
		std::string Loop;	//��·
		std::string DeviceAddress;	//�豸��ַ
	};

	typedef std::vector<DeviceStatus> DeviceVec;
#endif // !__DeviceStatus__