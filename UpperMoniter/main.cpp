#include "UpperMoniter.h"
#include <QtWidgets/QApplication>
#include"DeviceData.h"
#include"DeviceStatus.h"
#include<vector>

vector<DeviceStatus> DSs;

//一条DD传入DS类示例
bool test(DeviceData DD) {
    DeviceStatus DS = new DeviceStatus();
    DS.setDate(DD.Date);
    DS.setTime(DD.Time);
    DS.setEvent(DD.Event);
    DS.setEventDescription(DD.EventDescription);
    DS.setNetaddress(DD.NetAddress);
    DS.setLoop(DD.Loop);
    DS.setDeviceAddres(DD.DeviceAddress);
    DSs.emplace_back(DS);
    delete(DS);
    return true;
}

//获取DS类元素示例
bool getTest(vector<DeviceStatus> DSs) {
    std::string Time = DSs[0].getTime();


    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UpperMoniter w;
    w.show();
    return a.exec();
}
