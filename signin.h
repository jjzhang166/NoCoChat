#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include <QHostAddress>
#include "handle.h"
#include <QMessageBox>
#include <QTextCodec>
#include <QString>

namespace Ui {
class Signin;
}

class Signin : public QDialog
{
    Q_OBJECT

public:
    explicit Signin(QWidget *parent = 0);
    ~Signin();

    QString userid ;    // 用户帐号
    QString pwd ;   // 用户密码

    QString getUserId();

private slots:
    void on_b_signin_clicked();

    void on_b_login_clicked();

private:
    Ui::Signin *ui;
    Handle handle;
};

#endif // SIGNIN_H
