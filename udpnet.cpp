#include "udpnet.h"

UDPNet::UDPNet( )
{
    udpSocket=new QUdpSocket();
    eventloop=new QEventLoop();
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(acceptMessage()));
}
void UDPNet::setConfig(quint16 port, QString ip)
{
    this->port=port;
    this->ip=ip;
}
/**
 * @brief 发送消息
 * @param port 目标端口
 * @param ip 目标ip
 * @param message 发送信息
 */
void UDPNet::sendMessage(QString message)
{
    QByteArray byte=message.toAscii();
    QHostAddress address;
    address.setAddress(ip);
    udpSocket->writeDatagram(byte.data(),message.size(),address,port);
}
/**
  * @brief 接受消息
  * @param port 监听端口
  * @param ip 监听ip
  * @return 接收到的数据
  */
 void UDPNet::acceptMessage()
 {
      QHostAddress address;
      address.setAddress(ip);
      QByteArray accept;
      udpSocket->readDatagram(accept.data(),accept.size(),&address,&port);
      this->message=accept;
      eventloop->exit();

 }
QString UDPNet::read()
 {
     eventloop->exec();
     return message;
 }
