#ifndef ADDINFO_H
#define ADDINFO_H

#include <QDialog>
#include <QString>
#include <QResizeEvent>
#include "handle.h"
#include <QList>
#include <QMap>
#include <QMouseEvent>
#include <QContextMenuEvent>

namespace Ui {
class AddInfo;
}

class AddInfo : public QDialog
{
    Q_OBJECT

public:
    explicit AddInfo(QWidget *parent = 0);
    ~AddInfo();

    void setUserName(QString name); // 设置用户名
    void setUserId(QString id); // 设置用户帐号

private slots:
    void on_friend_searchbtn_clicked(); // 查找好友

    void on_group_searchbtn_clicked();  // 查找聊天室（群）
    void addFriendAction();

private:
    Ui::AddInfo *ui;

    QString userid ;    // 用户帐号（ID）
    QString username ;  // 用户昵称
    QString groupid ;   // 聊天室（群）的(ID)
    QList<QMap<QString, QString> > friendlist ; // 用于接收从服务器获取的好友信息
    QList<QMap<QString, QString> > grouplist ;  // 用于接收从服务器获取的聊天室（群）的信息
    int press_mouse_button; // 鼠标点击的按钮
    QMouseEvent *event;
    QAction *addfriend;

    void setSize() ;    // 设置窗口各组件的大小
    void setFriendTable() ; // 设置好友添加表格
    void setGroupTable() ;  // 设置群添加表格
    // 通过特定的用户名或帐号想找相应的用户信息并打印到表格中
    void printFriendInfo(QString name, QString id);
    void printGroupInfo(QString id);  // 将搜索群得到的信息放进表格中
    void setConnection();

    Handle handle ; // 本对象用于获取好友和聊天室信息

    void resizeEvent(QResizeEvent *);   // 窗体大小改变事件
    void mousePressEvent(QMouseEvent *e);    // 鼠标按下事件响应函数
    void mouseReleaseEvent(QMouseEvent *e);  // 鼠标松开事件响应函数
    void mouseDoubleClickEvent(QMouseEvent *e);  // 鼠标双击按钮事件响应函数
    void contextMenuEvent(QContextMenuEvent *); // 右键菜单事件
};

#endif // ADDINFO_H
