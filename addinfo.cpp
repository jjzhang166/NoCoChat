#include "addinfo.h"
#include "ui_addinfo.h"

AddInfo::AddInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInfo)
{
    ui->setupUi(this);
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
