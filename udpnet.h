#ifndef UDPNET_H
#define UDPNET_H

#include <QtNetwork/QUdpSocket>
#include <QObject>


class UDPNet:public QObject
{
public:
    UDPNet();
    //发送消息
    void sendMessage(QString message);
    //读取获取的信息
    QString getMessage();
    //设置ip和端口
    void setConfig(QString ip);
    //绑定端口
    int bindPort();
private slots:
    //接受消息
    void acceptMessage();

private:
   QUdpSocket *udpSocket;
   quint16 port;
   QString ip;
   //QEventLoop *eventloop;
   QString message;
};

#endif // UDPNET_H
