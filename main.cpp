#include <QApplication>
#include "mainwindow.h"
#include "signin.h"
#include <QTextCodec.h>
#include <QDebug>
#include <QRegExp>
#include "handle.h"
#include "udpnet.h"
#include "addinfo.h"

#include "tcpnet.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    QApplication a(argc, argv);
    Handle handle;
    UDPNet udp;
    MainWindow w_main;
    w_main.setUdp(&udp);
    w_main.setHandle(&handle);
    return a.exec();


}
