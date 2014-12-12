#include <QApplication>
#include "mainwindow.h"
#include "signin.h"
#include <QTextCodec.h>
#include <QDebug>
#include <QRegExp>
#include "tcpnet.h"

int main(int argc, char *argv[])
{
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
//    QApplication a(argc, argv);
//    MainWindow w_main;
//    Signin d_sign;
//    d_sign.show();
//    if(d_sign.exec()==QDialog::Accepted)
//    {
//        w_main.show();
//        return a.exec();
//    }
//    else
//    {
//       return 0;
//    }

    TcpNet tcp;
    tcp.getLocalAddress();

}
