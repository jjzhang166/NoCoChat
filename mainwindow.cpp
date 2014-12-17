#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   /*if(d_sign.exec()==QDialog::Accepted)
   {
           w_main.show();
         return a.exec();
   }
   else
       {
            return 0;
       }*/
    ui->setupUi(this);
    setMaximumSize(255, 544);
    setMinimumSize(255, 544);
    username = ui->user_name->text();
    //handle->setWindow(this);
    connect(udp,SIGNAL(haveMessaeg(QString)),this,SLOT(messageHandle(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setHandle(Handle *h)
{
    this->handle=h;
}
void MainWindow::setUdp(UDPNet *u)
{
    this->udp=u;
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
void MainWindow::setPort(int port)
{
    this->port=port;
}
/**
 * @brief 回应邀请进入聊天室
 * @param command
 * <fromid:>id<fromname:>名称(A) <talkroomid:>聊天室ID<talkroomname:>聊天室
 * @return
 */
void MainWindow::reactionTalkRoom(QMap<QString, QString> command)
{
    QString text="你的好友："+command["fromname"]+"邀请你加入聊天室："+command["talkroomname"]+",请问是否同意？";
    QString type="";
    if(QMessageBox::question(this,"好友申请",text,QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes)==QMessageBox::Yes)
    {
            type="1";
    }else{
            type="0";
    }
    //     拼接服务器请求协议
             QString commands="<addtalkroomfriendback><userid:>"+command["fromid"]+
"<fromuserid:>"+userId+"<type:>"+type+"<talkroomid:>"+command["talkroomid"];
    //    计算协议长度，添加协议头
             commands="[length="+QString::number(commands.size())+"]"+commands;
    //    发送协议
             udp->sendMessage(commands);
//             后续处理

}
/**
 * @brief 回应好友添加信息
 * @param command
 * <addyou><fromuserid:>用户名(A)<fromname:>名称(A)<ip:>ip<port:>port
 */
void MainWindow::reactionFriendRequest(QMap<QString,QString> command)
{
    QString text="用户："+command["fromname"]+"申请添加你为好友,请问是否同意？";
    QString type="";
    if(QMessageBox::question(this,"好友申请",text,QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes)==QMessageBox::Yes)
    {
            type="1";
    }else{
            type="0";
    }
    //     拼接服务器请求协议
             QString commands="<adduserfriendback><userId:>"+command["fromuserid"]+"<fromuserid:>"+userId+"<type:>"+type;;
    //    计算协议长度，添加协议头
             commands="[length="+QString::number(commands.size())+"]"+commands;
    //    发送协议
             udp->sendMessage(commands);
    //    后续处理
}
/**
 * @brief UDP接收处理函数
 * @param UDP接收到的Message
 */
void MainWindow::messageHandle(QString message)
{
    QMap<QString,QString> reslut=handle->getCommand(handle->changeMessage(message));
    QString command=reslut.value("command");
//        弹出系统窗口，询问是否进入聊天室
    if(command=="addtalkroomfriendyou")
    {
        reactionTalkRoom(reslut);
    }
//        打开聊天窗口
    if(command=="chat")
    {
        reactionTalkRoom(reslut);
    }
 //        弹出系统窗口，询问是否添加某人为好友
    if(command=="addyou")
    {
        reactionFriendRequest(reslut);
    }
//        弹出系统窗口，某人已下线，并把其项目置为enable（false）
    if(command=="youfrienddownline")
    {
        reactionTalkRoom(reslut);
    }
//        弹出系统窗口，某人已上线线，并把其项目置为enable（true）
    if(command=="youfriendsignin")
    {
        reactionTalkRoom(reslut);
    }
//        弹出系统窗口，某人进入群,并把其添加到群友列表
    if(command=="addtalkroomfriendback2")
    {
      reactionTalkRoom(reslut);
    }
}
