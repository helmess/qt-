/****************************************************************
*	文件名称：DeviceStatus.h
*	功能：提供字符串解析数据封装类声明
*	完成日期：
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
		std::string getDeviceCoding(void);	//设备编号

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
		std::string Date;	//日期
		std::string Time;	//时间
		std::string Event;	//事件
		std::string EventDescription;	//事件描述
		std::string Netaddress;	//网络地址
		std::string Loop;	//回路
		std::string DeviceAddress;	//设备地址
	};

	typedef std::vector<DeviceStatus> DeviceVec;
#endif // !__DeviceStatus__