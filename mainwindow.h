#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "udpnet.h"
#include "signin.h"
#include "addinfo.h"
#include "handle.h"
#include <QDebug>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include "signal.h"
#include <QTimer>
#include <QMenu>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString username ;  // 用户昵称
    QString userId ;    // 用户(帐号)ID

    QString getUserName();//获取用户名
    QString getUserId();//获取用户id
//    设置handle指针
    void setHandle(Handle h);
//    设置udp指针
    void setUdp(UDPNet u);
//    聊天室邀请
    void reactionTalkRoom(QMap<QString,QString> command);
//    好友申请
    void reactionFriendRequest(QMap<QString,QString> command);
    void timeico();


public slots:
    void Maction(QSystemTrayIcon::ActivationReason wch);
    void messageHandle(QString message);
    void changeico();
    void exitWindow();
private:
    Ui::MainWindow *ui;
    UDPNet *udp;
    Handle *handle;
    Signin sign;
    int port;
    QSystemTrayIcon *trayIcon;
    QTimer *times;
    int m;
    QMenu *trayIconMenu;

};

#endif // MAINWINDOW_H
