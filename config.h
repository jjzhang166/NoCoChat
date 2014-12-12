#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QSettings>
#include <QMap>

class Config : public QObject
{
    Q_OBJECT
public:
    explicit Config(QObject *parent = 0);
    QString getValue(QString key,QString group="connect");
    void setValue(QString key,QString value,QString group="connect");
public slots:

private:
    QSettings *set;
};

#endif // CONFIG_H
