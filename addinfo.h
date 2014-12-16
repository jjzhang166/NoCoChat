#ifndef ADDINFO_H
#define ADDINFO_H

#include <QDialog>
#include <QString>
#include <QResizeEvent>
#include "mainwindow.h"
#include "handle.h"
#include <QList>
#include <QMap>

namespace Ui {
class AddInfo;
}

class AddInfo : public QDialog
{
    Q_OBJECT

public:
    explicit AddInfo(QWidget *parent = 0);
    ~AddInfo();

private slots:
    void on_friend_searchbtn_clicked(); // 查找好友

private:
    Ui::AddInfo *ui;

    QString userid ;    // 用户帐号（ID）
    QString username ;  // 用户昵称
    QList<QMap<QString, QString> > friendlist ;    // 用于接收从服务器获取的好友信息
    QList grouplist ;   // 用于接收从服务器获取的聊天室（群）的信息

    void setSize() ;    // 设置窗口各组件的大小
    void setFriendTable() ; // 设置好友添加表格
    void setGroupTable() ;  // 设置群添加表格
    // 通过特定的用户名或帐号想找相应的用户信息并打印到表格中
    void printFriendInfo(QString name, QString id);
    void printGroupInfo();  // 将搜索群得到的信息放进表格中

    MainWindow mainwindow ; // 用于获取本用户的用户名和用户帐号
    Handle handle ; // 本对象用于获取好友和聊天室信息

    void resizeEvent(QResizeEvent *);   // 窗体大小改变事件
};

#endif // ADDINFO_H
