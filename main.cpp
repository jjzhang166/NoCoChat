#include <QApplication>
#include "mainwindow.h"
#include "signin.h"
#include <QTextCodec.h>
#include <QDebug>
#include <QRegExp>
#include "chat.h"

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
    Chat chat;
    chat.show();
    return a.exec();

    /*
    QString pattern="(?:\\[length=)(\\d+)(?:\\])";
    QRegExp reg(pattern);
    QString message="[length=32]<loginuser><userid:>用户名<name:>名称<password:>密码";
    qDebug()<<message.indexOf(reg);
    qDebug()<<reg.cap(1);
    qDebug()<<message.split(reg);
    return a.exec();
    */

}
