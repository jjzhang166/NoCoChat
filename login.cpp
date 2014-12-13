#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    userInfo();
}

Login::~Login()
{
    delete ui;
}

// 获取用户注册信息
void Login::userInfo()
{
    userid = ui->user_id->text() ;  // 获取用户帐号（ID）
    username = ui->name->text() ;   // 获取用户名（昵称）
    userpwd = ui->pwd->text() ;     // 获取用户第一次输入的密码
}

void Login::on_ok_clicked()
{
    if (ui->pwd_1->text() == userpwd)
    {
        if (handle.registered(userid,username,userpwd))
        {
            QMessageBox::about(this, "消息", "恭喜您，注册成功！") ;
            this->exec() ;
        }else{
            QMessageBox::about(this, "消息", "对不起，该帐号已存在！") ;
            ui->user_id->setText("");
            ui->name->setText("");
            ui->pwd->setText("");
            ui->pwd_1->setText("");
        }
    }else{
        QMessageBox::about(this, "消息", "两次密码输入不一致")
    }
}
