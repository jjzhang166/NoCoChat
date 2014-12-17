#include <QApplication>
#include "mainwindow.h"
#include <QTextCodec.h>
#include "addinfo.h"


int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    QApplication a(argc, argv);
    AddInfo w_main;
    w_main.show();
    return a.exec();


}
