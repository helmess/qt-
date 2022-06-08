/****************************************************************
*	文件名称：DeviceStatus.cpp
*	功能：提供字符串解析数据封装类实现程序
*	完成日期：
******************************************************************/
#include"DeviceStatus.h"


DeviceStatus::DeviceStatus(void)
{
	Date = "NULL";
	Time = "NULL";
	Event = "NULL";
	EventDescription = "NULL";
	Netaddress = "NULL";
	Loop = "NULL";
	DeviceAddress = "NULL";
	
}

DeviceStatus::~DeviceStatus(void)
{
}
std::string DeviceStatus::getDate(void) {
	return Date;
}
std::string DeviceStatus::getTime(void) {
	return Time;
}
std::string DeviceStatus::getEvent(void) {
	return Event;
}
std::string DeviceStatus::getEventDescription(void) {
	return EventDescription;
}
std::string DeviceStatus::getNetaddress(void) {
	return Netaddress;
}
std::string DeviceStatus::getLoop(void) {
	return Loop;
}
std::string DeviceStatus::getDeviceAddress(void) {
	return DeviceAddress;
}
std::string DeviceStatus::getDeviceCoding(void) {
	return Netaddress + Loop + DeviceAddress;
}

void DeviceStatus::setDate(std::string str) {
	Date = str;
}
void DeviceStatus::setTime(std::string str) {
	Time = str;
}
void DeviceStatus::setEvent(std::string str) {
	Event = str;
}
void DeviceStatus::setEventDescription(std::string str) {
	EventDescription = str;
}
void DeviceStatus::setNetaddress(std::string str) {
	Netaddress = str;
}
void DeviceStatus::setLoop(std::string str) {
	Loop = str;
}
void DeviceStatus::setDeviceAddres(std::string str) {
	DeviceAddress = str;
}
bool DeviceStatus::save2Excel(std::string address) {
	std::ofstream oFile;
	oFile.open(address, std::ios::app | std::ios::out);
	oFile << Date << "," << Time << "," << Event << "," << EventDescription << "," << "'" + Netaddress << "," << "'" + Loop << "," << "'" + DeviceAddress << std::endl;
	oFile.close();
	return true;
}