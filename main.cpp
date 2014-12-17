#include <QApplication>
#include "mainwindow.h"
#include <QTextCodec.h>


int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    QApplication a(argc, argv);
    MainWindow w_main;
    return a.exec();


}
