#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "signin.h"
#include "chat.h"
#include "addinfo.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Signin signin;  // 实例化登录窗口对象
    Chat chat;  // 实例化聊天窗口
    AddInfo addinfo ;   // 实例化添加好友（聊天室（群））窗口对象

    QString username="";  // 用户昵称
    QString userId="" ;  // 用户(帐号)ID

    QString getUserName();
    QString getUserId();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
