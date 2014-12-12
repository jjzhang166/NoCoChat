#include "signin.h"
#include "ui_signin.h"



Signin::Signin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signin)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    ui->setupUi(this);
}

Signin::~Signin()
{
    delete ui;
}

void Signin::on_b_signin_clicked()
{
    /*
        //验证模块——简易认证
        QString user_name="jancojie";
        QString user_pwd="84251033";
        if(ui->username->text()==user_name&&ui->password->text()==user_pwd)
   */
    /*
        验证模块——服务器验证
     */
    TcpNet tcp;
    QString ip="172.16.107.5"; 
    tcp.tcpconnect(ip,8002);
    QString command="<signin><userid:>"+ui->username->text()+"<password:>"+ui->password->text()+"<ip:>172.16.107.5<port:>7879";
    command="[length="+QString::number(command.length())+"]"+command;
    tcp.send(command);
    if(true)
    {
        /* while(tcp.isFlag())
        {

        }*/
        QMessageBox::warning(this,"返回的内容",tcp.read());
        accept();
        close();

    }
    else
    {
        QMessageBox::warning(this,"登录提示","密码或用户名错误");
    }
}
