#ifndef HANDLE_H
#define HANDLE_H

#include <QObject>
#include "tcpnet.h"
#include "udpnet.h"
#include "config.h"
#include <QRegExp>
#include <QMap>

class Handle : public QObject
{
    Q_OBJECT
public:
    explicit Handle(QObject *parent = 0);
    //信息提取
    QString  changeMessage(QString message);
    //命令处理
    QMap<QString,QString> getCommand(QString command);
    //注册处理
    bool registered(QString userId,QString userName,QString pwd);
signals:

public slots:

private:

protected:
    TcpNet tcp;
    UDPNet udp;
    Config config;
    QString ip;
    int port;

};

#endif // HANDLE_H
