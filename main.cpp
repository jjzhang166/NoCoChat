#include <QApplication>
#include "mainwindow.h"
#include "signin.h"
#include <QTextCodec.h>
#include <QDebug>
#include <QRegExp>

#include "addinfo.h"

#include "tcpnet.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    QApplication a(argc, argv);
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
    /*MainWindow w;
    w.show();
    return a.exec();*/
    QString command="<ashuodhihas><asdasd:>";
    QString pattern_1 ="(?:<)([a-zA-Z0-9_\u4e00-\u9fa5\\w]+)(?:>)";
    QRegExp reg_1(pattern_1);
    command.indexOf(reg_1);
    qDebug()<<reg_1.cap(1);
    return 0;

}
