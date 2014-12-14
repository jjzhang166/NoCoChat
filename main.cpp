#include <QApplication>
#include "mainwindow.h"
#include "signin.h"
#include <QTextCodec.h>
#include <QDebug>
#include <QRegExp>
#include <QStringList>
#include "tcpnet.h"
#include "handle.h"

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

//    //    正则规范：提取<TYPE：>信息 中的TYPE和信息
//        QString pattern ="(?:<userid:>)";
//        QRegExp reg(pattern);
//        //QString pattern="(?:<)([a-zA-Z0-9_\u4e00-\u9fa5\\w]+)(?::>)([a-zA-Z0-9_\u4e00-\u9fa5\\w]+)";
//        QString message="<loginuser><userid:>用户名<name:>名称<password:>密码<userid:>用户名<name:>名称<password:>密码<userid:>用户名<name:>名称<password:>密码";
//        QStringList list=message.split(reg);
//        for(int i=1;i<list.size();i++)
//        {
//            list[i]=list[0]+"<userid:>"+list[i];
//        }
//        list.pop_front();
//        qDebug()<<list;

//    TcpNet tcp;
//    Handle handle;
//    tcp.tcpconnect("172.16.107.5",8002);
//    QString command="<getaddlist><userid:>jancojie";
//    command="[length="+QString::number(command.size())+"]"+command;
//    tcp.send(command);
//    qDebug()<<handle.getCommand(handle.changeMessage(tcp.read()),"userid");
    return 0;

}
