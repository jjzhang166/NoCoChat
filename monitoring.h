#ifndef UDPHANDLE_H
#define UDPHANDLE_H

#include <QObject>
#include "udpnet.h"
#include <QThread>
#include <QEventLoop>

class Monitoring : public QObject
{
    Q_OBJECT
public:
    explicit Monitoring (QObject *parent = 0);

signals:
    void haveMessage();
public slots:
    void handle();
public:

};

#endif // UDPHANDLE_H
