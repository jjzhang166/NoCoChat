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
#include <QTimer>
#include <QMenu>
#include <QTableWidget>
#include <QStringList>
#include <QVBoxLayout>
#include <QMap>
#include "chat.h"

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
    void setMyFriendBox();  // 好友列表
    void addMyFriend(); // 将好友放进“我的好友”抽屉列表中


public slots:
    void Maction(QSystemTrayIcon::ActivationReason wch);
    void messageHandle(QString message);
    void changeico();
    void exitWindow();
private slots:
    void on_addfriend_clicked();

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
    QTableWidget *myfriendwidget; // 用于放置所有好友
    QVBoxLayout *lay;
    QMap<QString,Chat*> map;

};

#endif // MAINWINDOW_H
