#include "UpperMoniter.h"
#include <QtWidgets/QApplication>
#include<qfile.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	QFile file("./main.qss");
	file.open(QIODevice::ReadOnly);
	if (file.isOpen())
	{
		QString strFile = file.readAll();
		a.setStyleSheet(strFile);
		file.close();
	}
	UpperMoniter w;
	string str = "Ò»¶þÈý";
	w.m_dvec.push_back(DeviceStatus(str, str, str, str, str, str, str));
    w.show();


    return a.exec();
}
