#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setMaximumSize(255, 544);
    setMinimumSize(255, 544);
    username = ui->user_name->text();
    userId = "jancojie"/*signin.getUserId()*/;
    this->handle=new Handle();
    this->udp=new UDPNet();
    port=udp->bindPort();
    qDebug()<<port;
    connect(udp,SIGNAL(haveMessaeg(QString)),this,SLOT(messageHandle(QString)));
    udp->setConfig("127.0.0.1");

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getUserName()
{
    return username;
}

QString MainWindow::getUserId()
{
    return userId ;
}
void MainWindow::setHandle(Handle h)
{
    this->handle=&h;
}
void MainWindow::setUdp(UDPNet u)
{
    this->udp=&u;
}
/**
 * @brief UDP接收处理函数
 * @param UDP接收到的Message
 */
void MainWindow::messageHandle(QString message)
{
    QMap<QString,QString> reslut=handle->getCommand(handle->changeMessage(message));
//    switch (reslut.value("command")) {
//    case "chats":
////        打开聊天窗口
//        break;
//    case "addyou":
////        弹出系统窗口，询问是否添加某人为好友
//        break;
//    case "addtalkroominvite":
////        弹出系统窗口，询问是否添加某人为好友
//        break;
//    case "youfrienddownline":
////        弹出系统窗口，某人已下线，并把其项目置为enable（false）
//        break;
//    case "youfriendsignin":
////        弹出系统窗口，某人已上线线，并把其项目置为enable（true）
//        break;
//    case "adduserfriendback":
////         弹出系统窗口。某人确认你的好友申请，更新ip，和好友列表
//    default:
//        break;
//    }
}
