#include "udpnet.h"

UDPNet::UDPNet( )
{
    udpSocket=new QUdpSocket();
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(acceptMessage()));
}
/**
 * @brief 设置udp协议的ip地址和端口
 * @param ip ip地址
 */
void UDPNet::setConfig(QString ip)
{
    this->ip=ip;
}
/**
 * @brief 获取一个空闲端口作为本次进程的通讯端口
 * @return 绑定是否成功
 */
int UDPNet::bindPort()
{
//    初始端口从10000开始
    int p=10000;
//    直到端口能被绑定
    while(udpSocket->bind(p,QUdpSocket::ShareAddress))
    {
//        步长为一
        p++;
    }
//    返回绑定的端口号
    this->port=p;
    return p;
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
     //拥有等待的数据报
      while(udpSocket->hasPendingDatagrams()){
          QByteArray accept;
          accept.resize(udpSocket->pendingDatagramSize());
          udpSocket->readDatagram(accept.data(),accept.size());
          this->message=accept;
       }

 }
 /**
 * @brief 获取接收到的信息
 * @return 返回接收到的信息
 */
QString UDPNet::getMessage()
{
    return message;
}
