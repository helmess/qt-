#ifndef __DeviceData__
#define __DeviceStatus__
#include <iostream>
#include <string>

struct DeviceData{
    DeviceData(std::string ComData);
    std::string Date;
    std::string Time;
    std::string Event;
    std::string EventDescription;
    std::string NetAddress;
    std::string Loop;
    std::string DeviceAddress;
};

#endif