#include "UpperMoniter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UpperMoniter w;
    w.show();
    return a.exec();
}
