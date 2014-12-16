#include "addinfo.h"
#include "ui_addinfo.h"
#include <QTableWidgetItem>

AddInfo::AddInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInfo)
{
    ui->setupUi(this);

    setMinimumWidth(500);
    setMaximumWidth(500);
}

AddInfo::~AddInfo()
{
    delete ui;
}

void AddInfo::on_friend_searchbtn_clicked()
{
    userid = ui->friend_id->text() ;    // 获取用户输入的帐号
    username = ui->friend_name->text() ;    // 获取用户输入的昵称
}

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
    // 设置好友添加表格列的宽度
    ui->friend_table->setColumnWidth(0, 30);
    ui->friend_table->setColumnWidth(1, 150);
    ui->friend_table->setColumnWidth(2, 200);
    ui->friend_table->setColumnWidth(3, 113);
}

// 设置群添加表格
void AddInfo::setGroupTable()
{
    // 设置群添加表格列的宽度
    ui->group_table->setColumnWidth(0, 30);
    ui->group_table->setColumnWidth(1, 200);
    ui->group_table->setColumnWidth(2,263);
}

 // 将搜索用户得到的信息放进表格中
void AddInfo::printFriendInfo()
{
    ui->friend_table->setItem(0,0,new QTableWidgetItem("1"));
}

// 将搜索群得到的信息放进表格中
void AddInfo::printGroupInfo()
{

}

// 窗体大小改变事件
void AddInfo::resizeEvent(QResizeEvent *)
{
    setSize();
}
