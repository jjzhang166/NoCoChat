#ifndef HANDLE_H
#define HANDLE_H
/**
 * 文件名：handle.h
 * 文件功能：定义handle类的相关成员和声明所有成员函数
 * 类的作用：所有界面的业务操作函数集合
 * 类的继承：QObejct
 * 作者：NoCo_jancojie
 */

#include <QObject>
#include "tcpnet.h"
#include "udpnet.h"
#include "config.h"
#include <QRegExp>
#include <QMap>
#include <QStringList>
<<<<<<< HEAD
#include <QDebug>
=======
>>>>>>> 94ca8d59868df8251ef3667d2b67764f3e7f1b0c

class Handle : public QObject
{
    Q_OBJECT
public:
    explicit Handle(QObject *parent = 0);
//    信息提取
    QString  changeMessage(QString message);
//    命令处理
    QMap<QString,QString> getCommand(QString command);
//    注册处理
    bool registered(QString userId,QString userName,QString pwd);
<<<<<<< HEAD
    //登录处理
    bool signin(QString userId,QString pwd);
=======
//    创建聊天室
    bool creatTalkroom(QString userId, QString talkroomid, QString talkroomname);
//    登录处理
    int signIn(QString userId, QString pwd,int port);
>>>>>>> 94ca8d59868df8251ef3667d2b67764f3e7f1b0c
signals:

public slots:

private:

protected:
//    tcp对象
    TcpNet tcp;
//   udp对象
    UDPNet udp;
//    配置文件对象
    Config config;
    QString ip;
    int port;

};

#endif // HANDLE_H
