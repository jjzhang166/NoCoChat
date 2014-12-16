#ifndef ADDINFO_H
#define ADDINFO_H

#include <QDialog>
#include <QString>
#include <QResizeEvent>

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
    void setSize() ;    // 设置窗口各组件的大小
    void setFriendTable() ; // 设置好友添加表格
    void setGroupTable() ;  // 设置群添加表格
    void printFriendInfo(); // 将搜索用户得到的信息放进表格中
    void printGroupInfo();  // 将搜索群得到的信息放进表格中

    void resizeEvent(QResizeEvent *);   // 窗体大小改变事件
};

#endif // ADDINFO_H
