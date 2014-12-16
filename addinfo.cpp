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
    ui->friend_id->setText(NULL);
    ui->friend_name->setText(NULL);
}

AddInfo::~AddInfo()
{
    delete ui;
}

void AddInfo::on_friend_searchbtn_clicked()
{
    userid = ui->friend_id->text() ;    // 获取用户输入的帐号
    username = ui->friend_name->text() ;    // 获取用户输入的昵称
    printFriendInfo(username, userid);
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
    // 设置好友添加表格列的宽度
    ui->friend_table->setColumnWidth(0, 120);
    ui->friend_table->setColumnWidth(1, 100);
    ui->friend_table->setColumnWidth(2, 40);
    ui->friend_table->setColumnWidth(3, 120);
    ui->friend_table->setColumnWidth(4, 113);
}

// 设置群添加表格
void AddInfo::setGroupTable()
{
    // 设置群添加表格列的宽度
    ui->group_table->setColumnWidth(0, 220);
    ui->group_table->setColumnWidth(1,273);
}

 // 将搜索用户得到的信息放进表格中，通过特定的用户名或帐号想找相应的用户信息并打印到表格中
void AddInfo::printFriendInfo(QString name, QString id)
{
    int i,j;
    friendlist = handle.getFriendList(userid) ;
    QString temp[]={"userid","name","sex", "department", "major"};
    // 插入一行
    int row = ui->friend_table->rowCount();
    if (name == NULL || name == "" || id == NULL || id == "")
    {
        for (i=0; i < friendlist.size(); i++)
        {
            ui->friend_table->insertRow(row);
            for (j=0; j<sizeof(temp); j++)
            {
                ui->friend_table->setItem(i, j, new QTableWidgetItem(friendlist[i][temp[j]]));
            }
        }
    }else if(name != NULL && name != "" && (id == NULL || id == "")){
        int count = 0;  // 用于统计人数
        for (i=0; i < friendlist.size(); i++)
        {
            if (name == friendlist[i][temp[1]])
            {
                ui->friend_table->insertRow(row);
                for(j=0; j<sizeof(temp); j++)
                {
                    ui->friend_table->setItem(i, j, new QTableWidgetItem(friendlist[i][temp[j]]));
                    count++;
                }
            }
        }
    }else if(id != NULL && id == "" && (name == NULL | name == "")){
        int count=0;
        for (i=0; i <friendlist.size(); i++)
        {
            if (id == friendlist[i][temp[0]])
            {

            }
        }
    }
    //ui->friend_table->insertRow(row);
    //ui->friend_table->setItem(0,0,new QTableWidgetItem(QString::number(sizeof(i)/sizeof(i[0]))));
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
