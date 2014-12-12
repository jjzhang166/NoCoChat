#include "tcpnet.h"

TcpNet::TcpNet()
{
    tcpClient=new QTcpSocket();
    eventloop=new QEventLoop();
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(readMessage()));
}
/**
 * @brief TCP连接
 * @param ip 服务器ip地址
 * @param port 服务器端口
 * @return true or false
 */
bool TcpNet::tcpconnect(QString ip, quint16 port)
{
    QHostAddress address;
    address.setAddress(ip);
    tcpClient->connectToHost(address,port);
    if(!tcpClient->waitForConnected(5000))
    {

      return false;
    }
    else
    {
        return true;
    }

}
/**
 * @brief 发送数据
 */
void TcpNet::send(QString common)
{
   command(common);
   this->tcpClient->write(this->send_info);
}
/**
 * @brief 接受数据
 * @return 接收到的数据
 */
QString TcpNet::read()
{

  eventloop->exec();
  return read_info;
}
/**
 * @brief 读取数据
 */
void TcpNet::readMessage()
{
    this->read_info=this->tcpClient->readAll();
    eventloop->exit();
}

/**
 * @brief 把接受到的命令转为字节
 * @param 命令
 */
void TcpNet::command(QString common)
{
    this->send_info=common.toAscii();
}

/**
 * @brief 关闭连接
 */
void TcpNet::close()
{
    tcpClient->close();
}
QString TcpNet::getLocalAddress()
{
       QHostInfo info = QHostInfo::fromName(QHostInfo::localHostName());
       foreach(QHostAddress address,info.addresses())
       {
           if(address.protocol() == QAbstractSocket::IPv4Protocol)
           {
              return address.toString();
           }
       }
    return "none";
}
