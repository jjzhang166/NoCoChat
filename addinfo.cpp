#include "addinfo.h"
#include "ui_addinfo.h"
#include <QTableWidgetItem>
#include <QAbstractItemView>
#include <QMessageBox>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QCursor>

AddInfo::AddInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInfo)
{
    ui->setupUi(this);

    setMinimumWidth(500);
    setMaximumWidth(500);

    ui->friend_id->setText(NULL);
    ui->friend_name->setText(NULL);
    ui->group_id->setText(NULL);
}

AddInfo::~AddInfo()
{
    delete ui;
}

// 设置用户昵称
void AddInfo::setUserName(QString name)
{
    username = name;
}

// 设置用户帐号（ID）
void AddInfo::setUserId(QString id)
{
    userid = id ;
}

// 好友查找按钮点击槽函数
void AddInfo::on_friend_searchbtn_clicked()
{
    userid = ui->friend_id->text() ;    // 获取用户输入的帐号
    username = ui->friend_name->text() ;    // 获取用户输入的昵称
    printFriendInfo(username, userid);
}

// 聊天室（群）查找点击槽函数
void AddInfo::on_group_searchbtn_clicked()
{
    groupid = ui->group_id->text();
    printGroupInfo(groupid);
}

// 设置对话框中各部的大小
void AddInfo::setSize()
{
    float height = this->height();
    ui->tabWidget->resize(500, height);
    // 设置好友添加表格
    setFriendTable();
    ui->friend_table->resize(495, height-84);
    // 设置群添加表格
    setGroupTable();

}

// 设置好友添加表格
void AddInfo::setFriendTable()
{
    // 设置好友添加表格各列的宽度
    ui->friend_table->setColumnWidth(0, 120);
    ui->friend_table->setColumnWidth(1, 100);
    ui->friend_table->setColumnWidth(2, 40);
    ui->friend_table->setColumnWidth(3, 120);
    ui->friend_table->setColumnWidth(4, 113);

    // 设置单元格不能被修改
    ui->friend_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 设置表格整行选择
    ui->friend_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置表格中只能选中一个目标
    ui->friend_table->setSelectionMode(QAbstractItemView::SingleSelection);
}

// 设置群添加表格
void AddInfo::setGroupTable()
{
    // 设置群添加表格各列的宽度
    ui->group_table->setColumnWidth(0, 220);
    ui->group_table->setColumnWidth(1,273);

    // 设置单元格不能被修改
    ui->group_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 设置表格整行选择
    ui->group_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置表格中只能选中一个目标
    ui->group_table->setSelectionMode(QAbstractItemView::SingleSelection);
}

 // 将搜索用户得到的信息放进表格中，通过特定的用户名或帐号想找相应的用户信息并打印到表格中
void AddInfo::printFriendInfo(QString name, QString id)
{
    int i,j;
    friendlist = handle.getFriendList(userid) ;
    QString temp[]={"userid","name","sex", "department", "major"};
    // 插入一行
    int row = ui->friend_table->rowCount(); // 必须有此行代码才能新添一行表格
    if (name == NULL || name == "" || id == NULL || id == "")
    {   // 当用户即不输入用户名也不输入帐号，或者输入的帐号和用户名都为空时运行此区域的代码
        // 遍历所有用户信息，并将用户信息输出到表格中
        for (i=0; i < friendlist.size(); i++)
        {
            ui->friend_table->insertRow(row);
            for (j=0; j<sizeof(temp); j++)
            {
                // 将用户信息输出到第 i 行，第 j 列单元格中
                ui->friend_table->setItem(i, j, new QTableWidgetItem(friendlist[i][temp[j]]));
            }
        }
    }else if(name != NULL && name != "" && (id == NULL || id == "")){
        // 当用户只输入用户名时则运行此条件内的代码
        int count = 0;  // 用于统计人数
        // 遍历查找好友
        for (i=0; i < friendlist.size(); i++)
        {
            if (name == friendlist[i][temp[1]])
            {
                ui->friend_table->insertRow(row);
                for(j=0; j<sizeof(temp); j++)
                {
                    // 将用户信息输出到第 i 行，第 j 列单元格中
                    ui->friend_table->setItem(i, j, new QTableWidgetItem(friendlist[i][temp[j]]));
                    count++;
                }
            }
        }
        // 当查找的用户不存在时，弹出一个消息框
        if (0 == count)
        {
            QMessageBox::about(this, "消息", "对不起，您所要查找的用户不存在！");
        }
    }else if(id != NULL && id == "" && (name == NULL | name == "")){
        // 当用户只输入帐号时则运行此条件内的代码
        int count=0;
        // 遍历查找好友
        for (i=0; i <friendlist.size(); i++)
        {
            if (id == friendlist[i][temp[0]])
            {
                ui->friend_table->insertRow(row);
                for(j=0; j<sizeof(temp); j++)
                {
                    // 将用户信息输出到第 i 行，第 j 列单元格中
                    ui->friend_table->setItem(i, j, new QTableWidgetItem(friendlist[i][temp[j]]));
                    count++;
                }
            }
        }
        // 当查找的用户不存在时，弹出一个消息框
        if (0 == count)
        {
            QMessageBox::about(this, "消息", "对不起，您所要查找的用户不存在！");
        }
    }else if (name != NULL && name != "" && id == NULL && id == ""){
        // 当用户同时输入用户名和帐号时则运行此条件内的代码
        int count=0;
        for(i=0; i <friendlist.size(); i++)
        {
            if(friendlist[i][temp[0]] == id && friendlist[i][temp[1]] == name)
            {
                ui->friend_table->insertRow(row);
                for(j=0; j<sizeof(temp); j++)
                {
                    // 将用户信息输出到第 i 行，第 j 列单元格中
                    ui->friend_table->setItem(i, j, new QTableWidgetItem(friendlist[i][temp[j]]));
                    count++;
                }
            }
        }
        // 当查找的用户不存在时，弹出一个消息框
        if (0 == count)
        {
            QMessageBox::about(this, "消息", "对不起，您所要查找的用户不存在！");
        }
    }
}

// 将搜索群得到的信息放进表格中
void AddInfo::printGroupInfo(QString id)
{
    int i,j ;
    // 通过本用户帐号获取所有聊天室（群）的列表
//    grouplist = handle.getRoomList(userid);
//    QString temp[]={"talkroomid", "talkroomname"};
    // 插入一行
    int row = ui->group_table->rowCount(); // 必须有此行代码才能新添一行表格
    ui->group_table->insertRow(row);
    ui->group_table->insertRow(row);
//    if(id == NULL || id == "")
//    {   // 当聊天室（群）帐号为空时，执行此分支
//        for (i=0; i<grouplist.size(); i++)
//        {
//            ui->group_table->insertRow(row);
//            for(j=0; j<sizeof(temp); j++)
//            {
//                // 将用户信息输出到第 i 行，第 j 列单元格中
//                ui->group_table->setItem(i, j, new QTableWidgetItem(grouplist[i][temp[j]]));
//            }
//        }
//    }else if(id != NULL && id != ""){
//        // 当聊天室（群）帐号不为空时，执行此分支
//        int count = 0 ;
//        // 遍历所有的信息，找到对应 id 的聊天室（群）并输出到表格中
//        for(i=0;  i<grouplist.size(); i++)
//        {
//            if(grouplist[i][temp[0]] == id)
//            {
//                ui->group_table->insertRow(row);
//                for(j=0; j<sizeof(temp); j++)
//                {
//                    // 将用户信息输出到第 i 行，第 j 列单元格中
//                    ui->group_table->setItem(i, j, new QTableWidgetItem(grouplist[i][temp[j]]));
//                    count++ ;
//                }
//            }
//        }
//        // 当查找的聊天室（群）不存在时，弹出一个消息框
//        if (0 == count)
//        {
//            QMessageBox::about(this, "消息", "对不起，您所要查找的聊天室不存在！");
//        }
//    }

}

// 窗体大小改变事件
void AddInfo::resizeEvent(QResizeEvent *)
{
    setSize();
}

// 鼠标按下事件响应函数
void AddInfo::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::RightButton)
    {
        event = e ;
    }
}

// 鼠标松开事件响应函数
void AddInfo::mouseReleaseEvent(QMouseEvent *e)
{
    if(event->button() == e->button())
    {
        QMenuBar *menubar = new QMenuBar(this);
        QAction *addfriend = menubar->addAction("添加好友") ;
        QAction *getinfo = menubar->addAction("好友信息");
        menubar->show();
    }
}

// 鼠标双击按钮事件响应函数
void AddInfo::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(event->button() == e->button())
    {
//        QMenuBar *menubar = new QMenuBar(this);
//        QMenu *addfriend = menubar->addMenu("添加好友") ;
//        QAction *getinfo = menubar->addAction("好友信息");
//        menubar->show();
//        addfriend->show();
//        QCursor cur = this->cursor();
//        QMenu *menu = new QMenu(this);
//        menu->addAction("添加好友");
//        menu->addAction("好友信息");
//        menu->exec(cur.pos());
    }
}

// 右键菜单事件
void AddInfo::contextMenuEvent(QContextMenuEvent *)
{
    QCursor cur = this->cursor();
    QMenu *menu = new QMenu(this);
    menu->addAction("添加好友");
    menu->addAction("好友信息");
    QAction *aa = menu->addAction("aa");

    menu->exec(cur.pos());
}
