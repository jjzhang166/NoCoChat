#include "handle.h"

Handle::Handle(QObject *parent) :
    QObject(parent)
{
    ip=config.getValue("ip");
    port=config.getValue("port").toInt();
}
QString Handle::changeMessage(QString message)
{
    /*QString pattern="(?:\\[length=)(\\d+)(?:\\])";
    QRegExp reg(pattern);
    //QString message="[length=32]<loginuser><userid:>用户名<name:>名称<password:>密码";
    message.indexOf(reg);
    reg.cap(1);
    message.split(reg);*/
    return message;

}
QMap<QString, QString> Handle::getCommand(QString command)
{
    QString pattern="(?:<)([a-zA-Z0-9_\u4e00-\u9fa5\\w]+)(?::>)([a-zA-Z0-9_\u4e00-\u9fa5\\w]+)";
    QRegExp reg(pattern);
    int i=0;
    QMap<QString,QString> map;
    while(true){
        i=command.indexOf(reg,i+1);
        if(i==-1)
        {
            break;
        }
        map.insert(reg.cap(1),reg.cap(2));
    }
    return map;

}
bool Handle::registered(QString userId, QString userName, QString pwd)
{
    QString command="<loginuser><userid:>"+userId+"<name:>"+userName+"<password:>"+pwd;
    command="[length="+QString::number(command.size())+"]"+command;
    tcp.tcpconnect(ip,port);
    tcp.send(command);
    getCommand(tcp.read());
    QString result ="2";
    if(result=="1")
    {
        return true;
    }
    else
    {
        return false;
    }
}
