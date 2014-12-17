#ifndef CHAT_H
#define CHAT_H
#include <QDialog>
#include <QSplitter>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QResizeEvent>
#include <QFont>
#include <QFrame>
#include <QDateTime>
#include "udpnet.h"

namespace Ui {
class Chat;
}

class Chat : public QDialog
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = 0);
    ~Chat();
    QString username ;
    QString userid;
    QSplitter *splitter ;   // 分割主窗口
    QSplitter *Lsplitter ;  // 分割左边的窗口
    QSplitter *Rsplitter ;  // 分割右边的窗口
    QDialog *center ;   // 聊天窗口中间工具栏区域
    QTextEdit *alltext ;    // 所有聊天内容显示区域
    QTextEdit *inputtext ;  // 本地信息输入区域
    QTextEdit *historytext ;
    QPushButton *send ;     // 发送聊天信息按钮
    QPushButton *fontbtn ;  // 切换字体按钮
    QPushButton *history ;  // 查看历史记录按钮
    QFont font ;    // 字体
    QFrame *frame ;
    QDateTime time; // 用于获取当前系统时间的对象

    void setUserName(QString name) ;    // 设置用户昵称
    void setUserId(QString id); // 设置用户帐号(ID)
    void init() ;   // 对象初始函数
    void setComponent() ;   // 将各部件布局到窗口中
    void setSize() ;    // 设置窗口各部件大小
    void sendInfo() ;
    void resizeEvent(QResizeEvent *);

    void setConnect() ;

    void setUdp();
    void message(QString msg);
    void setFriend(QString friendid);
    QString getFriend();
    void setflag(bool flag);
    bool getflag();

signals:
private:
    Ui::Chat *ui;
    UDPNet *udp;
    QString friendId;
    bool flag=false;
public slots:

    void setFont() ;    // 设置字体
    void showHistory(bool) ;    // 显示历史记录
    void sendText() ;   // 发送聊天信息


};

#endif // CHAT_H
