#ifndef UDPNET_H
#define UDPNET_H

#include <QObject>
#include <QtNetwork/QUdpSocket>
#include <QEventLoop>
#include <QDebug>

class UDPNet : public QObject
{
    Q_OBJECT
public:
    explicit UDPNet(QObject *parent = 0);
    //发送消息
    void sendMessage(QString message, int port);
    //发送消息
    void sendMessage(QString message);
    //设置ip和端口
    void setConfig(QString ip);
    //绑定端口
    int bindPort();
public slots:
    //接受消息
    void acceptMessage();
signals:
    void haveMessaeg(QString);
private:
   QUdpSocket *udpAccepct;
   QUdpSocket *udpReaction;
   quint16 port;
   QString ip;
   QEventLoop eventloop;
   QString message;
};

#endif // UDPNET_H
