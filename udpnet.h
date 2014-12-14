#ifndef UDPNET_H
#define UDPNET_H

#include <QtNetwork/QUdpSocket>
#include <QObject>
#include <QEventLoop>

class UDPNet:public QObject
{
public:
    UDPNet();
    //发送消息
    void sendMessage(QString message);
    //接受消息
    QString acceptMessage();
    //设置ip和端口
    void setConfig(quint16 port, QString ip);
private slots:


private:
   QUdpSocket *udpSocket;
   quint16 port;
   QString ip;
   QEventLoop *eventloop;
   QString message;
};

#endif // UDPNET_H
