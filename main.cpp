#include <QApplication>
#include "mainwindow.h"
#include "signin.h"
#include <QTextCodec.h>
#include <QDebug>
#include <QRegExp>
<<<<<<< HEAD
#include "chat.h"
=======
#include "tcpnet.h"
>>>>>>> 39d927180629cdf477aec4edc05b9fcf3447ae2a

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    QApplication a(argc, argv);
//    MainWindow w_main;
//    Signin d_sign;
//    d_sign.show();
//    if(d_sign.exec()==QDialog::Accepted)
//    {
//        w_main.show();
//        return a.exec();
//    }
//    else
//    {
//       return 0;
//    }
    Chat chat;
    chat.show();
    return a.exec();

}
