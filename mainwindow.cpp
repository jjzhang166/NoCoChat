#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setMaximumSize(255, 544);
    setMinimumSize(255, 544);

    username = ui->user_name->text();
    userId = signin.getUserId();
    chat.setUserName(username);
    chat.setUserId(userId);
    addinfo.setUserName(username);
    addinfo.setUserId(userId);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getUserName()
{
    return username;
}

QString MainWindow::getUserId()
{
    return userId ;
}
