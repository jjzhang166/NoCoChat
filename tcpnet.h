#ifndef TCPNET_H
#define TCPNET_H

#include <QHostAddress>
#include <QtNetwork/QTcpSocket>
#include <QObject>
#include <QEventLoop>

class TcpNet :public QObject
{
    Q_OBJECT

public:
    explicit TcpNet();
    //TCP连接
    bool tcpconnect(QString ip, quint16 port);
    //发送数据
    void send(QString common);
    //读取数据
    QString read();
    //断开连接
    void close();
    //转换字节
    void command(QString common);

private slots:
    void readMessage();

private:
    QString read_info;
    QTcpSocket *tcpClient;
    QByteArray  send_info;
    QEventLoop *eventloop;
};

#endif // TCPNET_H
