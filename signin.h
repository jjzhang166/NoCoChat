#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include <QHostAddress>
#include "handle.h"
#include <QMessageBox>
#include <QTextCodec>

namespace Ui {
class Signin;
}

class Signin : public QDialog
{
    Q_OBJECT

public:
    explicit Signin(QWidget *parent = 0);
    ~Signin();

private slots:
    void on_b_signin_clicked();

private:
    Ui::Signin *ui;
    Handle handle;
};

#endif // SIGNIN_H
