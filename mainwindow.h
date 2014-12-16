#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "udpnet.h"
#include "signin.h"
#include "addinfo.h"
#include "handle.h"
#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Signin signin;

    QString username ;  // 用户昵称
    QString userId ;    // 用户(帐号)ID

    QString getUserName();//获取用户名
    QString getUserId();//获取用户id
//    设置handle指针
    void setHandle(Handle h);
//    设置udp指针
    void setUdp(UDPNet u);

public slots:
    void messageHandle(QString message);
private:
    Ui::MainWindow *ui;
    UDPNet *udp;
    Handle *handle;
    int port;
};

#endif // MAINWINDOW_H
