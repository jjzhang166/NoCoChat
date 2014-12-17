#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMaximumSize(255, 544);
    setMinimumSize(255, 544);
    handle=new Handle();
    handle->setWindow(this);
    udp=new UDPNet();
    port =udp->bindPort();
    connect(udp,SIGNAL(haveMessaeg(QString)),this,SLOT(messageHandle(QString)));
    sign.setHandle(handle);
    sign.setPort(port);
    trayIcon=new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/img/SiseChat.png"));
    trayIcon->setToolTip("NoCo_Chat,逗比做的聊天软件");//定义一个系统托盘图标并设置图标的提示语
    trayIcon->show();
    sign.show();
    //创建监听行为
        QAction *minimizeAction = new QAction("最小化 (&I)", this);
        connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
        QAction *restoreAction = new QAction("还原 (&R)", this);
        connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
        QAction *quitAction = new QAction("退出 (&Q)", this);
        connect(quitAction, SIGNAL(triggered()), this, SLOT(exitWindow()));

        //创建右键弹出菜单
        trayIconMenu = new QMenu(this);
        trayIconMenu->addAction(minimizeAction);
        trayIconMenu->addAction(restoreAction);
        trayIconMenu->addSeparator();
        trayIconMenu->addAction(quitAction);
        trayIcon->setContextMenu(trayIconMenu);
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(Maction(QSystemTrayIcon::ActivationReason)));
    if(sign.exec()==QDialog::Accepted)
    {
       userId=sign.getUserId();
       username=sign.getUserName();
       ui->user_name->setText(username);
       times=new QTimer (this);
       times->setSingleShot(false);//true 表示循环一次 表示循环无数次
       times->setInterval(650);
       connect(times,SIGNAL(timeout()),this,SLOT(changeico()));
       show();
       trayIcon->showMessage("欢迎！","欢迎"+username+"你回来！");

    }
    else
    {
       exit(0);
    }

    setMyFriendBox();
}

MainWindow::~MainWindow()
{
    handle->lamdownline(userId);
    delete ui;
}
void MainWindow::exitWindow()
{
    handle->lamdownline(userId);
    exit(0);
}
void MainWindow::timeico()

{

    m=0;

    times->start();

}
void MainWindow::changeico()

{
    m++;
        if(m%2==0)

        {

            trayIcon->setIcon(QIcon(":/img/SiseChat.png"));
        }

        else

        {
             trayIcon->setIcon( QIcon() );
        }

}
void MainWindow::Maction(QSystemTrayIcon::ActivationReason wch)

{

    switch(wch)

    {

            case QSystemTrayIcon::Trigger: times->stop();

                     trayIcon->setIcon( QIcon(":/img/SiseChat.png") );break;//当用户单击时 我们让图标停止闪烁
                     break;

        case QSystemTrayIcon::DoubleClick:
            //双击托盘图标
            this->showNormal();
            this->raise();
            break;
        default:
            break;

    }

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
    QMap<QString,QString> result=handle->getCommand(handle->changeMessage(message));
    QString command=result.value("command");
//        弹出系统窗口，询问是否进入聊天室
    if(command=="addtalkroomfriendyou")
    {
        reactionTalkRoom(result);
    }
//        打开聊天窗口
    if(command=="chat")
    {

        QString messages="";
        QStringList temp=result["value"].split('|');
        for(int i=0;i<temp.size();i++)
        {
            temp[i]="<"+temp[i]+">";
            messages+=temp[i];
        }
        if(map.contains(result["userid"]))
        {
            map[result["userid"]]->message(messages);

        }else{
            Chat *chat=new Chat(this);
            chat->message(messages);
            map.insert(result["userid"],chat);
        }
        map[result["userid"]]->show();
}
 //        弹出系统窗口，询问是否添加某人为好友
    if(command=="addyou")
    {
        reactionFriendRequest(result);
    }
//        弹出系统窗口，某人已下线，并把其项目置为enable（false）
    if(command=="youfrienddownline")
    {
        trayIcon->showMessage("好友下线","你的好友："+result["name"]+"已下线");
    }
//        弹出系统窗口，某人已上线线，并把其项目置为enable（true）
    if(command=="youfriendsignin")
    {
        trayIcon->showMessage("好友上线","你的好友："+result["name"]+"已上线");
    }
//        弹出系统窗口，某人进入群,并把其添加到群友列表
    if(command=="addtalkroomfriendback2")
    {
      reactionTalkRoom(result);
    }
}

/**
 * @brief MainWindow::setMyFriendBox
 */
void MainWindow::setMyFriendBox()
{
    myfriendwidget = new QTableWidget;
    myfriendwidget->verticalHeader()->setVisible(false);  // 隐藏表头
    myfriendwidget->horizontalHeader()->setVisible(false);    // 隐藏行头

    myfriendwidget->insertColumn(myfriendwidget->columnCount());    // 增加一列单元格
    myfriendwidget->setColumnWidth(0, 252);     // 设置单元格的宽度为252

    myfriendwidget->insertRow(myfriendwidget->rowCount());myfriendwidget->setRowHeight(0, 100);
    QTableWidgetItem *it = new QTableWidgetItem( "张三");
    myfriendwidget->setItem(0,0, it);
    it->setIcon(QPixmap(":/img/Person.png"));
    it->setIcon(QIcon(QSize(30,30)));
    lay = new QVBoxLayout(ui->myfriend);
    lay->addWidget(myfriendwidget); // 将一个表格放进我的好友抽屉中
    lay->setMargin(0);  // 设置边距为0
}

/**
 * @brief MainWindow::addMyFriend
 */
void MainWindow::addMyFriend()
{
    handle->getFriendList(userId);  // 获取所有的好友列表
}

void MainWindow::on_addfriend_clicked()
{
    AddInfo addinfo();
}
