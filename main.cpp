#include <QApplication>
#include "mainwindow.h"
#include <QTextCodec.h>
#include "config.h"
#include "chat.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    QApplication a(argc, argv);
    Chat w_main;
    w_main.show();
    return a.exec();


}
